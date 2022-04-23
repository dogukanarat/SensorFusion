#ifndef INCLUDED_SFKALMANFILTEROBJECT_H
#define INCLUDED_SFKALMANFILTEROBJECT_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "SFCore/SFCommon.h"

class SFKalmanFilterObject : public QObject
{
    Q_OBJECT
    
public:
    SFKalmanFilterObject(QObject* parent = NULL);
    virtual ~SFKalmanFilterObject() = default;
    
protected:
};
    
#endif // INCLUDED_SFKALMANFILTEROBJECT_H
