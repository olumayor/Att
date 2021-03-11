/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QFrame *header;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QFrame *body;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QLabel *CourseCode;
    QLabel *label_26;
    QLabel *label_21;
    QLabel *label_20;
    QLabel *label_14;
    QLabel *label_23;
    QLabel *Instructor;
    QLabel *CourseTitle;
    QLabel *label_16;
    QLabel *ClassNumber;
    QLabel *label_22;
    QLabel *label_18;
    QLabel *StartT;
    QLabel *EndT;
    QLabel *TimerT;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *IdPixmap;
    QLabel *label_11;
    QLabel *IdName;
    QLabel *label_12;
    QLabel *IdId;
    QLabel *label_13;
    QLabel *label_10;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QTextEdit *MessageBox;
    QFrame *footer;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QFrame *bb;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(648, 1024);
        MainWindow->setMinimumSize(QSize(600, 1024));
        MainWindow->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0.568, x2:1, y2:0.642, stop:0 rgba(15, 2, 36, 111),\n"
"        stop:0.494318 rgba(36, 2, 19, 111), stop:1 rgba(24, 2, 20, 255))\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setStyleSheet(QLatin1String("QFrame#header {\n"
"background: #23FFdb7f;  border: 1px solid transparent;  border-radius: 12px;  color: #E1FFFFFF; \n"
"\n"
"}\n"
"\n"
"QFrame#footer{ border: none }\n"
"\n"
"QFrame#body{\n"
"background: transparent;  border: none;  color: #E1FFFFFF; \n"
"\n"
"}\n"
"\n"
"QLabel{ color: #FFFFFF; font-family: 'Roboto'; }\n"
"\n"
"QGroupBox\n"
"{\n"
"    color: #FFFFFF;\n"
"    font: 11pt 'Roboto';\n"
"    border: 2px solid #51FFFFFF;  border-radius: 6px; \n"
"    margin-top: 8px;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"\n"
"QGroupBox::title\n"
"{\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"    left: 7px;\n"
"    padding: 0px 5px 0px 5px;\n"
"}"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 580));
        frame->setMaximumSize(QSize(16777215, 580));
        frame->setCursor(QCursor(Qt::BlankCursor));
        frame->setStyleSheet(QLatin1String("QFrame#frame{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 rgba(50, 61, 27, 255), stop:1 rgba(78, 154, 6, 255));\n"
"border: 2px solid qlineargradient(spread:pad, x1:0.0149254, y1:0.505727, x2:1, y2:0.364, stop:0 rgba(252, 233, 79, 255), stop:1 rgba(252, 233, 79, 157));\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        header = new QFrame(frame);
        header->setObjectName(QStringLiteral("header"));
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        header->setMinimumSize(QSize(0, 90));
        header->setMaximumSize(QSize(16777215, 90));
        header->setFrameShape(QFrame::StyledPanel);
        header->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(header);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20, -1, 20, -1);
        label_2 = new QLabel(header);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QStringLiteral("color: rgb(252, 233, 79);"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label = new QLabel(header);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(60, 50));
        label->setMaximumSize(QSize(60, 50));
        label->setPixmap(QPixmap(QString::fromUtf8(":/logo2.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 2, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_3 = new QLabel(header);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_6 = new QLabel(header);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label_6, 1, 4, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        label_4 = new QLabel(header);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(label_4, 0, 4, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 1, 3, 1, 1);


        verticalLayout_2->addWidget(header);

        body = new QFrame(frame);
        body->setObjectName(QStringLiteral("body"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(body->sizePolicy().hasHeightForWidth());
        body->setSizePolicy(sizePolicy1);
        body->setFrameShape(QFrame::StyledPanel);
        body->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(body);
        gridLayout_4->setSpacing(20);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 12, 0, -1);
        groupBox_2 = new QGroupBox(body);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(16);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(12, 12, 12, 12);
        CourseCode = new QLabel(groupBox_2);
        CourseCode->setObjectName(QStringLiteral("CourseCode"));

        gridLayout_5->addWidget(CourseCode, 2, 1, 1, 2);

        label_26 = new QLabel(groupBox_2);
        label_26->setObjectName(QStringLiteral("label_26"));

        gridLayout_5->addWidget(label_26, 3, 0, 1, 1);

        label_21 = new QLabel(groupBox_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_21, 5, 0, 1, 1, Qt::AlignHCenter);

        label_20 = new QLabel(groupBox_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_5->addWidget(label_20, 4, 0, 1, 3);

        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        label_23 = new QLabel(groupBox_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_23, 5, 2, 1, 1, Qt::AlignHCenter);

        Instructor = new QLabel(groupBox_2);
        Instructor->setObjectName(QStringLiteral("Instructor"));

        gridLayout_5->addWidget(Instructor, 3, 1, 1, 2);

        CourseTitle = new QLabel(groupBox_2);
        CourseTitle->setObjectName(QStringLiteral("CourseTitle"));
        CourseTitle->setWordWrap(true);

        gridLayout_5->addWidget(CourseTitle, 1, 1, 1, 2);

        label_16 = new QLabel(groupBox_2);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_5->addWidget(label_16, 1, 0, 1, 1);

        ClassNumber = new QLabel(groupBox_2);
        ClassNumber->setObjectName(QStringLiteral("ClassNumber"));

        gridLayout_5->addWidget(ClassNumber, 0, 1, 1, 2);

        label_22 = new QLabel(groupBox_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_22, 5, 1, 1, 1, Qt::AlignHCenter);

        label_18 = new QLabel(groupBox_2);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_5->addWidget(label_18, 2, 0, 1, 1);

        StartT = new QLabel(groupBox_2);
        StartT->setObjectName(QStringLiteral("StartT"));
        StartT->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(StartT, 6, 0, 1, 1, Qt::AlignHCenter);

        EndT = new QLabel(groupBox_2);
        EndT->setObjectName(QStringLiteral("EndT"));
        EndT->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(EndT, 6, 1, 1, 1, Qt::AlignHCenter);

        TimerT = new QLabel(groupBox_2);
        TimerT->setObjectName(QStringLiteral("TimerT"));
        TimerT->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(TimerT, 6, 2, 1, 1, Qt::AlignHCenter);


        gridLayout_4->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox = new QGroupBox(body);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(280, 0));
        groupBox->setAlignment(Qt::AlignCenter);
        groupBox->setFlat(false);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(12);
        gridLayout_3->setVerticalSpacing(18);
        gridLayout_3->setContentsMargins(12, 12, 12, 12);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 4, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 4, 1, 1, 1);

        IdPixmap = new QLabel(groupBox);
        IdPixmap->setObjectName(QStringLiteral("IdPixmap"));
        sizePolicy1.setHeightForWidth(IdPixmap->sizePolicy().hasHeightForWidth());
        IdPixmap->setSizePolicy(sizePolicy1);
        IdPixmap->setMinimumSize(QSize(0, 128));
        IdPixmap->setMaximumSize(QSize(16777215, 128));
        IdPixmap->setStyleSheet(QStringLiteral("QLabel{background: grey; border: 1px solid transparent; border-radius: 6px;}"));

        gridLayout_3->addWidget(IdPixmap, 0, 0, 1, 4);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        IdName = new QLabel(groupBox);
        IdName->setObjectName(QStringLiteral("IdName"));

        gridLayout_3->addWidget(IdName, 1, 1, 1, 3);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 2, 0, 1, 1);

        IdId = new QLabel(groupBox);
        IdId->setObjectName(QStringLiteral("IdId"));

        gridLayout_3->addWidget(IdId, 2, 1, 1, 3);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 3, 1, 1, 3);


        gridLayout_4->addWidget(groupBox, 0, 1, 2, 1);

        groupBox_3 = new QGroupBox(body);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        MessageBox = new QTextEdit(groupBox_3);
        MessageBox->setObjectName(QStringLiteral("MessageBox"));
        MessageBox->setStyleSheet(QStringLiteral("QTextEdit{background: transparent; color: blue;}"));

        gridLayout_6->addWidget(MessageBox, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 1);


        verticalLayout_2->addWidget(body);

        footer = new QFrame(frame);
        footer->setObjectName(QStringLiteral("footer"));
        footer->setMinimumSize(QSize(0, 35));
        footer->setMaximumSize(QSize(16777215, 35));
        footer->setFrameShape(QFrame::StyledPanel);
        footer->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(footer);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_5 = new QLabel(footer);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setStyleSheet(QStringLiteral("font-size: 9pt;"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);


        verticalLayout_2->addWidget(footer);


        verticalLayout->addWidget(frame);

        bb = new QFrame(centralwidget);
        bb->setObjectName(QStringLiteral("bb"));
        sizePolicy1.setHeightForWidth(bb->sizePolicy().hasHeightForWidth());
        bb->setSizePolicy(sizePolicy1);
        bb->setMinimumSize(QSize(0, 444));
        bb->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        bb->setFrameShape(QFrame::StyledPanel);
        bb->setFrameShadow(QFrame::Raised);

        verticalLayout->addWidget(bb);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "<h1> Osun State University </h1>", nullptr));
        label->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "<h3> Attendance Management Device </h3>", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "11:44 AM", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "27/06/2020", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Class Information", nullptr));
        CourseCode->setText(QString());
        label_26->setText(QApplication::translate("MainWindow", "Instructor:", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "Start", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "<hr>", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "Class number:", nullptr));
        label_23->setText(QApplication::translate("MainWindow", "Timer", nullptr));
        Instructor->setText(QString());
        CourseTitle->setText(QString());
        label_16->setText(QApplication::translate("MainWindow", "Course title:", nullptr));
        ClassNumber->setText(QString());
        label_22->setText(QApplication::translate("MainWindow", "End", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Course code:", nullptr));
        StartT->setText(QApplication::translate("MainWindow", "00:00", nullptr));
        EndT->setText(QApplication::translate("MainWindow", "00:00", nullptr));
        TimerT->setText(QApplication::translate("MainWindow", "00:00", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "ID Information", nullptr));
        IdPixmap->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Name:", nullptr));
        IdName->setText(QString());
        label_12->setText(QApplication::translate("MainWindow", "ID:", nullptr));
        IdId->setText(QString());
        label_13->setText(QApplication::translate("MainWindow", "Level:", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "IdLevel", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Notice Board", nullptr));
        MessageBox->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'FreeSerif Italic'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Osun State University Osogbo @2020", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
