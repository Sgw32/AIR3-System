// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

/// @file	PID.cpp
/// @brief	Generic PID algorithm

#include <math.h>

#include "PID.h"

PID_EXPORT float PID::get_pid(float error, float scaler,const Ogre::FrameEvent &evt)
{
   // uint32_t tnow = evt.timeSinceLastFrame*1000;
    uint32_t dt = evt.timeSinceLastFrame*1000;
    float output            = 0;
    float delta_time;

    if (dt > 1000) {
        dt = 0;

		// if this PID hasn't been used for a full second then zero
		// the intergator term. This prevents I buildup from a
		// previous fight mode from causing a massive return before
		// the integrator gets a chance to correct itself
		reset_I();
    }
   // _last_t = 0;

    delta_time = (float)dt / 1000.0f;

    // Compute proportional component
    output += error * _kp;

    // Compute derivative component if time has elapsed
    if ((fabsf(_kd) > 0) && (dt > 0)) {
        float derivative;

		if (!_last_derivative) {
			// we've just done a reset, suppress the first derivative
			// term as we don't want a sudden change in input to cause
			// a large D output change			
			derivative = 0;
			_last_derivative = 0;
		} else {
			derivative = (error - _last_error) / delta_time;
		}

        // discrete low pass filter, cuts out the
        // high frequency noise that can drive the controller crazy
        float RC = 1/(2*3.1415926535f*_fCut);
        derivative = _last_derivative +
                     ((delta_time / (RC + delta_time)) *
                      (derivative - _last_derivative));

        // update state
        _last_error             = error;
        _last_derivative    = derivative;

        // add in derivative component
        output                          += _kd * derivative;
    }

    // scale the P and D components
    output *= scaler;

    // Compute integral component if time has elapsed
    if ((fabsf(_ki) > 0) && (dt > 0)) {
        _integrator             += (error * _ki) * scaler * delta_time;
        if (_integrator < -((float)_imax)) {
            _integrator = -((float)_imax);
        } else if (_integrator > _imax) {
            _integrator = _imax;
        }
        output                          += _integrator;
    }

    return output;
}

PID_EXPORT int16_t PID::get_pid_4500(float error, float scaler,const Ogre::FrameEvent &evt)
{
	float v = get_pid(error, scaler,evt);
	return constrain_float(v, -4500, 4500);
}

PID_EXPORT void
PID::reset_I()
{
    _integrator = 0;
	// we use NAN (Not A Number) to indicate that the last 
	// derivative value is not valid
    _last_derivative = 0;
}

PID_EXPORT void
PID::load_gains()
{

}

PID_EXPORT void
PID::save_gains()
{

}
