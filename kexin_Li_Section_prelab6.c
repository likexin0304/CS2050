#include <stdio.h>
#include <math.h>
/* prototype */
void display_option();
int check_option(int);
int check_year(int);
int check_amount(float);

void display_option()
{
	printf("Bank account type\n\n(1) Checking\n(2) Saving\n(3) Fixed Depoist\n");
}

int check_option(int option)
{
	if ( 0 < option && option < 4 ){
	  return 1;
	}
	else {
	  return 0;
	}
}

int check_year(int year)
{
	if ( 0 < year && year < 11 ){
	  return 1;
	}
	else {
	  return 0;
	}
}

int check_amount(float x)
{
	if ( 0 < x ){
	  return 1;
	}
	else {
	  return 0;
	}
}

int main()
{
  int option, year;
  float x, ia, ta, interest, rate;

	display_option();
	printf("Please make a selection:\n");
	scanf("%d", &option);

	while (check_option(option) == 0){
	display_option();
	printf("Please make a selection:\n");
	scanf("%d", &option);
	}

	printf("Enter a year:\n");
	scanf("%d", &year);

	while (check_year(year) == 0){
	printf("In correct value of year enter the year again:\n");
	scanf("%d", &year);
	}

	printf("Enter the amount:\n");
	scanf("%f", &x);

	while (check_amount(x) == 0){
	printf("Incorrect value enter the amount again:\n");
	scanf("%f", &x);
	}

	switch ( option ) {
	
	case 1:
	 rate =(float) 1 / 100;
         interest =(float) 1 + rate;
         ta =(float) x * pow(interest,year);
         ia =(float) ta - x;
	 /* print the anwser */
  	 printf("Total amount after %d years is $%.2f\n", year, ta);
  	 printf("Total interest earned on the amount $%.2f is $%.2f\n", x, ia);

  	 break;

	 case 2:
	 rate =(float) 3 / 100;
  	 interest =(float) 1 + rate;
  	 ta =(float) x * pow(interest,year);
  	 ia =(float) ta - x;

    	 printf("Total amount after %d years is $%.2f\n", year, ta); /* print the answer */
  	 printf("Total interest earned on the amount $%.2f is $%.2f\n", x, ia);

  	 break;

	 case 3:
	 rate =(float) 7 / 100;
  	 interest =(float) 1 + rate;
         ta =(float) x * pow(interest,year);
         ia =(float) ta - x;
/* print the answer */
  	 printf("Total amount after %d years is $%.2f\n", year, ta);
  	 printf("Total interest earned on the amount $%.2f is $%.2f\n", x, ia);

  	 break;
}
	return 0;
}










