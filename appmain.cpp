#include "appmain.h"
#include "appcontroller.h"
#include "appview.h"


AppMain::AppMain(QObject *parent) : QObject(parent) {
    createObjects();
    createConnections();
    appView_->show();
}

void AppMain::createObjects() {
    appView_ = new AppView();
    appController_ = new AppController(appView_);
}

void AppMain::createConnections() {
    connect(appController_, SIGNAL(printMessage(QString)), appView_, SLOT(onPrintMessage(QString)));
    connect(appController_, SIGNAL(printDrawedNumbers(int,int,int)), appView_, SLOT(onPrintDrawedNumbers(int,int,int)));
}
