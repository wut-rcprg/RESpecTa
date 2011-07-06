class MyTypeWidget;
class sysIniWidget;
class runGenWidget;
class stopGenWidget;
class iniSensorWidget;
class getSensorWidget;
class emptyGenForSetWidget;
class emptyGenWidget;
class waitStateWidget;
class PoseDialog;
class MPDialog;
class ECPDialog;

#ifndef STATETYPEWIDGETS_H
#define STATETYPEWIDGETS_H

#include "respecta.h"
#include "States.h"
#include "globals.h"
#include "Pose.h"
#include "stateWidget.h"

#include <QDialog>

QT_BEGIN_NAMESPACE
class QCheckBox;
class QDialogButtonBox;
class QComboBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;
class QGridLayout;
class QVBoxLayout;
class QListWidget;
class QListItemWidget;
QT_END_NAMESPACE
//class PoseDialog;
//class ECPDialog;
//class MPDialog;
//class StateWidget;

class MyTypeWidget : public QWidget
{
   Q_OBJECT
public:
    MyTypeWidget(QWidget * parent,Model * newmod ):QWidget(parent){mod = newmod;}
    virtual BaseState * getStateObject() = 0;
    virtual void setState(BaseState * state) = 0;
private:
    Model * mod;
};

class sysIniWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    sysIniWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    QListWidget * robotsInitialized;
    void setState(BaseState * state);
private:
    sysInitState * State;

    ECPDialog * ecpDialog;
    MPDialog * mpDialog;
signals:
    void reportError(QString msgString);
private slots:
    void removeECPSection();
    void createECPSection();
    void changeMPSection();
    void InsertECP(robotInit newInit);
    void InsertMP (std::vector<Sensor> sensors, Transmitter trans);
    void forwardError(QString msgString){emit reportError(msgString);}
};

class runGenWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    runGenWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    RunGenState * State;

    QComboBox * genTypeCombo;
    QComboBox * robotCombo;
    QLineEdit * argsLineEdit;
    QLineEdit * speechLineEdit;
    QLabel * speechLabel;
    QLabel * argsLabel;
    QListWidget * PoseList;
    QLineEdit * trjFileName;
    PoseDialog * poseDialog;
signals:
    void reportError(QString msgString);
private slots:
    void CoordsInsert(Coordinates * newCoords);
    void showAddPosesDialog();
    void selectTrjFilePath();
    void forwardError(QString msgString){emit reportError(msgString);}
};

class emptyGenForSetWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    emptyGenForSetWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    EmptyGenForSetState * State;

    QListWidget * FirstRobotList;
    QListWidget * SecondRobotList;
    QComboBox * FirstRobotCombo;
    QComboBox * SecondRobotCombo;
signals:
    void reportError(QString msgString);
private slots:
    void addFirst();
    void removeFirst();
    void addSecond();
    void removeSecond();
};

class emptyGenWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    emptyGenWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    EmptyGenState * State;

    QLineEdit * argLineEdit;
    QComboBox * RobotCombo;
};

class waitStateWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    waitStateWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    WaitState * State;

    QLineEdit * timeSpan;
};

class stopGenWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    stopGenWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    StopGenState * State;

    QListWidget * RobotList;
    QComboBox * RobotCombo;
signals:
    void reportError(QString msgString);
private slots:
    void add();
    void remove();
};

class iniSensorWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    iniSensorWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    void setState(BaseState * state);
private:
    InitiateSensorState * State;

    QComboBox * SensorCombo;
};


class getSensorWidget : public MyTypeWidget
{
    Q_OBJECT
public:
    getSensorWidget(QWidget * parent,Model * newmod );
    BaseState * getStateObject();

    //GetSensorState * getState(){return State;}
    //void setState(GetSensorState * newState){State = newState;}
    void setState(BaseState * state);
private:
    GetSensorState * State;

    QComboBox * SensorCombo;
};


//***********************************************   DIALOGS   ***********************************************//


class PoseDialog:public QDialog
{
    Q_OBJECT
public:
    PoseDialog(QWidget * parent);

    Coordinates * getCoords(){return coords;}
    void setCoords(Coordinates * newCoords){coords = newCoords;}
    void coordsUpdated();
private:
    int num;
    QListWidget * poseList;
    QComboBox * motionTypeCombo;
    QComboBox * coordTypeCombo;
    std::vector<QLineEdit *> coordEdit;
    std::vector<QLineEdit *> velEdit;
    std::vector<QLineEdit *> accEdit;

    Coordinates * coords;

signals:
    void InsertCoords(Coordinates * newCoords);
    void reportError(QString msgString);
private slots:
    void AddPose();
    void PoseOK();
    void PoseCancel();
    void PosesReset();
};

class ECPDialog:public QDialog
{
    Q_OBJECT
public:
    ECPDialog(QWidget * parent);
private:
    QListWidget * genList;
    QComboBox * genTypeCombo;
    QLineEdit * argLineEdit;
    QComboBox * robotCombo;
    robotInit robotInitObj;
    sysIniWidget * parentx;
    sysInitState * tmpState;

signals:
    void InsertECP(robotInit newInit);
    void reportError(QString msgString);

private slots:
    void remove();
    void add();
    void OKPressed();
    void CancelPressed();
};

class MPDialog:public QDialog
{
    Q_OBJECT
public:
    MPDialog(QWidget * parent);
    void setSensTrans(std::vector<Sensor> sens, Transmitter tran);
private:
    QListWidget * sensorList;
    QComboBox * sensorCombo;
    QComboBox * transmitterCombo;

signals:
    void InsertMP (std::vector<Sensor> sensors, Transmitter trans);
    void reportError(QString msgString);

private slots:
    void remove();
    void add();
    void OKPressed();
    void CancelPressed();
};


#endif // STATETYPEWIDGETS_H
