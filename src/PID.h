#ifndef PID_H
#define PID_H

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp; //Coefficient for the proportional part of the Controller. Describes how Strong the controller reacts on being off the track.

  double Ki; //Coefficient for integral part of the Controller. Sums up when vehicle is off track for a longer time and
             //produces a stronger reaction in this case. Because the track is a counter clockwise closed loop, the vehicle tends to be more on the
             //right side of the lane. The integral part counters this.

  double Kd; //Coefficient for differential part of the Controller. This part should slow down the reaction when the change in error is high, so that
             //the vehicle will not to much overshoot the target.

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
};

#endif /* PID_H */
