#include "appview.h"
#include "ui_appview.h"

AppView::AppView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppView)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

AppView::~AppView()
{
    delete ui;
}

void AppView::onPrintMessage(const QString& _text) {
    ui->stackedWidget->setCurrentIndex(0);
    ui->p1_le_2->setText(_text);
}

void AppView::onPrintDrawedNumbers(int a, int b, int c) {
    ui->stackedWidget->setCurrentIndex(1);
    ui->p2_le_1->setText(QString::number(a));
    ui->p2_le_2->setText(QString::number(b));
    ui->p2_le_3->setText(QString::number(c));
}
