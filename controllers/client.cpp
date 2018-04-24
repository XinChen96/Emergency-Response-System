#include "client.h"
#include <iostream>

Client::Client(QObject *parent) : QObject(parent) {
    socket = new QTcpSocket(this);
    in.setDevice(socket);
    in.setVersion(QDataStream::Qt_4_0);

    connect(socket, &QIODevice::readyRead, this, &Client::read_message);
    connect(socket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error), this, &Client::display_error);
    request_new_message();
}

void Client::request_new_message() {
    std::cout << "Initializing request" << std::endl;
    socket->abort();
    socket->connectToHost(QHostAddress::LocalHost, 8080);
}

void Client::read_message() {
    std::cout << "Reading messages" << std::endl;

    in.startTransaction();

    QString new_message;
    in >> new_message;

    if(!in.commitTransaction()) return;

    if(new_message == current_message) {
        QTimer::singleShot(0, this, &Client::request_new_message);
        return;
    }
    current_message = new_message;
    std::cout << current_message.toStdString() << std::endl;
}

void Client::display_error(QAbstractSocket::SocketError socketError) {
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        std::cerr << "Host was not found." << std::endl;
        break;
    case QAbstractSocket::ConnectionRefusedError:
        std::cerr << "Connection was refused." << std::endl;
        break;
    default:
        std::cerr << "Something else went wrong" << std::endl;
    }
}
