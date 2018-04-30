#include "server.h"

Server::Server(QObject *parent) : QTcpServer(parent) {
    if(!this->listen(QHostAddress::Any, 8080)) std::cout << "Could not start server." << std::endl;
    else std::cout << "Server running on " << this->serverAddress().toString().toStdString() << " on port " << this->serverPort() << std::endl;
    connect(this, SIGNAL(newConnection()), this, SLOT(incoming_request()));
    connect(this, SIGNAL(group_received(int)), SLOT(send_instruction(int)));

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
    //QByteArray message;

    QDataStream in(sock);
    in.startTransaction();
    int group_id;
    if(in.commitTransaction()) {
        in >> group_id;

        std::cout << "got this from the socket: " << group_id << std::endl;
    } else {
        std::cerr << "failed to commit transaction." << std::endl;
    }
    emit group_received(group_id);
}

void Server::send_instruction(int group_id) {
    db = new Instructions_DB(db_path);
    Instruction *i = ((Instructions_DB*)db)->get_instruction(group_id);
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
