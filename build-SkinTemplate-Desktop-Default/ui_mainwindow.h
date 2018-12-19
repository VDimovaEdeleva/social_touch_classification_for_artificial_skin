/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "SkinViz/Version2/SimpleViz/SimpleViz.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_4;
    QSpinBox *sbNumOfPoses;
    QPushButton *pbStartPose;
    QPushButton *pbNextPose;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lCurrentPose;
    QLCDNumber *lcdnCurrentPose;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbStopPose;
    QSpacerItem *verticalSpacer_2;
    Skin::Visualization::Version2::SimpleViz *wSimpleViz;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(818, 740);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sbNumOfPoses = new QSpinBox(centralwidget);
        sbNumOfPoses->setObjectName(QString::fromUtf8("sbNumOfPoses"));
        sbNumOfPoses->setMinimumSize(QSize(50, 0));
        sbNumOfPoses->setMinimum(1);
        sbNumOfPoses->setMaximum(6);

        horizontalLayout_4->addWidget(sbNumOfPoses);

        pbStartPose = new QPushButton(centralwidget);
        pbStartPose->setObjectName(QString::fromUtf8("pbStartPose"));

        horizontalLayout_4->addWidget(pbStartPose);

        pbNextPose = new QPushButton(centralwidget);
        pbNextPose->setObjectName(QString::fromUtf8("pbNextPose"));

        horizontalLayout_4->addWidget(pbNextPose);


        horizontalLayout_9->addLayout(horizontalLayout_4);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lCurrentPose = new QLabel(centralwidget);
        lCurrentPose->setObjectName(QString::fromUtf8("lCurrentPose"));

        horizontalLayout_5->addWidget(lCurrentPose);

        lcdnCurrentPose = new QLCDNumber(centralwidget);
        lcdnCurrentPose->setObjectName(QString::fromUtf8("lcdnCurrentPose"));
        lcdnCurrentPose->setMaximumSize(QSize(16777215, 30));
        lcdnCurrentPose->setDigitCount(1);
        lcdnCurrentPose->setProperty("intValue", QVariant(1));

        horizontalLayout_5->addWidget(lcdnCurrentPose);


        horizontalLayout_9->addLayout(horizontalLayout_5);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_5);

        pbStopPose = new QPushButton(centralwidget);
        pbStopPose->setObjectName(QString::fromUtf8("pbStopPose"));

        horizontalLayout_9->addWidget(pbStopPose);


        verticalLayout->addLayout(horizontalLayout_9);

        verticalSpacer_2 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        wSimpleViz = new Skin::Visualization::Version2::SimpleViz(centralwidget);
        wSimpleViz->setObjectName(QString::fromUtf8("wSimpleViz"));
        wSimpleViz->setMinimumSize(QSize(800, 600));

        verticalLayout->addWidget(wSimpleViz);

        verticalSpacer_3 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 818, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Skin Tutorial", 0, QApplication::UnicodeUTF8));
        pbStartPose->setText(QApplication::translate("MainWindow", "Start Pose", 0, QApplication::UnicodeUTF8));
        pbNextPose->setText(QApplication::translate("MainWindow", "Next Pose", 0, QApplication::UnicodeUTF8));
        lCurrentPose->setText(QApplication::translate("MainWindow", "Current Pose:", 0, QApplication::UnicodeUTF8));
        pbStopPose->setText(QApplication::translate("MainWindow", "Stop Pose", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
