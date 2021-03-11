#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "comm.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setWindowFlags(Qt::FramelessWindowHint);
    QTimer::singleShot(0, this, SLOT(showFullScreen()));

    nrfInterface = new comm();
    connect(nrfInterface, SIGNAL(setMessage(QString)), this, SLOT(setMessage(QString)));
    //nrfInterface->requestInterruption();
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

