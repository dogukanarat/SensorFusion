#ifndef INCLUDED_SFKALMANFILTER_H
#define INCLUDED_SFKALMANFILTER_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "SFCore/SFCommon.h"

class SFKalmanFilter : public QObject
{
    Q_OBJECT
    
public:
    SFKalmanFilter(QObject* parent = NULL);
    virtual ~SFKalmanFilter() = default;
    
protected:
};
    
#endif // INCLUDED_SFKALMANFILTER_H
