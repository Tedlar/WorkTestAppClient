#include "tcpclient.h"
#include <QHostAddress>


TcpClient::TcpClient(QObject *parent) : QObject(parent) {

}

void TcpClient::initialize() {
    socket_ = new QTcpSocket(this);
    connect(socket_, SIGNAL(connected()), this, SLOT(connected()));
    connect(socket_, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(socket_, SIGNAL(readyRead()), this, SLOT(readyRead()));
    connect(socket_, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));

    qDebug() << "Connecting,..";

    socket_->connectToHost(QHostAddress::LocalHost, 1234);
}

void TcpClient::connected() {
    qDebug() << "Connected!";
}

void TcpClient::disconnected() {
    qDebug() << "Disconnected!";
}

void TcpClient::bytesWritten(qint64 bytes) {
    qDebug() << "We wrote: " << bytes;
}

void TcpClient::readyRead() {
    qDebug() << "Reading...";
    msg_ = QString::fromUtf8(socket_->readAll());
    emit receivedMessage(msg_);
}

void TcpClient::onSendMessage(const QString& _text) {
    qDebug() << "Writing...";
    socket_->write(_text.toUtf8());
}
