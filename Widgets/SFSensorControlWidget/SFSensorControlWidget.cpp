#include "SFSensorControlWidget/SFSensorControlWidget.h"
#include "ui_SFSensorControlWidget.h"

SFSensorControlWidget::SFSensorControlWidget(QWidget *parent)
    : SFBaseWidget(parent)
    , m_ui(new Ui::SFSensorControlWidget)
{
    m_ui->setupUi(this);

}

SFSensorControlWidget::~SFSensorControlWidget()
{
    delete m_ui;
}