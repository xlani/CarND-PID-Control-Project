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
