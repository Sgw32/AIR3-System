// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

/// @file	PID.h
/// @brief	Generic PID algorithm, with EEPROM-backed storage of constants.

#ifndef __PID_H__
#define __PID_H__

//#include <AP_Common.h>
//#include <AP_Param.h>
#include <Ogre.h>
#include <stdlib.h>
#include <math.h>               // for fabs()


#ifdef RUN3
#ifndef PID_EXPORT
#define PID_EXPORT __declspec( dllimport )
#endif
#endif

#ifndef PID_EXPORT
#ifndef PID_EXPORT
#define PID_EXPORT __declspec( dllexport )
#endif
#endif

typedef signed char 	int8_t;
 
typedef unsigned char 	uint8_t;
 
typedef signed int 	int16_t;
 
typedef unsigned int 	uint16_t;
 
typedef signed long int 	int32_t;
 
typedef unsigned long int 	uint32_t;
 
typedef signed long long int 	int64_t;
 
typedef unsigned long long int 	uint64_t;
 




/// @class	PID
/// @brief	Object managing one PID control
class PID_EXPORT PID {
public:

	float constrain_float(float amt, float low, float high) {
    return (amt < low) ? low : ((amt > high) ? high : amt);
	}

    PID(const float &   initial_p = 0.0,
        const float &   initial_i = 0.0,
        const float &   initial_d = 0.0,
        const int16_t & initial_imax = 0)
    {
		
        _kp = initial_p;
        _ki = initial_i;
        _kd = initial_d;
        _imax = initial_imax;

		// set _last_derivative as invalid when we startup
		_last_derivative = 0;
    }

    /// Iterate the PID, return the new control value
    ///
    /// Positive error produces positive output.
    ///
    /// @param error	The measured error value
    /// @param scaler	An arbitrary scale factor
    ///
    /// @returns		The updated control output.
    ///
    float        get_pid(float error, float scaler,const Ogre::FrameEvent &evt);

	// get_pid() constrained to +/- 4500
    int16_t     get_pid_4500(float error, float scaler,const Ogre::FrameEvent &evt);

    /// Reset the PID integrator
    ///
    void        reset_I();

    /// Load gain properties
    ///
    void        load_gains();

    /// Save gain properties
    ///
    void        save_gains();

    /// @name	parameter accessors
    //@{

    /// Overload the function call operator to permit relatively easy initialisation
    void operator        () (const float    p,
                             const float    i,
                             const float    d,
                             const int16_t  imaxval) {
        _kp = p; _ki = i; _kd = d; _imax = imaxval;
    }

    float        kP() const {
        return _kp;
    }
    float        kI() const {
        return _ki;
    }
    float        kD() const {
        return _kd;
    }
    int16_t        imax() const {
        return _imax;
    }

    void        kP(const float v)               {
        _kp=v;
    }
    void        kI(const float v)               {
        _ki=v;
    }
    void        kD(const float v)               {
        _kd=v;
    }
    void        imax(const int16_t v)   {
        _imax=v;
    }

    float        get_integrator() const {
        return _integrator;
    }


private:
    float        _kp;
    float        _ki;
    float        _kd;
    unsigned int        _imax;

    float           _integrator;///< integrator value
    float           _last_error;///< last error for derivative
    float           _last_derivative;///< last derivative for low-pass filter
    uint32_t        _last_t;///< last time get_pid() was called in millis

    float           _get_pid(float error, uint16_t dt, float scaler);

    /// Low pass filter cut frequency for derivative calculation.
    ///
    /// 20 Hz becasue anything over that is probably noise, see
    /// http://en.wikipedia.org/wiki/Low-pass_filter.
    ///
    static const uint8_t        _fCut = 20;
};

#endif
