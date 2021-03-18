#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include "comm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
   // QTimer::singleShot(0, this, SLOT(showFullScreen()));

    nrfInterface = new comm();
    connect(nrfInterface, SIGNAL(setMessage(QString)), this, SLOT(setMessage(QString)));
    //nrfInterface->requestInterruption();

    connect(nrfInterface, SIGNAL(newCard(QString)), this, SLOT(newCard(QString)));
    connect(nrfInterface, SIGNAL(setCurClass(QString)), this, SLOT(setCurClass(QString)));
    connect(nrfInterface, SIGNAL(setCurSess(QString)), this, SLOT(setCurSess(QString)));
    connect(nrfInterface, SIGNAL(startNewClass(QString,QString,QString,int)), this, SLOT(startNewClass(QString,QString,QString,int)));
    connect(nrfInterface, SIGNAL(clockStudent(QString,QString,QByteArray,QString)), this, SLOT(clockStudent(QString,QString,QByteArray,QString)));

    nrfInterface->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow :: setMessage(QString str)
{
    ui->MessageBox->setText(str);
}

//--------------------------------------------------------------------------------------------------
void MainWindow :: newCard(QString str)
{
    ui->IdId->setText(str);
}

void MainWindow :: setCurClass(QString str)
{
    ui->CourseCode->setText(str);
}

void MainWindow :: setCurSess(QString str)
{
}

void MainWindow :: startNewClass(QString instructor, QString course, QString dateTime, int dur)
{
    ui->Instructor->setText(instructor);
    ui->CourseTitle->setText(course);
    QDateTime tt = QDateTime::fromString(dateTime);
    ui->currDateLab->setText(tt.date().toString());
    ui->currTimeLab->setText(tt.time().toString());
    //ui->cDurLab->setText(QString::number(dur));
    setMessage("Class in progress");
}

void MainWindow :: clockStudent(QString name, QString id, QByteArray pasp, QString status)
{
    ui->IdName->setText(name);
    ui->IdId->setText(id);
    ui->IdStatus->setText(status);

    QPixmap pix(100, 100);
    pix.loadFromData(pasp, "PNG");
    ui->IdPixmap->setPixmap(pix);
}

