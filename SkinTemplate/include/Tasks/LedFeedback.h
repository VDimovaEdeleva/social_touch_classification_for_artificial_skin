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
* Changed:          26.05.2014
*
* Comment:
*
*
********************************************************************/

#ifndef SKIN_TUTORIAL_TASKS_LED_FEEDBACK_H
#define SKIN_TUTORIAL_TASKS_LED_FEEDBACK_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>
#include <QVector>
#include <QMap>
#include <QTimer>

#include <SkinCore/Cell/Data.h>
#include <SkinCore/Cell/LedColor.h>


class LedFeedback : public QObject
{
    Q_OBJECT

public:

private:
    QThread m_thread;
    QTimer m_timer;

    QVector<Skin::Cell::Data> m_data;
    QMap<int,int> m_cellIdMap;      // map cell id to index

    bool m_started;

public:
    explicit LedFeedback();
    ~LedFeedback();

private:


private slots:
    void update();

public slots:
    void start(int num);
    void stop();

    void newDataBunch(QVector<Skin::Cell::Data> d);

signals:
    void changeLedColor(Skin::Cell::LedColor color);
    void changeLedColor(Skin::Cell::LedColor color,int id);


};

#endif // SKIN_TUTORIAL_TASKS_LED_FEEDBACK_H
