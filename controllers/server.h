#ifndef SERVER_H
#define SERVER_H
#include <QtNetwork>
#include <QObject>
#include <iostream>
#include "../db/db_manager.h"
#include "../db/instructions_db.h"
#include "../users/instruction.h"
#include "clientthread.h"

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

signals:
    void group_received();

public slots:
    void incoming_request();
    void get_group_id();
    void conn_closed();
    void send_instruction();

private:
    QTcpServer *server = nullptr;
    QTcpSocket *sock = nullptr;
    DB_Manager *db = nullptr;
    int group_id;
    QString db_path;
};

#endif // SERVER_H
