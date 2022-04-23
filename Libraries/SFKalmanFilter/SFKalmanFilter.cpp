#include "SFKalmanFilter/SFKalmanFilter.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace SF;

SFKalmanFilter::SFKalmanFilter(
    double dt,
    const Eigen::MatrixXd &A,
    const Eigen::MatrixXd &C,
    const Eigen::MatrixXd &Q,
    const Eigen::MatrixXd &R,
    const Eigen::MatrixXd &P)
    : m_m(C.rows())
    , m_n(A.rows())
    , m_dt(dt)
    , m_initialized(false)
    ,m_I(m_n, m_n)
    , m_xHat(m_n)
    , m_xHatNew(m_n)
{
    m_matrices.A = A;
    m_matrices.C = C;
    m_matrices.Q = Q;
    m_matrices.R = R;
    m_matrices.P0 = P;
    m_I.setIdentity();
}

SFKalmanFilter::SFKalmanFilter() {}

void SFKalmanFilter::initialise(double t0, const Eigen::VectorXd &x0)
{
    m_xHat = x0;
    m_matrices.P = m_matrices.P0;
    this->m_t0 = t0;
    m_t = t0;
    m_initialized = true;
}

void SFKalmanFilter::initialise()
{
    m_xHat.setZero();
    m_matrices.P = m_matrices.P0;
    m_t0 = 0;
    m_t = m_t0;
    m_initialized = true;
}

void SFKalmanFilter::update(const Eigen::VectorXd &y)
{
    if (!m_initialized)
    {
        throw std::runtime_error("Filter is not initialized!");
    }
    else {}

    m_xHatNew = m_matrices.A * m_xHat;

    m_matrices.P = m_matrices.A * m_matrices.P * m_matrices.A.transpose() + m_matrices.Q;

    m_matrices.K = m_matrices.P * m_matrices.C.transpose() * 
        (m_matrices.C * m_matrices.P * m_matrices.C.transpose() + m_matrices.R).inverse();

    m_xHatNew += m_matrices.K * (y - m_matrices.C * m_xHatNew);

    m_matrices.P = (m_I - m_matrices.K * m_matrices.C) * m_matrices.P;

    m_xHat = m_xHatNew;

    m_t += m_dt;
}

void SFKalmanFilter::update(const Eigen::VectorXd &y, double dt, const Eigen::MatrixXd A)
{

    this->m_matrices.A = A;
    this->m_dt = dt;
    update(y);
}
