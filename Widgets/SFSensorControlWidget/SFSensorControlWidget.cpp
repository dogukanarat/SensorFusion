#include "SFSensorControlWidget/SFSensorControlWidget.h"
#include "ui_SFSensorControlWidget.h"

SFSensorControlWidget::SFSensorControlWidget(QWidget *parent)
    : SFBaseWidget{parent}
    , m_ui{new Ui::SFSensorControlWidget}
    , m_timer{}
    , m_accelerationX{0}
    , m_accelerationY{0}
    , m_accelerationZ{0}
    , m_velocityX{0.0}
    , m_velocityY{0.0}
    , m_velocityZ{0.0}
    , m_currentVelocityX{0.0}
    , m_currentVelocityY{0.0}
    , m_currentVelocityZ{0.0}
    , m_timerInterval{100}
    , m_timerState{STOPPED}
{
    m_ui->setupUi(this);

    m_ui->accelerationX->setRange(-10, 10);
    m_ui->accelerationX->setValue(0);
    m_ui->accelerationX->setSingleStep(1);

    m_ui->accelerationY->setRange(-10, 10);
    m_ui->accelerationY->setValue(0);
    m_ui->accelerationY->setSingleStep(1);

    m_ui->accelerationZ->setRange(-10, 10);
    m_ui->accelerationZ->setValue(0);
    m_ui->accelerationZ->setSingleStep(1);

    onAccelerationXValueChanged(0);
    onAccelerationYValueChanged(0);
    onAccelerationZValueChanged(0);

    setVelocityX(0.0);
    setVelocityY(0.0);
    setVelocityZ(0.0);

    connect
    (
        m_ui->accelerationX,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationXValueChanged
    );

    connect
    (
        m_ui->accelerationY,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationYValueChanged
    );

    connect
    (
        m_ui->accelerationZ,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationZValueChanged
    );

    connect
    (
        m_ui->buttonRun,
        &QPushButton::clicked,
        this,
        &SFSensorControlWidget::onButtonRunClicked
    );

    connect
    (
        &m_timer,
        &QTimer::timeout,
        this,
        &SFSensorControlWidget::onTimerTimeout
    );

    m_timer.setInterval(m_timerInterval);
}

SFSensorControlWidget::~SFSensorControlWidget()
{
    delete m_ui;
}

SFSensorControlWidget::NoiseGenerator::NoiseGenerator(double variance)
    : m_variance{variance}
{
}

double SFSensorControlWidget::NoiseGenerator::makeNoise(double value)
{
    return value + qrand() % (int)(m_variance * 2) - m_variance;
}

void SFSensorControlWidget::onAccelerationXValueChanged(int value)
{
    m_accelerationX = value;
    m_ui->accelerationXState->setText(QString::number(m_accelerationX));
}

void SFSensorControlWidget::onAccelerationYValueChanged(int value)
{
    m_accelerationY = value;
    m_ui->accelerationYState->setText(QString::number(m_accelerationY));
}

void SFSensorControlWidget::onAccelerationZValueChanged(int value)
{
    m_accelerationZ = value;
    m_ui->accelerationZState->setText(QString::number(m_accelerationZ));
}

void SFSensorControlWidget::onButtonRunClicked()
{
    if (m_timerState == STOPPED)
    {
        m_timerState = WORKING;
        m_timer.start();
        m_ui->buttonRun->setText("Stop");
    }
    else
    {
        m_timerState = STOPPED;
        m_timer.stop();
        m_ui->buttonRun->setText("Run");
    }
}

void SFSensorControlWidget::onTimerTimeout()
{
    double dtAccelerationX = (double)m_accelerationX / m_timerInterval;
    double dtAccelerationY = (double)m_accelerationY / m_timerInterval;
    double dtAccelerationZ = (double)m_accelerationZ / m_timerInterval;

    m_currentVelocityX += dtAccelerationX;
    m_currentVelocityY += dtAccelerationY;
    m_currentVelocityZ += dtAccelerationZ;

    setVelocityX(m_currentVelocityX);
    setVelocityY(m_currentVelocityY);
    setVelocityZ(m_currentVelocityZ);
}

void SFSensorControlWidget::setVelocityX(double value)
{
    m_velocityX = value;
    m_ui->velocityXState->setText(QString::number(m_velocityX));
}

void SFSensorControlWidget::setVelocityY(double value)
{
    m_velocityY = value;
    m_ui->velocityYState->setText(QString::number(m_velocityY));
}

void SFSensorControlWidget::setVelocityZ(double value)
{
    m_velocityZ = value;
    m_ui->velocityZState->setText(QString::number(m_velocityZ));
}