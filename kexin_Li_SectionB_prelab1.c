#include <stdlib.h>
#include <stdio.h>

int *read_file(char *filename, int len);
void print_array(int *array, int len);

int main(int argc, char *argv[])
{
	
	
	if (argc != 3)
	{
		printf("\n Insufficient arguments \n");
		return 0;
	}

	int n = atoi(argv[1]);
	int *Array = read_file(argv[2], n);
	
	read_file(argv[2], n);
	print_array(Array, n);
	

	return 0;
}

int *read_file(char *filename, int len)
{
	int i;
	int *number = malloc(sizeof(int)*len);
	
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	for (i = 0; i < len; i++)
	{
		fscanf(file, "%d", (number + i));
	}
	fclose(file);
	return number;
}
void print_array(int *array, int len)
{
	int i;
 	
	
	for(i = 0; i < len; i++)
	{
		printf("%-2d", *(array + i));
	}
	printf("\n");
}

