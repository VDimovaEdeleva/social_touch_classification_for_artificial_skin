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

#ifndef SKIN_TUTORIAL_TASKS_RECON_H
#define SKIN_TUTORIAL_TASKS_RECON_H

#include <QObject>
#include <QThread>
#include <QElapsedTimer>
#include <QVector>
#include <QMap>
#include <QTimer>

#include <SkinCore/Cell/Data.h>
#include <SkinCore/Cell/Organization.h>
#include <SkinRecon/AccDataSampler/Data.h>


class Recon : public QObject
{
    Q_OBJECT

private:
    typedef Skin::Reconstruction::AccDataSampler::Data SamplerData;

    static const QVector<Eigen::Vector3d> defaultPos;
    static const QVector<Eigen::Vector3d> defaultRollAxis;
    static const QVector<Eigen::Vector3d> defaultPitchAxis;
    static const QVector<Eigen::Vector3d> defaultYawAxis;

private:
    static Eigen::Vector3d getRPY(const Eigen::Matrix3d& r);
    static Eigen::Matrix3d rotRPY(const Eigen::Vector3d& rpy);
    static QString matrixToString(const Eigen::MatrixXd& m);

public:


private:
    QThread m_thread;

public:
    explicit Recon();
    ~Recon();

private:


private slots:

public slots:
    void sampledData(Skin::Reconstruction::AccDataSampler::Data d);

signals:
    void newSkinOrganization(QVector<Skin::Cell::Organization>);


};


#endif // SKIN_TUTORIAL_TASKS_RECON_H
