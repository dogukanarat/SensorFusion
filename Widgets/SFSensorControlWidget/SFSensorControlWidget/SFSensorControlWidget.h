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

private:
    Ui::SFSensorControlWidget* m_ui;

};
