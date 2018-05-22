#include "PID.h"

using namespace std;

/*
* Code source: * Udacity class lesson PID control
               * Project walkthrough: https://www.youtube.com/watch?v=YamBuzDjrs8&feature=youtu.be
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {

    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    update_initialized = false;

    p_error = 0;
    i_error = 0;
    d_error = 0;

}

void PID::UpdateError(double cte) {

    //update i_error
    i_error += cte;

    //update d_error
    //first time call initialization
    // this sets d_error to 0 (and not cte) at t=0
    if(!update_initialized) {
        // d_error = 0; already set at PID::Init
        update_initialized = true;
        cout << "Initialization d_error done." << endl;
    }

    else {
        d_error = cte - p_error;
    }

    //update p_error
    p_error = cte;

}

double PID::TotalError() {

    double res = 0.0;

    res = Kp*p_error + Ki*i_error + Kd*d_error;

    //limit steering values to [-1, 1]
    if (res > 1.0) res = 1.0;
    else if (res < -1.0) res = -1.0;
    return res;

}

// double p_error;
// double i_error;
// double d_error;
//
// /*
// * Coefficients
// */
// double Kp;
// double Ki;
// double Kd;

// def twiddle(tol=0.2):
//     # Don't forget to call `make_robot` before every call of `run`!
//     p = [0, 0, 0]
//     dp = [1, 1, 1]
//     robot = make_robot()
//     x_trajectory, y_trajectory, best_err = run(robot, p)
//
//     # TODO: twiddle loop here
//     for i in len(p):
//         p[i] += dp[i]
//         _, _, err = run(robot, p)
//         if(err < best_err):
//             best_err = err
//             dp[i] *= 1.1
//         else:
//             p[i] -= 2. * dp[i]
//
//     return p, best_err
