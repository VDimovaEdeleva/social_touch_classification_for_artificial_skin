/*********************************************************************
* Compiler:         QT Creator V2.4.1
*                   QT V 4.8.0 (64 bit)
*
* Company:          Institute for Cognitive Systems
*                   Technical University of Munich
*
* Author:           Florian Bergner
*
* Compatibility:
*
* Software Version: V1.0
*
* Created:          26.05.2014
* Changed:
*
* Comment:
*
*
********************************************************************/

#include "Tasks/LedFeedback.h"
#include <QDebug>
#include <iostream>
#include <fstream>


LedFeedback::LedFeedback()
{
    m_started = false;

    moveToThread(&m_thread);

    m_thread.start();
    m_timer.start(20);     // 50 Hz
}

LedFeedback::~LedFeedback()
{
    m_thread.exit();
    m_thread.wait(10);
}

void LedFeedback::start(int num)
{
    m_data.reserve(num);
    m_cellIdMap.clear();

    connect(&m_timer,SIGNAL(timeout()),this,SLOT(update()));

    m_started = true;
}

void LedFeedback::stop()
{
    disconnect(&m_timer,SIGNAL(timeout()),this,SLOT(update()));
    m_started = false;
}

void LedFeedback::update()
{
    std::ofstream myfile;

    // Viktorija: write the name of the file here
    myfile.open("prox_and_force.csv",std::ios_base::app);
    //myfile << "id, \t proximity, \t force[1], \t force[2], \t force[3], \t temperature" << std::endl;

    for(int i=0; i<m_data.size(); i++)
    {
        int id = m_data.at(i).cellId;
        const double prox = m_data.at(i).prox.at(0);
        const double* force = m_data.at(i).force.data();

        // ??????????????????????????????????????????????????????????? //
        //      change the led color according to touch event

        Skin::Cell::LedColor c = Skin::Cell::LedColor::White;

        // Viktorija: add the data that you want to have in the file
        myfile << id << "," << prox << "," << force[0] << "," <<  force[1] << "," << force[2] << std::endl;
        //myfile << force[1] << ",\t"<< *force+1 << std::endl;


        if((force[1] + force[2] + force[0]) > 0.05)
        {
            c = Skin::Cell::LedColor::Blue;
            //myfile << id << ":" << force[1] << "," <<  force[2] << "," << force[0] << std::endl;
            //myfile << "Hello world \n";
            std::cout << "Written in file\n";
        }
        else if(prox > 0.2)
        {
            c = Skin::Cell::LedColor::Red;
        }
        else
        {
            c = Skin::Cell::LedColor::Green;
        }

        // ??????????????????????????????????????????????????????????? //

        emit changeLedColor(c,id);
    }
    myfile.close();
}

void LedFeedback::newDataBunch(QVector<Skin::Cell::Data> d)
{
    if(!m_started)
    {
        return;
    }

    for(int i=0; i<d.size(); i++)
    {
        int id  = d.at(i).cellId;
        int ind = m_cellIdMap.value(id,-1);

        if(ind == -1)
        {
            m_cellIdMap.insert(id,m_data.size());
            m_data.append(d.at(i));
            continue;
        }

        m_data[ind] = d.at(i);
    }
}

