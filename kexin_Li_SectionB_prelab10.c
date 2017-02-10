#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

/*
 * Parameters:
 * token - A string
 *
 * Return:
 * 1 if the string is a valid phone number,
 * 0 otherwise
 *
 * A valid phone number takes the form
 * (XXX)XXX-XXXX where X is a digit 0-9. 
 */
int isPhoneNumber(char* token);

int main(void) {
	//This is a valid phone number
	assert(isPhoneNumber("(123)456-7890") == 1);

	//These are not valid phone numbers
	assert(isPhoneNumber("123-456-7890")    == 0);
	assert(isPhoneNumber("1234567890")      == 0);
	assert(isPhoneNumber("(123) 456-7890") == 0);
	assert(isPhoneNumber("Hello World")     == 0);
	assert(isPhoneNumber("")				== 0);

	printf("Congratulations! You finsihed the prelab!");
	return 0;
}

int isPhoneNumber(char* token)
{
	int i;

	if('(' == *token && ')' == *(token+4) && '-' == *(token+8))
	{


	
		for( i = 1; i < 4; i++)
		{
			if(isdigit(*(token+i)!= 1))
			{
				return 0;
			}
		}

		for( i = 5; i < 8; i++)
		{
			if(isdigit(*(token+i)!= 1))
			{
				return 0;
			}
		}
		for( i = 9; i < 13; i++)
		{
			if(isdigit(*(token+i)!= 1))
			{
				return 0;
			}
		}
		return 1;


	}
	return 0;
}



