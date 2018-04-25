#include "clientthread.h"

ClientThread::ClientThread(QObject *parent) : QThread(parent), quit(false) {}

ClientThread::~ClientThread() {
    mutex.lock();
    quit = true;
    cond.wakeOne();
    mutex.unlock();
    wait();
}

void ClientThread::request_new_msg(QString host_name, int port) {
    QMutexLocker locker(&mutex);
    QHostAddress addr(host_name);
    this->host_name = addr;
    this->port = port;
    if (!isRunning()) start();
    else cond.wakeOne();
}

void ClientThread::run() {
    // Lock member data
    mutex.lock();
    QHostAddress server_name = host_name;
    int server_port = port;
    mutex.unlock();

    while (!quit) {
        QTcpSocket socket;
        socket.connectToHost("0.0.0.0", 8080);

        if (socket.waitForConnected()) {
            std::cout << "Connected to server!" << std::endl;
        } else {
            std::cerr << "Could not connect: " << socket.errorString().toStdString() << std::endl;
            return;
        }

        QByteArray message;
        while(socket.waitForReadyRead()) {
            message.append(socket.readAll());
        }

        // There's gotta be a better way to do this
        QString msg = QString::fromStdString(message.toStdString());

        mutex.lock();
        emit new_msg(msg); // Call new_msg signal
        cond.wait(&mutex);
        server_name = host_name;
        server_port = port;
        mutex.unlock();
    }
}
