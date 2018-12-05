/*******************************************************************************************
* Programmer: Freya
* Class: CptS 121, Spring  2018; Lab Section 10
* Programming Assignment: PA2
* Date: January 31, 2018
* Description: This program solves various equations with inputs from the user
*******************************************************************************************/

#include "Header.h"

/*Calculates force using newtons second law from user input of mass and acceleration
params: mass of object, acceleration of object
precondition:true
Postcondition:return product of mass and acceleration*/
double calculate_newtons_2nd_law(double mass, double acceleration)
{
	double force = 0;
	force = mass * acceleration;
	return force;
}

/*Calculates the volume of a cylinder using user inputs of radius and height
params: radius of cylinder, height of cylinder
precondition:true
Postcondition:returns volume of cylinder computed as PI * radius^2 *height*/
double calculate_volume_cylinder(double radius, double height)
{
	double volume = 0;
	volume = PI * pow(radius, 2) * height;
	return volume;
}

/*encodes a users given character
params: plaintext character 
precondition: true
Postcondition: returns encoded character*/
char perform_character_encoding(char plaintext_character)
{
	char encoded_character = 'a';
	encoded_character = (plaintext_character - 'a') + 'A';
	return encoded_character;
}

/*calculates the gravitational force between two objects (with masses given by user)
params: mass of object one, mass of object two, distance between the two objects
precondition:true
Postcondition: returns the gravitational force between the two objects calculated by force = G * mass1 * mass2 / distance^2*/
double calculate_gravity_force(double mass1, double mass2, double distance)
{
	double force = 0;
	force = G * mass1 * mass2 / pow(distance, 2);
	return force;
}

/*calculates the output voltage of a system with parallel circuits r1 and r2, and an input voltage vin
params: resistance (ohms) of resistor 1 and resistor 2 and the input voltage to the system
precondition: true
Postcondition: returns output voltage calculated by vout = r2 / (r1 + r2) * vin*/
double calculate_resistive_divider(double r1, double r2, double vin)
{
	double vout = 0;
	vout = r2 / (r1 + r2) * vin;
	return vout;
}

/*Calculates the distance between two cartesian coordinates (x1,y1) and (x2,y2) given by the user
params: two x coordinates and two y coordinates 
precondition:true
Postcondition: returns the distance between the two points calculated as qrt((x1 - x2)^2 + (y1 - y2)^2)*/
double calculate_distance_between_2pts(double x1, double x2, double y1, double y2)
{
	double distance = 0;
	distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return distance;
}

/*calculates a general equation given variable x, z and a, solving for y
params: general variables x, a and z
precondition: true
Postcondition: returns y*/
double calculate_general_equation(int a, double x, double z)
{
	double y = 0;
	y = (89 / 27) - z * x + a / (a % 2);
	return y;
}