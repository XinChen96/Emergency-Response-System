#include "client.h"

Client::Client(QObject *parent) : QTcpSocket(parent) {}

// TODO: implement custom ip addresses
void Client::request_new_msg(int group_id) {
    this->connectToHost("0.0.0.0", 8080);

    if (this->waitForConnected()) {
        std::cout << "Connected to server!" << std::endl;
    } else {
        std::cerr << "Could not connect: " << this->errorString().toStdString() << std::endl;
        return;
    }

    // Send group_id
    emit readyRead();
    QByteArray arr;
    QDataStream ds(&arr, QIODevice::WriteOnly);
    ds << group_id;
    this->write(arr);

    // Now wait for ready read from server
    QByteArray message;
    while(this->waitForReadyRead()) {
        message.append(this->readAll());
        std::cout << "received some data: " << message.toStdString() << std::endl;
    }

    std::cout << "here it is" << std::endl;
    // There's gotta be a better way to do this
    QString msg = QString::fromStdString(message.toStdString());
    msg.remove(QRegExp("[^a-zA-Z^!^.\\d\\s]"));
    new_message = msg;
}

QString Client::get_msg() {
    std::cout << new_message.toStdString() << std::endl;
    return new_message;
}
