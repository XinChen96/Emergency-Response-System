#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {}

// TODO: implement custom ip addresses
void Client::request_new_msg() {
    mutex.lock(); // Lock the thread until the transaction is complete
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
    new_message = msg;
    mutex.unlock(); // Done reading data
}

QString Client::get_msg() {
    std::cout << new_message.toStdString() << std::endl;
    return new_message;
}
