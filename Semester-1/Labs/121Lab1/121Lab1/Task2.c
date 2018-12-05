/*******************************************************************************************
* Programmer: Freya Varez                                                                       *
* Class: CptS 121, Spring  2018; Lab Section 10L                                           *
* Programming Assignment: Lab1Task2                                                     *
* Date: January 16, 2018                                                                          *
* Description: User prompt      
*******************************************************************************************/
#include <stdio.h> // necessary to use printf () and scanf ()

int main(void) // the starting point for all C programs
{
	// we need to request memory for 
	int number1_int = 0, number2_int = 0, intSum = 0; // 2 variable declarations - reserves two memory blocks for integers and sets them to 0's
	double number1_float = 0.0, number2_float = 0.0, floatSum = 0; // reserves two memory blocks for numbers with precision (floating-point)

	printf("Enter two integer values: "); // ask the user
	scanf("%d%d", &number1_int, &number2_int); // read the integers typed through the keyboard - %d is for "decimal", i.e. integers

	printf("Enter two floating-point values: "); // ask the user
	scanf("%lf%lf", &number1_float, &number2_float); // read the integers typed through the keyboard - %lf is for "long float", i.e. double precision numbers

	printf("number1_int + number2_int = ");
	intSum = number1_int + number2_int;
	printf("%d\n\n", intSum);

	printf("number1_float - number2_float = ");
	floatSum = number1_float - number2_float;
	printf("%lf\n\n", floatSum);

	printf("number1_int * number1_float =");

	//Multiply number1_int by number1_float and print the result as an integer value
	//Divide number1_int by number2_int and print the result as an integer and a floating - point value(Ask yourself : What happens when you divide and integer by and integer ? Does the result change because you print it as a floating - point number ? )
	//Divide number1_int by number2_float and print the result as an integer and a floating - point value(Ask yourself : How does this compare to the previous operations ? We are now dealing with mixed data types.)
	//Explicitly cast number1_int as a floating - point value and divide by number2_int.Print the result as a floating - point value.
	//Try to mod number1_float by number2_float.Does the program compile ? If not, fix it so that it does.



									

	return 0; // return a success status (value 0) indicating the program worked fine
} // end of the main () function

	
