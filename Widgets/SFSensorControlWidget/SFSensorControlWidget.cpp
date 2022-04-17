#include "SFSensorControlWidget/SFSensorControlWidget.h"
#include "ui_SFSensorControlWidget.h"

SFSensorControlWidget::SFSensorControlWidget(QWidget *parent)
    : SFBaseWidget(parent)
    , m_ui(new Ui::SFSensorControlWidget)
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


    connect(
        m_ui->accelerationX,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationXValueChanged
    );

    connect(
        m_ui->accelerationY,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationYValueChanged
    );

    connect(
        m_ui->accelerationZ,
        &QSlider::valueChanged,
        this,
        &SFSensorControlWidget::onAccelerationZValueChanged
    );
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
    m_ui->accelerationXState->setText(QString::number(value));
}

void SFSensorControlWidget::onAccelerationYValueChanged(int value)
{
    m_ui->accelerationYState->setText(QString::number(value));
}

void SFSensorControlWidget::onAccelerationZValueChanged(int value)
{
    m_ui->accelerationZState->setText(QString::number(value));
}