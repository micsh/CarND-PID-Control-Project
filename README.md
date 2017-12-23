# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Overview
---
The goal of the project is to build a PID controller in C++ and tune its parameters, using the simulator.
The simulator provides cross-track-error, speed, and steering-angle, and the controller responds to the streaming data with the steering-angle.
---
## PID
PID stands for Proportional, Integral, Differential.
The PID controller calculates the steering-angle using the cross-track-error in the following way:
* Proportional:
  The steering-angle component is proportional to the cross-track-error. This is the main component that generaly aims to correct the cross-track-error.
* Integral:
  The steering-angle component is proportional to an assumed constant bias in the cross-track-error. This component does help with constant biases, but if too big, will have an effect of memory when turning.
* Differential:
  The steering-angle component is proportional to the change in cross-track-error. This helps with overshooting and also helps smooth the Proportional component.

## Final parameters and Twiddle
I have tried setting and tuning the Kp, Ki, Kd parameters manually initially and then I have also tried implementing the Twiddle algorithm as suggest in the videos.
The manual tuning was helpful get a feeling for how the different components affect the driving behaviour. 
When the manual tuning was enough for the car to at least complete a track, I have added the twiddle algorithm to search for a better solution. And it did get better for a while, but I guess that the objective funtion of minimizing the total cross-track-error isn't perfect, and wait long enought and while the error goes down, the chance for a catastrophic mistake (such as driving off-road) goes up.

---
## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)


