/*******************************************************************************************
* Programmer: Freya                                                                     
* Class: CptS 121, Spring  2018; Lab Section 10                                          
* Programming Assignment: PA2                                                     
* Date: January 31, 2018                                                                          
* Description: This program solves various equations with inputs from the user     
*******************************************************************************************/

#include <stdio.h>
#include <math.h>

#define PI 3.1415926 
#define G 6.67e-11

double calculate_newtons_2nd_law(double mass, double acceleration);
double calculate_volume_cylinder(double radius, double height);
char perform_character_encoding(char plaintext_character);
double calculate_gravity_force(double mass1, double mass2, double distance);
double calculate_resistive_divider(double r1, double r2, double vin);
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2);
double calculate_general_equation(int a, double x, double z);
