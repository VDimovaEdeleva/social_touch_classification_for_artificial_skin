#ifndef MAINCONSOLE_H
#define MAINCONSOLE_H

#include <QObject>
#include <QThread>

#include <SkinManagers/Application/Standard/Application.h>

#include <SkinManagers/Viz/Viz.h>
#include <SkinManagers/Recon/Recon.h>

#include <tumtools/Common/ConsoleReader.h>

using namespace Tum::Tools::Common;

class MainConsole : public QObject
{
    Q_OBJECT

    typedef Skin::Implementation::IntfNode IntfNode;
    typedef Skin::Managers::Application::Type AppType;

private:
    typedef bool (MainConsole::*cmd_handler_func)(const QString& s);

    ConsoleReader m_console;
    bool m_quit;

    QVector<cmd_handler_func> m_cmdHandlers;

    Skin::Managers::Application::Standard::Application  m_app;
    Skin::Managers::Viz m_viz;
    Skin::Managers::Recon m_recon;

public:
    MainConsole(QObject *parent = 0);
   ~MainConsole();

    bool autoConnect(const AppType& t=Skin::Managers::Application::Standard::Application::SingleIntfFtdiV2,
                     const IntfNode& n = Skin::Implementation::FtdiNode::StdNode);

private:
    bool handleHelpCommand(const QString& s);

private slots:
    void message(QString s);

public slots:
    void quit();

signals:
    void finished();

};

#endif // MAINCONSOLE_H
