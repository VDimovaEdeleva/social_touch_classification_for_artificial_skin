#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QPushButton>
#include <QWidget>

#include <SkinCore/Implementation/Packets/Version2/Packets.h>
#include <SkinCore/Cell/Organization.h>

#include <SkinManagers/Application/Standard/Application.h>
#include <SkinManagers/Viz/Viz.h>
#include <SkinManagers/Recon/Recon.h>

#include <SkinViz/Version2/SimpleViz/SimpleViz.h>

#include <SkinRecon/AccDataSampler/Data.h>
#include <SkinRecon/AccDataSampler/Sampler.h>

#include <tumtools/Common/ConsoleReader.h>

using namespace Skin::Reconstruction::AccDataSampler;
using namespace Tum::Tools::Common;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    typedef bool (MainWindow::*cmd_handler_func)(const QString& s);
    typedef Skin::Implementation::IntfNode IntfNode;
    typedef Skin::Managers::Application::Type AppType;

    Ui::MainWindow *ui;

    ConsoleReader m_console;
    bool m_quit;

    QVector<cmd_handler_func> m_cmdHandlers;

    Skin::Managers::Application::Standard::Application  m_app;
    Skin::Managers::Viz m_viz;
    Skin::Managers::Recon m_recon;

    Skin::Reconstruction::AccDataSampler::Sampler       m_sampler;
    Skin::Visualization::Version2::SimpleViz*           m_simpleViz;

    QVector<QWidget*> m_widgets;
    QMap<QString,QWidget*> m_nameWidgetMap;     // name -> widget
    QMap<QWidget*,QString> m_wigetNameMap;      // widget -> name

    QMap<QString,QPushButton*> m_nameButtonMap; // name -> button
    QMap<QPushButton*,QString> m_buttonNameMap; // button -> name

    QSpinBox* m_sbNumOfPoses;
    QLCDNumber* m_lcdnCurrentPose;
    QStatusBar* m_status;

    int m_numOfCells;
    bool m_poseStarted;
    int m_currentPose;
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool autoConnect(const AppType& t=Skin::Managers::Application::Standard::Application::SingleIntfFtdiV2,
                     const IntfNode& n = Skin::Implementation::FtdiNode::StdNode);
    
private:
    bool handleHelpCommand(const QString& s);

    void closeEvent(QCloseEvent* e);

    void startPoseClicked();
    void nextPoseClicked();
    void stopPoseClicked();

private slots:
    void message(QString s);

    void handleEvents();

    void dataSamplerStarted();
    void dataSamplerStopped();
    void dataSamplerPoseFinished();
    void dataSamplerFinished();
    void dataSamplingFailed();

    void newNumberOfCells(int num);

public slots:
    void quit();

    void changeLedColor(Skin::Cell::LedColor color,int id=Skin::Implementation::Packets::Version2::ID_ALL);
    void newSkinOrganization(QVector<Skin::Cell::Organization> org);


signals:
    void finished();

    void newDataBunch(QVector<Skin::Cell::Data>);
    void sampledData(Skin::Reconstruction::AccDataSampler::Data d);

    void startLedFeedback(int num);
    void stopLedFeedback();





};

#endif // MAINWINDOW_H
