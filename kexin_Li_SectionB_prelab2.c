#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAMESIZE 20
typedef struct song {
	char *name;
	int rating;
	int numTimesPlayed;
} Song;

Song *readAlbum(const char *filename, int *lenPtr);
void printAlbum(Song *album, int len);
int main(int argc, char *argv[])
{
	int lenPtr;
		
	
	if (argc != 2)
	{
		printf("\n incorrect Usage\n");
		return 0;
	}
	
	
/*	if ( readAlbum(argv[1], &lenPtr) == 0)
	{
		printf("Failed to open file\n");
		return 0;
	}
*/	
	Song *A = readAlbum(argv[1], &lenPtr);

	if ( A == 0)
	{
		printf("Failded to open file\n");
		return 0;
	}			
	printAlbum(A, lenPtr);
	free(A);
	return 0;
}

Song *readAlbum(const char *filename, int *lenPtr)
{
	
	int i;
	

	FILE *file = fopen(filename, "r");
	if( file == NULL)
	{
		return 0;
	}
	
		
	fscanf(file,"%d", lenPtr);
	//printf("%d\n", *lenPtr);	
	Song *A = malloc(sizeof(Song)*(*lenPtr));
	
	for ( i = 0; i < *lenPtr; i++)
	{
		(A+i)->name = (char*)malloc(64);
		fscanf(file,"%s%2d%4d",(A+i)->name, &(A+i)->rating, &(A+i)->numTimesPlayed);
	}
	
	fclose(file);
	
	return A;	
}
void printAlbum(Song *album, int len)
{

	int i;
	for (i = 0; i < len; i++)
	{
		printf("%-2s%4d%8d\n", (album+i)->name, (album+i)->rating, (album+i)->numTimesPlayed);
	}
}
