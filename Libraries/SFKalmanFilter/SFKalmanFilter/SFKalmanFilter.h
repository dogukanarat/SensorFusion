#ifndef INCLUDED_SFKALMANFILTER_H
#define INCLUDED_SFKALMANFILTER_H

#include <Eigen/Dense>
#include "SFCore/SFUtilities.h"

namespace SF
{
    class SFKalmanFilter
    {

    public:
        /**
         * Create a Kalman filter with the specified matrices.
         *   A - System dynamics matrix
         *   C - Output matrix
         *   Q - Process noise covariance
         *   R - Measurement noise covariance
         *   P - Estimate error covariance
         */
        SFKalmanFilter(
            double dt,
            const Eigen::MatrixXd &A,
            const Eigen::MatrixXd &C,
            const Eigen::MatrixXd &Q,
            const Eigen::MatrixXd &R,
            const Eigen::MatrixXd &P);

        /**
         * Create a blank estimator.
         */
        SFKalmanFilter();

        /**
         * Initialize the filter with initial states as zero.
         */
        void initialise();

        /**
         * Initialize the filter with a guess for initial states.
         */
        void initialise(double t0, const Eigen::VectorXd &x0);

        /**
         * Update the estimated state based on measured values. The
         * time step is assumed to remain constant.
         */
        void update(const Eigen::VectorXd &y);

        /**
         * Update the estimated state based on measured values,
         * using the given time step and dynamics matrix.
         */
        void update(const Eigen::VectorXd &y, double dt, const Eigen::MatrixXd A);

        /**
         * Return the current state and time.
         */
        Eigen::VectorXd state()
        {
            return m_xHat;
        };

        double time()
        { 
            return m_t;
        };

    private:
        // Matrices for computation
        typedef struct
        {
            Eigen::MatrixXd A;
            Eigen::MatrixXd C;
            Eigen::MatrixXd Q;
            Eigen::MatrixXd R;
            Eigen::MatrixXd P;
            Eigen::MatrixXd K;
            Eigen::MatrixXd P0;
        } Matrices;

        Matrices m_matrices;
        
        // System dimensions
        int m_m;
        int m_n;

        // Initial and current time
        double m_t0;
        double m_t;

        // Discrete time step
        double m_dt;

        // Is the filter initialized?
        bool m_initialized;

        // n-size identity
        Eigen::MatrixXd m_I;

        // Estimated states
        Eigen::VectorXd m_xHat;
        Eigen::VectorXd m_xHatNew;
    };
}

#endif // INCLUDED_SFKALMANFILTER_H