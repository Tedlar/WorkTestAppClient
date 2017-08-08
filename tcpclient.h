#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QString>


class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = 0);
    void initialize();

signals:
    void receivedMessage(const QString&);

public slots:
    void connected();
    void disconnected();
    void bytesWritten(qint64 bytes);
    void readyRead();
    void onSendMessage(const QString&);

private:
    QTcpSocket *socket_;
    QString msg_;
};

#endif // TCPCLIENT_H
