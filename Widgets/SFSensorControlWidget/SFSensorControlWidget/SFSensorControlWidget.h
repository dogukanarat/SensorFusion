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

public:
    SFSensorControlWidget(QWidget *parent = 0);
    virtual ~SFSensorControlWidget();

public slots:

private:
    Ui::SFSensorControlWidget* m_ui;

};
