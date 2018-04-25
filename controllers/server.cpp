#include "server.h"

Server::Server(QObject *parent) : QObject(parent) {
    server = new QTcpServer(this);
    if(!server->listen(QHostAddress::Any, 8080)) std::cout << "Could not start server." << std::endl;
    else std::cout << "Server running on " << server->serverAddress().toString().toStdString() << " on port " << server->serverPort() << std::endl;
    connect(server, SIGNAL(newConnection()), this, SLOT(send_msg()));
}

void Server::send_msg() {
    std::cout << "Server was accessed." << std::endl;
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_10);
    out << "Hey there friendos";

    QTcpSocket *client_conn = server->nextPendingConnection();
    connect(client_conn, SIGNAL(disconnected()), client_conn, SLOT(deleteLater()));

    client_conn->write(block);
    client_conn->disconnectFromHost();
}
