#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
    if(!this->listen(QHostAddress::Any, 8080)) std::cout << "Could not start server." << std::endl;
    else std::cout << "Server running on " << this->serverAddress().toString().toStdString() << " on port " << this->serverPort() << std::endl;
    connect(this, SIGNAL(newConnection()), this, SLOT(incoming_request()));
    connect(this, SIGNAL(group_received()), SLOT(send_instruction()));

    db_path = "/mnt/cs205/db.sqlite";
}

void Server::incoming_request() {
    sock = this->nextPendingConnection();

    if (sock->waitForConnected()) {
        std::cout << "Connected to client!" << std::endl;
    } else {
        std::cerr << "Could not connect: " << this->errorString().toStdString() << std::endl;
        return;
    }
    connect(sock, SIGNAL(readyRead()), SLOT(get_group_id()));
    connect(sock, SIGNAL(disconnected()), SLOT(conn_closed()));
}

void Server::get_group_id() {
    QByteArray message;

    message.append(sock->readAll());

    QDataStream str(&message, QIODevice::ReadOnly);
    int group_id;
    str >> group_id;
    std::cout << "group id of incoming request: " << group_id << std::endl;
    emit group_received();
}

void Server::send_instruction() {
    db = new Instructions_DB(db_path);
    std::cout << "group_id: " << group_id << std::endl;
    Instruction *i = ((Instructions_DB*)db)->get_instruction(group_id);
    std::cout << i->instruction.toStdString() << "blablabla" << std::endl;
    QByteArray arr;
    QDataStream str(&arr, QIODevice::WriteOnly);
    str << i->instruction;

    sock->write(arr);
    sock->close();
    delete db;
}

void Server::conn_closed() {
    std::cout << "Connection closed!" << std::endl;
}
