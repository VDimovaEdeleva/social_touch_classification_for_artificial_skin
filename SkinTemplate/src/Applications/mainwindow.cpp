#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace Skin::Cell;

#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_numOfCells(0),
    m_quit(false),
    m_poseStarted(false),
    m_app(),
    m_viz(&m_app),
    m_recon(&m_app)
{
    m_cmdHandlers.append(&MainWindow::handleHelpCommand);

    // console reader
    QObject::connect(&m_console,SIGNAL(message(QString)),
                     this,SLOT(message(QString)));

    // recon
    QObject::connect(&m_recon,SIGNAL(newSkinConfig(Skin::Config)),
                     &m_viz,SLOT(newSkinConfig(Skin::Config)));

    ui->setupUi(this);

    setWindowTitle("Skin Tutorial");

    m_nameWidgetMap.insert("StartPose",ui->pbStartPose);
    m_nameWidgetMap.insert("NextPose",ui->pbNextPose);
    m_nameWidgetMap.insert("StopPose",ui->pbStopPose);
    m_nameWidgetMap.insert("LCurrrentPose",ui->lCurrentPose);
    m_nameWidgetMap.insert("LCDNCurrentPose",ui->lcdnCurrentPose);
    m_nameWidgetMap.insert("NumOfPoses",ui->sbNumOfPoses);

    m_widgets = m_nameWidgetMap.values().toVector();

    QList<QString> nwKeys = m_nameWidgetMap.keys();
    for(int i=0; i< nwKeys.size();i++)
    {
        QString k = nwKeys.at(i);
        QWidget* v = m_nameWidgetMap.value(k);
        m_wigetNameMap.insert(v,k);
        v->setEnabled(false);
    }

    m_nameButtonMap.insert("StartPose",ui->pbStartPose);
    m_nameButtonMap.insert("NextPose",ui->pbNextPose);
    m_nameButtonMap.insert("StopPose",ui->pbStopPose);

    QList<QString> nbKeys = m_nameButtonMap.keys();
    for(int i=0; i< nbKeys.size();i++)
    {
        QString k = nbKeys.at(i);
        QPushButton* v = m_nameButtonMap.value(k);
        m_buttonNameMap.insert(v,k);

        connect(v,SIGNAL(clicked()),
                this,SLOT(handleEvents()));
    }

    m_sbNumOfPoses = ui->sbNumOfPoses;
    m_lcdnCurrentPose = ui->lcdnCurrentPose;
    m_status = ui->statusbar;

    m_simpleViz = ui->wSimpleViz;

    // app
    connect(&m_app,SIGNAL(newNumberOfCells(int)),
            this,SLOT(newNumberOfCells(int)));

    connect(&m_app, SIGNAL(newDataBunch(QVector<Skin::Cell::Data>)),
            this, SIGNAL(newDataBunch(QVector<Skin::Cell::Data>)));

    // simple viz
    connect(&m_app,SIGNAL(ledColorChanged(Skin::Cell::LedColor)),
            m_simpleViz,SLOT(changeLedColor(Skin::Cell::LedColor)));

    connect(&m_app,SIGNAL(ledColorChanged(Skin::Cell::LedColor,int)),
            m_simpleViz,SLOT(changeLedColor(Skin::Cell::LedColor,int)));

    connect(&m_app, SIGNAL(newDataBunch(QVector<Skin::Cell::Data>)),
            m_simpleViz, SLOT(newDataBunch(QVector<Skin::Cell::Data>)));


    // data sampler
    connect(&m_app, SIGNAL(newDataBunch(QVector<Skin::Cell::Data>)),
            &m_sampler, SLOT(newDataBunch(QVector<Skin::Cell::Data>)));

    connect(&m_sampler,SIGNAL(started()),
            this, SLOT(dataSamplerStarted()));

    connect(&m_sampler,SIGNAL(stopped()),
            this, SLOT(dataSamplerStopped()));

    connect(&m_sampler,SIGNAL(poseFinished()),
            this, SLOT(dataSamplerPoseFinished()));

    connect(&m_sampler,SIGNAL(finished()),
            this, SLOT(dataSamplerFinished()));

    connect(&m_sampler,SIGNAL(samplingFailed()),
            this, SLOT(dataSamplingFailed()));

    connect(&m_sampler,SIGNAL(sampledData(Skin::Reconstruction::AccDataSampler::Data)),
            this, SIGNAL(sampledData(Skin::Reconstruction::AccDataSampler::Data)));

    qDebug("Estabilished connections");


    // init widgets
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "NumOfPoses"
            << "StartPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    qDebug("Exit MainWindow");
}

bool MainWindow::autoConnect(const AppType& t, const IntfNode& n)
{
    return m_app.autoConnect(t,n);
}

bool MainWindow::handleHelpCommand(const QString& s)
{
    if(s == "h" || s == "help")
    {
        QString help;

        help.append("=================================================================\n");
        help.append("The programm supports the following commands [cmd]:\n");
        help.append("=================================================================\n");

        help.append("[help], [h]                     help\n");
        help.append("[quit], [q], [exit]             exit program\n");

        help.append(m_app.consoleCmdDescription());
        help.append(m_viz.consoleCmdDescription());
        help.append(m_recon.consoleCmdDescription());

        help.append("=================================================================\n");
        help.append("\n\n");


        fprintf(stdout,"%s",help.toAscii().data());
        fflush(stdout);

        return true;
    }

    return false;
}

void MainWindow::closeEvent(QCloseEvent* e)
{
    e->ignore();
    quit();
}

void MainWindow::startPoseClicked()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }
    m_status->showMessage("Start collecting samples for poses...");

    QMetaObject::invokeMethod(&m_sampler,"start",
                              Q_ARG(int,m_numOfCells),
                              Q_ARG(int,m_sbNumOfPoses->value()),
                              Q_ARG(int,100));
}

void MainWindow::nextPoseClicked()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "LCurrentPose"
            << "LCDCurrentPose"
            << "StopPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }

    m_currentPose++;
    m_lcdnCurrentPose->display(m_currentPose);

    m_status->showMessage("Start collecting samples for next pose...");
    QMetaObject::invokeMethod(&m_sampler,"nextPose");
}

void MainWindow::stopPoseClicked()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    m_status->showMessage("Stop collecting samples for poses...");
    QMetaObject::invokeMethod(&m_sampler,"stop");
}


void MainWindow::message(QString s)
{
    if(m_recon.started() && m_recon.nextPose())
    {
        QMetaObject::invokeMethod(&m_recon,"acquireNextPose");
        return;
    }

    if(m_recon.started() && !m_recon.nextPose())
    {
        return;
    }


    if(s == "")
    {
        return;
    }

    if(s == "q" || s == "quit" || s == "exit")
    {
        quit();
        return;
    }

    if(m_app.handleConsoleCmd(s))
    {
       return;
    }

    if(m_viz.handleConsoleCmd(s))
    {
        return;
    }

    if(m_recon.handleConsoleCmd(s))
    {
        return;
    }

    // call command handlers
    for(int i=0; i<m_cmdHandlers.size(); i++)
    {
        if((this->*m_cmdHandlers.at(i))(s))
        {
            return;
        }
    }

    qDebug("invalid cmd");
}


void MainWindow::handleEvents()
{
    QPushButton* pb = qobject_cast<QPushButton*>(sender());
    if(pb != 0)
    {
        QString n = m_buttonNameMap.value(pb,"");
        if(n.isEmpty())
        {
            return;
        }

        if(n == "StartPose")
        {
            startPoseClicked();
            return;
        }

        if(n == "NextPose")
        {
            nextPoseClicked();
            return;
        }

        if(n == "StopPose")
        {
            stopPoseClicked();
            return;
        }
    }
}

void MainWindow::dataSamplerStarted()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "LCurrentPose"
            << "LCDCurrentPose"
            << "StopPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }

    m_poseStarted = true;
    m_currentPose = 1;

    m_status->showMessage("Data sampler started.");
}

void MainWindow::dataSamplerStopped()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "NumOfPoses"
            << "StartPose"
            << "NextPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }

    m_poseStarted = false;
    m_status->showMessage("Data sampler stopped.");

    if(m_quit)
    {
        quit();
    }
}

void MainWindow::dataSamplerPoseFinished()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(true);
    }

    QVector<QString> names = QVector<QString>()
            << "NumOfPoses"
            << "StartPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(false);
        }
    }
    m_status->showMessage("Data sampler pose finished.");
}

void MainWindow::dataSamplerFinished()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "NumOfPoses"
            << "StartPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }

    m_poseStarted = false;
    m_status->showMessage("Data sampler finished.");
}

void MainWindow::dataSamplingFailed()
{
    for(int i=0; i<m_widgets.size(); i++)
    {
        m_widgets[i]->setEnabled(false);
    }

    QVector<QString> names = QVector<QString>()
            << "NumOfPoses"
            << "StartPose";

    for(int i=0; i<names.size(); i++)
    {
        QWidget* w= m_nameWidgetMap.value(names.at(i),0);
        if(w != 0)
        {
            w->setEnabled(true);
        }
    }

    m_poseStarted = false;
    m_status->showMessage("Data sampling failed.");
}


void MainWindow::newNumberOfCells(int num)
{
    m_numOfCells = num;
    emit startLedFeedback(num);
}

void MainWindow::quit()
{
    m_quit = true;

    if(m_poseStarted)
    {
        QMetaObject::invokeMethod(&m_sampler,"stop");
        return;
    }

    if(m_app.isConnected())
    {
        connect(&m_app,SIGNAL(disconnected()),
                this,SLOT(quit()));

        emit stopLedFeedback();
        QMetaObject::invokeMethod(&m_app,"disconnect");
        return;
    }

    if(!m_app.isConnected())
    {
        close();
        emit finished();
    }
}

void MainWindow::changeLedColor(LedColor color,int id)
{
    QMetaObject::invokeMethod(&m_app,"changeLedColor",
                              Q_ARG(Skin::Cell::LedColor,color),
                              Q_ARG(int,id));
}

void MainWindow::newSkinOrganization(QVector<Skin::Cell::Organization> org)
{
    QMetaObject::invokeMethod(m_simpleViz,"newSkinOrganization",
                              Q_ARG(QVector<Skin::Cell::Organization>,org));
}

