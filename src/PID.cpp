#include "PID.h"

#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd)
{
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    total_cte = 0;
    prev_cte = 0;
}

void PID::UpdateError(double cte)
{
    p_error = Kp * cte;

    total_cte += cte;
    i_error = Ki * total_cte;

    d_error = Kd * (cte - prev_cte);
    prev_cte = cte;
}

double PID::TotalError()
{
    return p_error + d_error + i_error;
}