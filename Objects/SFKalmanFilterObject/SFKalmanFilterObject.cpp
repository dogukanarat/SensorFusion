#include "SFKalmanFilterObject/SFKalmanFilterObject.h"
#include <Eigen/Dense>
#include <QDebug>
#include <iostream>

using Eigen::MatrixXd;

SFKalmanFilterObject::SFKalmanFilterObject(QObject* parent)
    : QObject(parent)
{
    MatrixXd m(2,2);
    m(0,0) = 3;
    m(1,0) = 2.5;
    m(0,1) = -1;
    m(1,1) = m(1,0) + m(0,1);
    std::cout << m;
}
