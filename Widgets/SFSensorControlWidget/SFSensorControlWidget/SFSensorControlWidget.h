#include <QWidget>
#include <QTimer>
#include <QMap>
#include <QString>
#include "SFBaseWidget/SFBaseWidget.h"

namespace Ui
{
    class SFSensorControlWidget;
}

class SFSensorControlWidget : public SFBaseWidget
{
    Q_OBJECT

    typedef enum
    {
        STOPPED = 0,
        WORKING
    } TimerState;

    class NoiseGenerator
    {
    public:
        NoiseGenerator(double variance);
        virtual ~NoiseGenerator() = default;

        double makeNoise(double value);

    protected:
        double m_variance;
    };

public:
    SFSensorControlWidget(QWidget *parent = 0);
    virtual ~SFSensorControlWidget();

public slots:
    void onAccelerationXValueChanged(int value);
    void onAccelerationYValueChanged(int value);
    void onAccelerationZValueChanged(int value);
    void onButtonRunClicked();
    void onTimerTimeout();

protected:
    void setVelocityX(double value);
    void setVelocityY(double value);
    void setVelocityZ(double value);

private:
    Ui::SFSensorControlWidget* m_ui;
    QTimer m_timer;
    int m_accelerationX;
    int m_accelerationY;
    int m_accelerationZ;
    double m_velocityX;
    double m_velocityY;
    double m_velocityZ;
    double m_currentVelocityX;
    double m_currentVelocityY;
    double m_currentVelocityZ;
    int m_timerInterval;
    TimerState m_timerState;
};




