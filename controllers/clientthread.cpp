#include "clientthread.h"

ClientThread::ClientThread(QTcpSocket *sock, QObject *parent) : QTcpSocket(parent) {
    db_path = "/mnt/cs205/db.sqlite";
    setSocketDescriptor(sock->socketDescriptor());
    connect(this, SIGNAL(connected()), this, SLOT(connected()));
    connect(this, SIGNAL(readyRead()), this, SLOT(receive_group()));
    connect(this, SIGNAL(group_received()), this, SLOT(send_msg()));
}

void ClientThread::connected() {
    if (this->waitForConnected()) {
        std::cout << "Connected to client!" << std::endl;
    } else {
        std::cerr << "Could not connect: " << this->errorString().toStdString() << std::endl;
        return;
    }
}

void ClientThread::receive_group() {
    QByteArray message;
    while(this->waitForReadyRead()) {
        std::cout << "from socket: " << this->readAll().toStdString() << std::endl;
        message.append(this->readAll());
    }

    QDataStream str(&message, QIODevice::ReadOnly);
    int group_id;
    str >> group_id;
    std::cout << "group id of incoming request: " << group_id << std::endl;
    emit group_received();
}

void ClientThread::send_msg() {
    db = new Instructions_DB(db_path);
    Instruction *i = ((Instructions_DB*)db)->get_instruction(group_id);
    QByteArray arr;
    QDataStream str(&arr, QIODevice::WriteOnly);
    str << i->instruction;

    this->write(arr);
    this->close();
}
