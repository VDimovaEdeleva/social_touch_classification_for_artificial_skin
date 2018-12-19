#include <QtGui/QApplication>
#include <QTimer>
#include <QDebug>
#include <QFile>
#include <QDir>

#include <GL/freeglut.h>

#include <stdio.h>

#include "MainConsole.h"
#include "mainwindow.h"

#include <SkinCore/Core.h>
#include <SkinRecon/Recon.h>

#include <GL/freeglut.h>


#include "Tasks/LedFeedback.h"
#include "Tasks/Recon.h"

int main(int argc, char* argv[])
{
//    for(int i=0; i<argc; i++)
//    {
//        qDebug("arg[%d] = %s",i,argv[i]);
//    }

    qDebug("-----------------------------------------------------------");
    qDebug("                Skin Command Line App                      ");
    qDebug("-----------------------------------------------------------");   

    glutInit(&argc,argv);

    QApplication a(argc, argv);

    Skin::Core::registerMetaTypes();
    Skin::Reconstruction::Recon::registerMetaTypes();

    LedFeedback led;
    Recon recon;

    MainWindow w;



    // led
    QObject::connect(&w,SIGNAL(startLedFeedback(int)),
                     &led,SLOT(start(int)));

    QObject::connect(&w,SIGNAL(stopLedFeedback()),
                     &led,SLOT(stop()));

    QObject::connect(&w,SIGNAL(newDataBunch(QVector<Skin::Cell::Data>)),
                     &led,SLOT(newDataBunch(QVector<Skin::Cell::Data>)));

    QObject::connect(&led,SIGNAL(changeLedColor(Skin::Cell::LedColor)),
                     &w,SLOT(changeLedColor(Skin::Cell::LedColor)));

    QObject::connect(&led,SIGNAL(changeLedColor(Skin::Cell::LedColor,int)),
                     &w,SLOT(changeLedColor(Skin::Cell::LedColor,int)));

    // recon
    QObject::connect(&w,SIGNAL(sampledData(Skin::Reconstruction::AccDataSampler::Data)),
                     &recon,SLOT(sampledData(Skin::Reconstruction::AccDataSampler::Data)));

    QObject::connect(&recon,SIGNAL(newSkinOrganization(QVector<Skin::Cell::Organization>)),
                     &w,SLOT(newSkinOrganization(QVector<Skin::Cell::Organization>)));


    if(!w.autoConnect())
    {
        return -1;
    }

    QObject::connect(&w, SIGNAL(finished()), &a, SLOT(quit()));
    w.show();

    int ret = a.exec();
    qDebug() << "exit program";

    return ret;
}


