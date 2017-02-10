//Name: KEXIN LI
//Pawprint: klft2
//Section: B
//Date: 2/22016
//Code: Winter is coming

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
        char *name;
        int rating;
        int numTimesPlayed;
} Song;
Song *readAlbum(const char *filename, int *lenPtr);
void printAlbum(Song *album, int len);
int changeRating(char *title, int rating, Song *album, int len);
int listenToSong(char *title, Song *album, int len);
void bubble_sort(Song *album, int len);

int main(int argc, char *argv[])
{
	int lenPtr;
	int choice;
	char *title;
	int rating;
	title = (char*)malloc(64);
	if (argc != 2)
	{
		printf("\n incorrect Usage\n");
		return 0;
	}
	
	Song *A = readAlbum(argv[1], &lenPtr);
	if ( A == 0)
	{
		printf("Failed to open file\n");
		return 0;
	}
		 printAlbum(A, lenPtr);

	//	printf("Enter 1 to listen to a song\nEnter 2 to change a rating\nEnter 0 to quit\n");
          //      scanf("%d",&choice);

	while ( choice != 0)
	{
	  	printf("Enter 1 to listen to a song\nEnter 2 to change a rating\nEnter 0 to quit\n");
                scanf("%d",&choice);
	
		if (choice == 2)
		{	
			printf("Enter a title:\n");
			scanf("%s", title);

			printf("Enter a new rating:\n");
			scanf("%d", &rating);
			changeRating(title, rating, A, lenPtr);
		}
		if (choice == 1)
		{
			printf("Enter a title:\n");
			scanf("%s", title);
			
		//	int B = listenToSong(title, A, lenPtr);	
		 	while(listenToSong(title, A, lenPtr)  == -1)
			{
				printf("Unable to find the %s\n", title);
				break;	
			}
	
		
			//	listenToSong(title, A, lenPtr);
			
		}
		
	}
	printAlbum(A, lenPtr);
	free(title);
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
int changeRating(char *title, int rating, Song *album, int len)
{
	int i;
	
	for ( i = 0; i < len; i++)
	{
		if( strcmp(title, (album+i)->name) == 0)
		{
			(album+i)->rating = rating;
			
			
			printf("%-2s%4d%8d\n", (album+i)->name, (album+i)->rating, (album+i)->numTimesPlayed);
			return i;
		}
			
		
	}
	return -1;
}
int listenToSong(char *title, Song *album, int len)
{
	int i;
	
	for( i = 0; i < len; i++)
	{
		if (strcmp(title, (album+i)->name) == 0)
		{
			//printf("%-2s%4d%8d\n", (album+i)->name, (album+i)->rating, (album+i)->numTimesPlayed);
			(album+i)->numTimesPlayed += 1;
			 printf("%-2s%4d%8d\n", (album+i)->name, (album+i)->rating, (album+i)->numTimesPlayed);

			return i;
		}
	//	printf("%-2s%4d%8d\n", (album+i)->name, (album+i)->rating, (album+i)->numTimesPlayed);
	}	
	return -1;
}



 
	

