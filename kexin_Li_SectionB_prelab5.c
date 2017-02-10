#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {
	PENNY   = 1,
	NICKEL  = 5,
	DIME    = 10,
	QUARTER = 25,
} Denomination;

typedef struct {
	Denomination denomination;
	int quantity;
} Coin;
typedef Coin * PiggyBank;

PiggyBank loadBank(const char *filename, int *lenPtr);
int totalMoney(PiggyBank bank, int length);

int main(int argc, char *argv[])
{
	int *lenPtr;
	
	if( argc != 2)
	{
		printf("Incorrect usage\n");
		return 0;
	}
	PiggyBank A = loadBank(argv[1], lenPtr);
	if( A == 0)
	{
		printf("Failed to open file\n");
		return 0;
	}
	int sum = totalMoney(A, *lenPtr);
	printf("You have %d cents\n", sum);
	free(A);	
	return 0;
}

PiggyBank loadBank(const char *filename, int *lenPtr)
{
	int i;
	FILE *file = fopen(filename, "r");
	if( file == NULL)
	{
		return 0;
	}
	fscanf(file, "%d", lenPtr);
	PiggyBank A = malloc(sizeof(Coin)*(*lenPtr));
	
	for ( i = 0; i < *lenPtr; i++)
	{
		fscanf(file, "%u %d", &A[i].denomination, &A[i].quantity);
	}
	
	//return A;
	fclose(file);		
	return A;
}

int totalMoney(PiggyBank bank, int length)
{
	int p, n, d, q, sum;
	int i;
	
	for(i = 0; i < length; i++)
	{
		if(bank[i].denomination == 1) 
		{
			p = (bank[i].denomination) * (bank[i].quantity);
		}
		
		if(bank[i].denomination == 5)
                {
                        n = (bank[i].denomination) * (bank[i].quantity);
                }


		if(bank[i].denomination == 10)
                {
                        d = (bank[i].denomination) * (bank[i].quantity);
                }
		
		if(bank[i].denomination == 25)
                {
                        q = (bank[i].denomination) * (bank[i].quantity);
                }
		
	}
		sum = p + n + d + q;
		return sum;	
}
