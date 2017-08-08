#ifndef APPMAIN_H
#define APPMAIN_H

#include <QObject>


class AppView;
class AppController;

class AppMain : public QObject
{
    Q_OBJECT
public:
    explicit AppMain(QObject *parent = nullptr);

private:
    AppView* appView_;
    AppController* appController_;

private:
    void createObjects();
    void createConnections();

signals:

public slots:
};

#endif // APPMAIN_H
