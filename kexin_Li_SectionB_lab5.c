//Name: KEXIn LI
//Section: B
//Pawprint: klft2
//Code: Pink Dragon

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
char *enumToString(Denomination denomination);
int totalMoney(PiggyBank bank, int length);
void printBankToScreen(PiggyBank bank, int length);
void sortByQuantity(PiggyBank bank, int length);
void writeToFile(const char *filename, PiggyBank bank, int length);
PiggyBank minimumChange(int amount);
int main(int argc, char *argv[])
{
	int lenPtr;
	int x;
	
	 if( argc != 3)
        {
                printf("Incorrect usage\n");
                return 0;
        }
	PiggyBank A = loadBank(argv[1], &lenPtr);
	if(A == 0)
	{
		printf("Failed to open file\n");
		return 0;
	}
	
	printBankToScreen(A, lenPtr);
	sortByQuantity(A, lenPtr);
	writeToFile(argv[2], A, lenPtr);
	free(A);
	
	printf("BONUS:\nEnter an amount of change\n");
        scanf("%d", &x);

//	PiggyBank minimumChange(x); 
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

char *enumToString(Denomination denomination)
{
/*		char *string = malloc(sizeof(char)*128);
		if(denomination == PENNY)
		{
			string = "penny";
			return string;
		}
		 if(denomination == NICKEL)
                {
                        string = "nickel";
                        return string;
                }
		 if(denomination == DIME)
                {
                        string = "dime";
                        return string;
                }
		 if(denomination == QUARTER)
                {
                        string = "quarter";
                        return string;
                }
*/	
	switch(denomination)
		{
			case PENNY :return "penny";
			case NICKEL: return "nickel";
			case DIME: return "dime";
			case QUARTER: return "quarter";
		}
	
	return NULL; 
	
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

void printBankToScreen(PiggyBank bank, int length)
{
	int i, sum;
//	Denomination denomination;
	sum = totalMoney(bank, length);
	
	char **string = malloc(sizeof(char*)*length); 
	//ring = enumToString(denomination);
	
	printf("You have %d cents in your piggy bank\n", sum);	
	
	for( i = 0; i < length; i++)
	{
		*(string+i) = enumToString((bank+i)->denomination);
		printf("%s %d\n",*(string+i),(bank+i)->quantity);
	}

}
void sortByQuantity(PiggyBank bank, int length)
{
	int i;
	
	for(i = 0; i < length; i++)
	{
		int j = i;
		while(j > 0 && bank[j].quantity < bank[j-1].quantity)
		{
			Coin temp = bank[j];
			bank[j] = bank[j-1];
			bank[j-1] = temp;
			j--;
		}
	} 

}

void writeToFile(const char *filename, PiggyBank bank, int length)
{
	FILE *fp = fopen(filename, "w");
	if (fp == NULL)
	{
		return ;
	}
	fprintf(fp,"%d\n", length);
	int i;
	for( i = 0; i < length; i++)
	{
		fprintf(fp, "%d %d\n", bank[i].denomination, bank[i].quantity);
	}
	fclose(fp);
}

PiggyBank minimumChange(int amount)
{
//	printf("Enter an amount of change;\n");
//	scanf("%d", &amount);
	int quarter, dime, nickel, penny;
	quarter = amount / 25;
	dime = (amount - quarter) / 10;
	nickel = (amount - quarter - dime) /5;
	penny = (amount - quarter - dime - nickel)/ 5;



	printf("%d cents can be made with:\n%d quarter's\n%d dime's\n%d nickel's\n%d penny's\n", amount, quarter, dime, nickel, penny);
	
	return NULL;
}


























