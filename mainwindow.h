#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class comm;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    comm *nrfInterface;

public slots:
    void setMessage(QString);

    void newCard(QString);
    void setCurSess(QString);
    void setCurClass(QString);
    void startNewClass(QString instructor, QString course, QString dateTime, int dur);
    void clockStudent(QString name, QString id, QByteArray pasp, QString status);
};
#endif // MAINWINDOW_H
