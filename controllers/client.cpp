#include "client.h"

Client::Client(QObject *parent) : QObject(parent) {
    connect(&ct, SIGNAL(new_msg(QString)), this, SLOT(change_msg(QString)));
}

void Client::request_new_msg() {
    qint16 port(8080);
    ct.request_new_msg("0.0.0.0", port);
}

void Client::change_msg(const QString& new_msg) {
    msg = new_msg;
}
