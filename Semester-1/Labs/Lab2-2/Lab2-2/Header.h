/*Freya Varez
Write a program that computes the duration of a projectile's flight and its height above the ground when it reaches the target. As part of your solution, write and call a function that displays instructions to the program user. You will need to use the following information to solve this problem:

Problem Constant
G 32.17              gravitational constant 

Problem Inputs
double theta      angle (radians) of elevation 
double distance  distance (ft) to target 
double velocity   projectile velocity (ft/sec) 

Problem Outputs
double time       time (sec) of flight
double height     height of impact 

Relevant Formulas
time = (distance) / (velocity * cos(theta))    make sure to include math.h to use cos ( ) and sin ( ) 
height = velocity * sin(theta) * time - ((G * time ^ 2) / 2)*/

#include <stdio.h>
#include <math.h>
#define G 32.7

double get_theta();
double get_distance();
double get_velocity();
double calc_time(double theta, double distance, double velocity);
double calc_height(double theta, double distance, double velocity, double time);

