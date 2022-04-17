#include <QWidget>
#include "SFCore/SFCommon.h"

class SFBaseWidget : public QWidget
{
    Q_OBJECT

public:
    SFBaseWidget(QWidget *parent = 0);
    virtual ~SFBaseWidget() = default;

private:
};