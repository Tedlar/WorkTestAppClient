#ifndef APPVIEW_H
#define APPVIEW_H

#include <QMainWindow>
#include <QString>


namespace Ui {
class AppView;
}

class AppView : public QMainWindow
{
    Q_OBJECT

public:
    explicit AppView(QWidget *parent = 0);
    ~AppView();

private:
    Ui::AppView *ui;

public slots:
    void onPrintMessage(const QString&);
    void onPrintDrawedNumbers(int, int, int);
};

#endif // APPVIEW_H
