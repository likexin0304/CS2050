//Name: kexin Li
//Lab Code: Bad wolf
//Pawprint: klft2
//Lab Section: B
//Lab : 1
//Date:1/26/16

#include <stdio.h>
#include <stdlib.h>

double *read_file(char *filename, int length);
double find_min (double *array, int length);
double find_max (double *array, int length);
double find_max (double *array, int length);
double find_avg (double *array, int length);
void write_to_file (char *filename, double *array, int length);

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("\n incorrect Usage\n./a.out <file length> <input file> <output file>\n");
		return 0;
	}
	
	int n = atoi(argv[1]);
	double *Array = read_file(argv[2], n);

	if (Array == 0)
	{
		printf("Unable to open file %s\n", argv[2]);
		return 0;
	}
	
	printf("min:%0.7f\n", find_min(Array, n));
	printf("max:%0.7f\n", find_max(Array, n));
	printf("avg:%0.7f\n", find_avg(Array, n));
	
	write_to_file(argv[3], Array, n);
	return 0;
	

}


double *read_file(char *filename, int length)
{
	int i;
	double *number = malloc(sizeof(double)*length);

	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		return 0;
	}
	for (i = 0; i < length; i++)
	{
		fscanf(file, "%lf", (number + i));
	}
	
	fclose(file);
		
	return number;
}

	
double find_min(double *array, int length)
{
	int i;
	double min = 999999;
	double on;
	for (i = 0; i < length; i++)
	{
		if (min > *(array + i))
		{
			min = *(array + i);
			on = *(array + i);
		}
				
	}
	return on;
}

double find_max(double *array, int length)
{
	int i; 
	double max = -999999;
	double on;
	for (i = 0; i < length; i++)
	{
		if ( max < *(array + i))
		{
			max = *(array + i);
			on = *(array + i);
		}
	}
	return on;
}

double find_avg(double *array, int length)
{
	int i;
	double average = 0;
	for (i = 0; i < length; i++)
	{
		average+=*(array + i);
	}
	average/=length;
	return average;
}

void write_to_file(char *filename, double *array, int length)
{
	int i;
	FILE *fp;
	
	fp = fopen(filename, "w");
	if (fp == NULL)
	{
		printf("Fail to open\n");
		return;
	}
	for (i = length - 1; i >= 0; i--)
	{
		fprintf(fp,"%lf\n", *(array + i ));
	}
	fclose(fp);
}
