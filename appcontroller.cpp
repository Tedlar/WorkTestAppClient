#include "appcontroller.h"
#include "tcpclient.h"

#include <QApplication>
#include <QStringList>
#include <QRegExp>
#include <QDebug>

#include <random>


AppController::AppController(QObject *parent) : QObject(parent) {
    client_ = new TcpClient(parent);
    connect(client_, SIGNAL(receivedMessage(QString)), this, SLOT(onMessageReceived(QString)));
    connect(this, SIGNAL(sendMessage(const QString&)), client_, SLOT(onSendMessage(const QString&)));
    client_->initialize();
}

void AppController::onMessageReceived(const QString& _text) {
    parseMessage(_text);
}

void AppController::parseMessage(const QString& _text) {
    if (checkMessageClose(_text)) {
        qDebug() << "Close app";
        emit printMessage(_text);
        qApp->quit();
    } else if (checkMessageDraw(_text)) {
        drawNumbers();
        emit printDrawedNumbers(drawed_[0], drawed_[1], drawed_[2]);
    } else
        emit printMessage(_text);
}

bool AppController::checkMessageClose(const QString& _text) {
    if (_text == "zamknij") return true;
    return false;
}

bool AppController::checkMessageDraw(const QString& _text) {
    QRegExp exp("\\ ");
    QStringList tokens = _text.split(exp);
    if (tokens.size() != 4) return false;
    if (tokens[0] != "losuj") return false;
    bool result;
    numbers_[0] = tokens.at(1).toInt(&result);
    if (!result) return false;
    numbers_[1] = tokens.at(2).toInt(&result);
    if (!result) return false;
    numbers_[2] = tokens.at(3).toInt(&result);
    if (!result) return false;
    return true;
}

void AppController::drawNumbers() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0,2);

    drawed_[0] = numbers_[dis(gen)];
    drawed_[1] = numbers_[dis(gen)];
    drawed_[2] = numbers_[dis(gen)];

    if (drawed_[0] == drawed_ [1] && drawed_[1] == drawed_ [2]) {
        emit sendMessage("wygrana");
    }
}
