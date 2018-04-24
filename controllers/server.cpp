#include "server.h"
#include <iostream>

Server::Server(QObject *parent) : QObject(parent) {
    server = new QTcpServer(this);
    if(server->listen(QHostAddress::Any, 8080)) std::cout << "Server successfully started!" << std::endl;

    // Connect new connection event to message retrieval event
    connect(server, SIGNAL(newConnection()), this, SLOT(print_something()));
}

void Server::print_something() {
    std::cout << "called print something" << std::endl;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);

    out << QString("Hello there friendo");

    QTcpSocket *client_connection = server->nextPendingConnection();
    connect(client_connection, &QAbstractSocket::disconnected, client_connection, &QObject::deleteLater);

    client_connection->write(block);
    client_connection->disconnectFromHost();
}
