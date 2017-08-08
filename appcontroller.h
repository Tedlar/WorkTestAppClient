#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>


class TcpClient;

class AppController : public QObject
{
    Q_OBJECT
public:
    explicit AppController(QObject *parent = nullptr);

signals:
    void printMessage(const QString&);
    void printDrawedNumbers(int, int, int);
    void sendMessage(const QString&);

public slots:
    void onMessageReceived(const QString& _text);

private:
    void parseMessage(const QString& _text);
    bool checkMessageClose(const QString& _text);
    bool checkMessageDraw(const QString& _text);
    void drawNumbers();

private:
    TcpClient* client_;
    int numbers_[3];
    int drawed_[3];
};

#endif // APPCONTROLLER_H
