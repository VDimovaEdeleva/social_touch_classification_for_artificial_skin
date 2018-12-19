#include "MainConsole.h"
#include <stdio.h>

#include <QDebug>
#include <QElapsedTimer>
#include <QStringList>

#include <unistd.h>

using namespace Skin;

MainConsole::MainConsole(QObject* parent) :
    m_app(),
    m_viz(&m_app),
    m_recon(&m_app)
{
    m_quit          = false;

    m_cmdHandlers.append(&MainConsole::handleHelpCommand);

    // console reader
    QObject::connect(&m_console,SIGNAL(message(QString)),
                     this,SLOT(message(QString)));

    // recon
    QObject::connect(&m_recon,SIGNAL(newSkinConfig(Skin::Config)),
                     &m_viz,SLOT(newSkinConfig(Skin::Config)));
}


MainConsole::~MainConsole()
{
}

bool MainConsole::autoConnect(const AppType& t, const IntfNode& n)
{
    return m_app.autoConnect(t,n);
}


bool MainConsole::handleHelpCommand(const QString& s)
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


void MainConsole::message(QString s)
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

void MainConsole::quit()
{
    m_quit = true;

    if(m_app.isConnected())
    {
        connect(&m_app,SIGNAL(disconnected()),
                this,SLOT(quit()));

        QMetaObject::invokeMethod(&m_app,"disconnect");
    }
    else
    {
        emit finished();
    }

    if(!m_app.isConnected())
    {
        emit finished();
    }

}

