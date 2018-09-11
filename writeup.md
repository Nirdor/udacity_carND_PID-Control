# **PID-Control** 

---

**PID-Control Project**

The goals / steps of this project are the following:
* Implement a PID Controller that controls the steering of a car in the simulator
* Test that the controler successfully drives around the track without leaving the road
* Summarize the results with a written report


## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/824/view) individually and describe how I addressed each point in my implementation.  

---
### Compilation

#### 1. Code must compile without errors with `cmake` and `make`.

My project includes the following files:
* src/PID.h header file for the PID Controller class
* src/PID.cpp source file for the PID Controller class
* src/json.hpp library for handling json
* src/main.cpp main source file containig the main loop

I didn't change the CMakeFiles.txt so everything should compile fine.

### Implementation

#### 1. The PID procedure follows what was taught in the lessons.

My PID Controller follows the lessons.

### Reflection

#### 1. Describe the effect each of the P, I, D components had in your implementation.

* the P Coefficient is for the proportional part of the Controller. Describes how Strong the controller reacts on being off the track.
* the I Coefficient is for the integral part of the Controller. Sums up when vehicle is off track for a longer time and produces a stronger reaction in this case.
Because the track is a counter clockwise closed loop, the vehicle tends to be more on the right side of the lane. The integral part counters this.
* the D Coefficient is for the differential part of the Controller. This part should slow down the reaction when the change in error is high, so that the vehicle will not to much overshoot the target.

#### 2. Describe how the final hyperparameters were chosen.

The Coefficients were chosen by manual tuning. First I started with [1.0, 0.0, 0.0], then adjusted the proportional part till the car reacts
not to slow and not to fast [0.2, 0.0, 0.0]. Second, I adjusted the differential part till the car stops overshooting in the center of the lane.
[0.2, 0.0, 2.5]. Third, I was adding a tiny bit of integral coefficient to improve performance: [0.2, 0.00001, 2.5].

### Simulation

#### 1. The vehicle must successfully drive a lap around the track.

On my machine the vehicle drives successfully around the lap.