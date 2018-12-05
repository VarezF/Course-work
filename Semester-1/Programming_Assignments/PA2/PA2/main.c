/*******************************************************************************************
* Programmer: Freya
* Class: CptS 121, Spring  2018; Lab Section 10
* Programming Assignment: PA2
* Date: January 31, 2018
* Description: This program solves various equations with inputs from the user 
*******************************************************************************************/
#include "Header.h"

int main(void)
{
	//Newton’s Second Law of Motion: force = mass * acceleration		
	double mass = 0, acceleration = 0, force = 0;
	printf_s("Newtons second law calculator: \nInput mass\n");//prompts the user for mass and acceleration
	scanf_s("%lf", &mass);
	printf_s("Input acceleration\n");
	scanf_s("%lf", &acceleration);
	force = calculate_newtons_2nd_law(mass, acceleration);// sends mass and acceleration to the function calculate_newtons_2nd_law(), calculating for force
	printf_s("force = %.2lf\n___________________________________\n", force); //displays force

	//Volume of a cylinder: volume_cylinder = PI * radius2 * height
	double radius = 0, height = 0, volume = 0;
	printf_s("Volume of a cylinder calculator: \nEnter the radius of the cylinder:\n");//prompts the user for radius and height of their cylinder
	scanf_s("%lf", &radius);
	printf_s("Enter height of the cylinder:\n");
	scanf_s("%lf", &height);
	volume = calculate_volume_cylinder(radius, height);//sends radius and height values to the calculate_volume() function to calculate the cylinders volume
	printf_s("Volume = %.2lf\n___________________________________\n", volume);//displays volume

	//Character encoding: encoded_character = (plaintext_character - 'a') + 'A'
	char plaintext_character = '\0', encoded_character = 'a';
	printf_s("character encoding: \nEnter a plaintext character\n");//prompts the user for a plain text character for encoding
	scanf_s(" %c", &plaintext_character);
	encoded_character = perform_character_encoding(plaintext_character);//sends the plaintext character to the perform_character_encoding() function for character encoding
	printf_s("encoded character = %c\n__________________________\n", encoded_character);//displays encoded character

	//Gravity: force = G * mass1 * mass2 / distance2, where G is the gravitational constant with value 6.67 * 10-11
	double mass1 = 0, mass2 = 0, distance = 0;
	printf_s("Gravitational force calculator: \nEnter mass of object 1\n");//prompts the user for the masses of the two objects, and the distanc ebewteen them
	scanf_s("%lf", &mass1);
	printf_s("Enter mass of object 2\n");
	scanf_s("%lf", &mass2);
	printf_s("Enter distance between mass 1 and mass 2\n");
	scanf_s("%lf", &distance);
	force = calculate_gravity_force(mass1, mass2, distance);//sends the two objetc masses and the distance between them to the calculate_gravity_force() function to calculate the gravitational force between them
	printf_s("Force = %.2lf\n_________________________\n", force);//displays gravitational force

	//Resistive divider: vout = r2 / (r1 + r2) * vin
	double r1 = 0, r2 = 0, vin = 0, vout = 0;
	printf_s("Resistive divider calculator: \nEnter resistance 1 (ohms)\n");//prompts the user for the resistace in ohms of the two resistors as well as the input voltage to the circuit
	scanf_s("%lf", &r1);
	printf_s("Enter resistance 2 (ohms)\n");
	scanf_s("%lf", &r2);
	printf_s("Enter voltage Vin (volts)\n");
	scanf_s("%lf", &vin);
	vout = calculate_resistive_divider(r1, r2, vin);//sends the resistance and input voltage values to the calculate_resistive_divider() function to calculate the output voltage
	printf_s("Vout = %.2lf\n_________________________\n", vout);//displays output voltage

	//Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2) 
	double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
	printf_s("Distance between two points: \nEnter first coordinates x and y\n");//prompts the user for two cartian coordinates (x1,y1) and (x2,y2)
	scanf_s("%lf%lf", &x1, &y1);
	printf_s("Enter second coordinates x and y\n");
	scanf_s("%lf%lf", &x2, &y2);
	distance = calculate_distance_between_2pts(x1, y1, x2, y2);//sends the two coordinates to the calculate_distance_between_2pts() function to calculate the distance between the two points
	printf_s("distance = %.2lf\n__________________________\n", distance);//displays the distance between the two given points

	//General equation: y = (89 / 27) - z * x + a / (a % 2) (recall: a is an integer; the 89 and 27 constants in the equation should be left as integers initially, but explicitly type-casted as floating-point values)*/
	double x = 0, z = 0, y = 0, a = 0;
	printf_s("General calculation: \nEnter z:\n");//prompts the user for the values of z, x and a for a general equation
	scanf_s("%lf", &z);
	printf_s("Enter x:\n");
	scanf_s("%lf", &x);
	printf_s("Input a:\n");
	scanf_s("%lf", &a);
	y = calculate_general_equation(z, x, a);//sends the three values to the calculate_general_equation() function to find the solution y
	printf_s("y = %.2lf\n_________________________\n", y);//displays general solution

	return 0;
}