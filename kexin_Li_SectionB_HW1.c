//Name: KEXIN LI
//Section: B
//Pawprint: klft2

//don't add to this list. You won't need anything else.
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//for expandable use.
#define NUMHEROES 6
#define NUMCHOSENHEROES 3
#define MAXNUMSAVEFILES 5
#define MAXPLAYERNAME 20

//for locating the save file
typedef enum f_
{
        EXIST,
        DOESNOTEXIST
} FileFinder;

//MVP OF THE HOMEWORK
//Mostly self-expalanatory pieces.
typedef struct hero_
{
        char name[40];
        int health;
        int baseDefense;
        int baseAttack;
        int baseSpeed;
} Hero;

//Not used in this HW, just defined to prep for later HWs
typedef struct boss_
{
        char name[40];
        int health;
        int maxHealth;
        int baseDefense;
        int baseAttack;
        int baseSpeed;
} Boss;


//THAT'S A LOT OF FUNCTIONS. GET EXCITED.
void deleteFile(int choice, char* filename);
void saveFileData(int choice, char* filename, Hero* heroes, char* playerName, int progress);
char* getPlayerName();
Hero* loadSavedData(char* filename);
Hero* loadInitialData();
Hero* pickHeroes(Hero* heroes);
void sortHeroes(Hero* heroes);
void printHeroes(Hero* heroes, int numHeroes);
//The following ones are all done for you. Just call them as instructed.
FileFinder findSaveFile();
void loadSavedGameHandler();
void DeleteSavedGameHandler();
void loadGameStateData(char*** names, int** states, int* fileCount);
char* choiceToFile(int num);
void freeMemory(char** names, int* states);
void startNewGame();
void playGame(Hero* heroes, char* playerName, Boss* boss, int progress, int choice);
int chooseSaveFile();

int main(void)
{
	
	
	findSaveFile();
	
	int select;
        
        
            printf("Welcome to the Gauntlet!\n Select your option.\n 1:start a new game\n 2:quit\n");
            printf(">");
            scanf("%d", &select);
            while(select != 1 && select != 2)
            {
                printf("Invaild option. Try again:\n");
                printf(">");
                scanf("%d", &select);
            }
	    if(select == 1)
	{
		 startNewGame();
	}
	else
	{	
		 exit(0); 
	}

        
	 
        
	
	
        	printf("1 Start a new game\n");
        	printf("2 Start a saved game\n");
        	printf("3 Delete a saved file\n");
        	printf("4 Quit\n");
        	scanf("%d",&select);
	 
	 while(select != 1 && select != 2 && select != 3 && select != 4)      
         {  	printf("Invaild option. Try again:\n");
            	printf(">");
            	scanf("%d",&select);
         }

       // int choice;
        switch(select)
	{
        
	    case 1: startNewGame();break;
            case 2: loadSavedGameHandler();break;
            case 3: DeleteSavedGameHandler();break;
            case 4: exit(1);break;
        }
    
	//while(select == 4);
	
	return 0;
}

void deleteFile(int choice, char* filename)
{
    FILE *fp = fopen("gamestate.txt", "r+");
    if(fp == NULL)
    {
        
        printf("Unable to open\n");
	exit(1);    
    }
   
    char n[5][40];
    int x, value[5], i;
 
    remove(filename);   
    fscanf(fp, "%d", &x);
    
    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s | %d", n[i], &value[i]);
    }
    
    strcpy(n[choice - 1], "000");
    value[choice - 1] = 0;
    x--;
    rewind(fp);
   // flcose(fp);
   // FILE *ptr = fopen("gamestate.txt", "w");
    
    fprintf(fp, "%d\n", x);
    
    for( i = 0; i < 5; i++)
    {
        fprintf(fp, "%s | %d\n", n[i], value[i]);
    }
    fclose(fp);
    printf("file has been deleted\n");

}

void saveFileData(int choice, char* filename, Hero* heroes, char* playerName, int progress)
{
	FILE *fp = fopen("gamestate.txt", "r+");
    	if( fp == NULL)
    	{
        	printf("cannot to open this file\n");
    
    	}
    	char name[5][40];
    	int x[5], number;
	int i;    
    	switch(progress)
    	{
        	case 1:
        	{
            		
            		fscanf(fp, "%d", &number);
            		for( i = 0; i < 5; i++)
            		{
                		fscanf(fp, "%s | %d", name[i], &x[i]);
            		}
            		strcpy(name[choice -1], playerName);
            		x[choice -1] = progress;
            		number++;
            		fprintf(fp, "%d\n", number);
            		for(i = 0; i < 5; i++)
            		{
                		fprintf(fp, "%s | %d\n", name[i], x[i]);
            		}
            		fclose(fp);
            		break;
        	}


		case 2:
        	{
            	
            		fscanf(fp,"%d",&number);
            		for (i = 0; i < 5;i++)
			{
                		fscanf(fp,"%s | %d",name[i],&x[i]);
            		}
           		strcpy(name[choice-1],playerName);
            
           		x[choice-1]= progress;
            		number++;
            		fclose(fp);
            
            		FILE* Fp = fopen("gamestate.txt", "w");
            
            		fprintf(Fp,"%d\n",number);
            
            		for(i = 0; i < 5; i++)
            		{
                		fprintf(Fp,"%s | %d\n",name[i],x[i]);
            		}
            		fclose(Fp);
            		FILE *ptr = fopen(filename,"w");
		
            		for( i = 0; i < 3; i++)
            		{
                		fprintf(ptr,"%s | %d | %d | %d | %d\n",(heroes+i)->name,(heroes+i)->health,(heroes+i)->baseDefense,(heroes+i)->baseAttack,(heroes+i)->baseSpeed);
            		}
            		fclose(ptr);
        	}
    	}
}

char* getPlayerName()
{
 	char *name;
        name = malloc(sizeof(char)*256);

        printf("Please input your name:\n");
        scanf("%s", name);

        return name;

}

Hero* loadSavedData(char* filename)
{
	Hero *B = malloc(sizeof(Hero)* NUMCHOSENHEROES);
	int i;
    	FILE *file1 = fopen(filename, "r");
    	if(file1 == NULL)
    	{
        	printf("cannnot to open this file\n");
        	exit(1);
    	}
    //	Hero *B = malloc(sizeof(Hero)*3);
    	for ( i = 0; i < NUMCHOSENHEROES; i++)
    	{
        	//A[i].name = (char*)malloc(64);
        	fscanf(file1, "%s | %d | %d | %d | %d", (B+i)->name, &(B+i)->health,  &(B+i)->baseDefense,  &(B+i)->baseAttack,  &(B+i)->baseSpeed);
    	}
    
   	 fclose(file1);
    	return B;
}

Hero* loadInitialData()
{
	Hero *A = malloc(sizeof(Hero)*6);
	int i;
	FILE *file = fopen("Heroes.txt", "r");
	if (file == NULL)
	{
		printf("cannot to open this file\n");
		return 0;
	}
//	Hero *A = malloc(sizeof(Hero)*6);
	
	for ( i = 0; i < 6; i++)
	{
	//	(A+i)->name = (char*)malloc(64);
		fscanf(file, "%s | %d | %d | %d | %d", (A+i)->name, &(A+i)->health,  &(A+i)->baseDefense,  &(A+i)->baseAttack,  &(A+i)->baseSpeed);
	}
	fclose(file);
	return A;
}


Hero* pickHeroes(Hero* heroes)
{
	
    	Hero * A = malloc(sizeof(Hero)* NUMCHOSENHEROES);
   
    	int first, second, third;// every one is a hero
    
    	sortHeroes(heroes);
    	
	printHeroes(heroes, NUMHEROES);
	
	printf("Please pick a hero:");
	scanf("%d", &first);
    	// first hero
    	while (first < 1 || first > 6)
    	{
        	printf("Invalid choice. Please pick a valid hero option:");
        	scanf("%d", &first);
    	}
    	
//	A = heroes + first;
    	
	A[0] = heroes[first -1];
    
    	printf("Excellent choice. Hero saved\n");
 
    	// pick second hero
    	printf("Please pick another hero:");
    	scanf("%d", &second);
    
	while(second > 6 || second < 1)
    	{
        	printf("Invalid choice. Please pick a valid hero option");
        	scanf("%d", &second);
    	}
    	while(second == first)
    	{
        	printf("Invalid choice. Please pick a valid hero option");
        	scanf("%d", &second);
    	}
  //  	A = heroes + second;
    
	 A[1] = heroes[second - 1];
    
    	printf("Excellent choice. Hero saved\n");
    
    	//pick third hero
        printf("Please prick another hero:");
    	scanf("%d", &third);
    	while(third > 6 || third < 1)
    	{
        	printf("Invalid choice. Please pick a valid hero option");
        	scanf("%d", &third);
    	}
    	while(third == first || third == second)
    	{
        	printf("Invalid choice. Please pick a valid hero option");
        	scanf("%d", &third);
    	}
   
	 A[2] = heroes[third - 1];
    	printf("Excellent choice. Hero saved\n");
    	// already picked three heroes.
    
    //	printHeroes(A, NUMCHOSENHEROES);
    	
    	return A;
	
}

void sortHeroes(Hero* heroes)
{
	int i, j, min_index;
    
    	for ( i = 0; i < NUMHEROES - 1; i++)
    	{
        	min_index = i;
        	for(j = i+1; j < NUMHEROES; j++)
        	{
            		if(strcmp(heroes[min_index].name, heroes[j].name) > 0)
            		{
                		min_index = j;
                
            		}
        	}
        	if( min_index != i)
        	{
			Hero *temp = (Hero*)malloc(sizeof(Hero));
            		*temp = heroes[i];
            		heroes[i] = heroes[min_index];
            		heroes[min_index] = *temp;
			free(temp);
        	}
    	}
	
}

void printHeroes(Hero* heroes, int numHeroes)
{
	int i;
    	for(i = 0; i < numHeroes; i++)
    	{
        	printf("%d:%s\n Health: %d\n Defense: %d\n Attack: %d\n Speed: %d\n", (i + 1), (heroes+i)->name, (heroes+i)->health, (heroes+i)->baseDefense, (heroes+i)->baseAttack, (heroes+i)->baseSpeed );
	}

}



/***************************************START OF FUNCTIONS GIVEN TO YOU*********************************************************************/
FileFinder findSaveFile()
{
        printf("Checking save file...\n\n");
        //This should exist. Make sure the file is with your HW.
        FILE* fp = fopen("gamestate.txt", "r");
        if(!fp)
        {
                //You will have to debug this...it could be for a variety of reasons.
                perror("gamestate.txt read error");
                exit(1);
        }

        int numFiles;

        //read the number of save file slots that are taken up, and
        //interpret accordingly.
        if(fscanf(fp, "%d", &numFiles) < 1)
        {
                printf("gamestate.txt: failed to read number of save files. Check input file.\n");
                exit(1);
        }

        FileFinder f;
        if (numFiles == 0)
        {

                f = DOESNOTEXIST;
        }
        else
        {
                f = EXIST;
        }

        fclose(fp);

        printf("Check complete.\n\n");
        return f;
}


void loadSavedGameHandler()
{
        //initial load of all data that might be needed.
        char** names;
        int* states;
        int numFiles;
        int choice;

        loadGameStateData(&names, &states, &numFiles);

        while(1)
        {
                printf("\nChoose a file you would like to load: \n");
                printf("(-1 to return to main menu)\n");
                printf(">");
                scanf("%d", &choice);
                while((choice < 1 || choice > MAXNUMSAVEFILES) && choice != -1)
                {
                        printf("Invalid choice. Please choose a different option:\n ");
                        printf(">");
                        scanf("%d", &choice);

                }

                if(choice == -1)
                {
                        freeMemory(names, states);
                        return;
                }

                if(states[choice-1] == 0)
                {
                        printf("There is no saved file present in this slot.\n");
                }
                else
                {
                        //From here, a valid saved file has been selected, so we need to interpret where
                        //the save file is in terms of game progression. This way we know what data to load

                        //the state value will never be anything other than 0, 1, or 2.
                        if(states[choice-1] == 1)
                        {
                                //Heroes have not been selected yet.
                                playGame(loadInitialData(), names[choice-1], NULL, states[choice-1], choice);
                        }
                        else
                        {
                                //Heroes have already been selected.
                                Hero* heroes = loadSavedData(choiceToFile(choice-1));
                                if(!heroes)
                                {
                                        printf("Failed to load heroes. Exiting...\n");
                                        freeMemory(names, states);
                                        exit(1);
                                }
                                playGame(heroes, names[choice-1], NULL, states[choice-1], choice);
                        }

                        freeMemory(names, states);
                        return;
                }
        }
}


void DeleteSavedGameHandler()
{

        //Everything in this file is almost identical to the function above, just different ending actions.
        //Could move a lot of this to its own function, but eh
        char** names;
        int* states;
        int numFiles;
        int flag = 0;
        int choice = -1;

        while (1)
        {
                //Small optimization. If we didn't delete a file, we don't have to reload the data
                //since nothing changed.
                if(flag == 0)
                {
                        //to cover the first time the loop goes through.
                        //Can't free if nothing's been loaded yet.
                        if(choice != -1)
                        {
                                freeMemory(names, states);
                        }
                        loadGameStateData(&names, &states, &numFiles);
                }

                printf("\nChoose a file you would like to delete: \n");
                printf("(-1 to return to main menu)\n");
                printf(">");
                scanf("%d", &choice);
                while((choice < 1 || choice > MAXNUMSAVEFILES) && choice != -1)
                {
                        printf("Invalid choice. Please choose a different option:\n ");
                        printf(">");
                        scanf("%d", &choice);
                }

                if(choice == -1)
                {
                        //This is the only way to get out of this function.
                        freeMemory(names, states);
                        return;
                }

                if(states[choice-1] == 0)
                {
                        //shouldn't get here, but just in case.
                        //can't get here because the numFiles controls what's
                        //a valid value for chioce.
                        printf("There is no saved file present in this slot.\n");
                        flag = 1;
                }
                else
                {
                        deleteFile(choice, choiceToFile(choice-1));
                        flag = 0;
                }
        }
}


void loadGameStateData(char*** names, int** states, int* fileCount)
{
        printf("\n\n");
        //All memory is allocated here, and once the data is loaded
        //The variables passed by reference into this function will be set up.
        char** n = malloc(sizeof(char*)*MAXNUMSAVEFILES);
        int i;
        for(i = 0; i < MAXNUMSAVEFILES; i++)
        {
                n[i] = malloc(sizeof(char)*MAXPLAYERNAME);
        }

        int* s = malloc(sizeof(int)*MAXNUMSAVEFILES);

        //again, should not fail.
        FILE* fp = fopen("gamestate.txt", "r");
        if(!fp)
        {
                perror("gamestate.txt");
                freeMemory(n, s);
                exit(1);
        }

        int numFiles;
        if(fscanf(fp, "%d", &numFiles) < 1)
        {
                printf("gamestate.txt: could not read the number of save files. Check input file.\n");
                freeMemory(n,s);
                exit(1);
        }
        //Load all the data, interpret the data, and print to the user what
        //was found in the list of save file slots.
        for(i = 0; i < MAXNUMSAVEFILES; i++)
        {
                if(fscanf(fp, "%s | %d", n[i], &s[i]) < 2)
                {
                        printf("gamestate.txt: could not read save file data #%d. Check input file.\n", i+1);
                        freeMemory(n,s);
                        exit(1);
                }
                //NOTE: everything shown to the user is for human readability.
                //Stuff starts at 1, but internally stuff still starts at 0.
                switch(s[i])
                {
                        case 0:
                                printf("%d: [No File Present]\n", i+1);
                                break;
                        case 1:
                                printf("%d: %s - ", i+1, n[i]);
                                printf("Heroes have not been selected.\n");
                                break;
                        case 2:
                                printf("%d: %s - ", i+1, n[i]);
                                printf("Heroes have been selected.\n");
                                break;
                }
        }

        fclose(fp);
        //complete the links after everything is loaded.
        *names = n;
        *states = s;
        *fileCount = numFiles;
}

char* choiceToFile(int num)
{
        switch(num)
        {
                case 0: return "file1.txt"; break;
                case 1: return "file2.txt"; break;
                case 2: return "file3.txt"; break;
                case 3: return "file4.txt"; break;
                case 4: return "file5.txt"; break;
                default:
                        printf("Something happened with the save file choice. See Daniel.\n");
                        exit(1); break;
        }
}

void freeMemory(char** names, int* states)
{
        int i;
        //seg faults? Check input file/gdb.
        for(i = 0; i < MAXNUMSAVEFILES; i++)
        {
                free(names[i]);
        }
        free(names);
        free(states);
}

void startNewGame()
{
        //I don't think anything else needs to be here?
        Hero* heroes = loadInitialData();
        //doesn't matter what the value of choice is, since progress = 0 means get a choice value first.
        playGame(heroes, NULL, NULL, 0, -1);
}

void playGame(Hero* heroes, char* playerName, Boss* boss, int progress, int choice)
{

        //Added flavor
        if(progress > 0)
        {
                printf("\nWelcome back %s.\n\n", playerName);
        }

        //holds what the last thing done was.
        int initialprogress = progress;

        Hero* chosenHeroes = NULL;

        //another check for how the data is laid out. This is so we can immediately print out
        //heroes if we have already selected heroes.
        if(progress > 1)
        {
                chosenHeroes = heroes;
        }

        switch(progress)
        {
                //initial player identification
                case 0:
                        playerName = getPlayerName();
                        choice = chooseSaveFile();
                        saveFileData(choice, choiceToFile(choice-1), NULL, playerName, 1);
                //hero selection
                case 1:
                        chosenHeroes = pickHeroes(heroes);
                        saveFileData(choice, choiceToFile(choice-1), chosenHeroes, playerName, 2);
                        free(heroes);
                //equip heroes with items
                case 2:
                        //shop
                        printHeroes(chosenHeroes, NUMCHOSENHEROES);
                        free(chosenHeroes);
                        //should never be past this point, so stop the pitfalling here.
                        break;
                //fight the boss (a boss? Maybe find some way to get more than one boss in there?)
                case 3:
                        //fight
                        printf("Why is progree value 3? It should not be here yet.\n");
                default:
                        //What?
                        printf("Something fatal happened with the progress value. Check gamestate.txt.\n");
                        break;
        }

        printf("\n\n**********Until Next Homework!*************\n\n");

        //I don't actually remember why I did this, but it works.
        //I think because if it's a save file, it's freed elsewhere?
        if(initialprogress == 0)
        {
                free(playerName);
        }
        return;
}

int chooseSaveFile()
{
        //Initial load for data management.
        char** names;
        int* states;
        int numFiles;
        int choice;
        int confirm = 1;

        loadGameStateData(&names, &states, &numFiles);

        //Get a chosen file slot to save to. The file slot must be valid, and
        //old files can be overriden.
        while(1)
        {
                confirm = 1;
                printf("\nChoose a file you would like to save to: \n");
                printf(">");
                scanf("%d", &choice);
                while((choice < 1 || choice > MAXNUMSAVEFILES))
                {
                        printf("Invalid choice. Please choose a different option:\n ");
                        printf(">");
                        scanf("%d", &choice);
                }

                if(states[choice-1] != 0)
                {
                        printf("There is a file here. Would you like to override it? (1 = yes, 0 = no)\n");
                        printf(">");
                        scanf("%d", &confirm);
                        while(confirm != 1 && confirm != 0)
                        {
                                printf("Invalid choice. Please choose a different option:\n ");
                                printf(">");
                                scanf("%d", &confirm);
                        }
                }

                if(confirm == 1)
                {
                        //Go ahead and delete the old hero file immediately if there is one.
                        if(states[choice-1] == 2)
                        {
                                deleteFile(choice, choiceToFile(choice-1));
                        }
                        freeMemory(names, states);
                        //I haven't found a bug yet with the state = 1, but there might be one somewhere.
                        return choice;
                }
        }
}


