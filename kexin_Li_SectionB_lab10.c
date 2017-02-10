// Lab Code: Cucumber
//name: KEXIN LI
//Paw print: klft2
//Section; B


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isDate(char *token);
int isPhoneNumber(char* token);
int isEmail(char* token);
int isName(char*token);

int main(int argc, char*argv[])
{
	if( argc != 2)
	{
		printf("incorrect usage\n");
		return 0;
	}

	FILE *file = fopen(argv[1], "r");
	if(file == NULL)
	{
		return 0;
	}

	int i;
	char *data;
	data = (char*)malloc(64);

	char *buffer;
	buffer = (char*)malloc(256);

	char* temp = buffer;
	while(1){
		fscanf(file,"%c",buffer);
		if(feof(file)){
			break;	
		}
		buffer++;
	}

	buffer = temp;



	while(*buffer !='\0')
	{
		for( i = 0; i < 14; i++)
		{
			*(data+i) = *(buffer+i);

		}
		if(isPhoneNumber(data) == 1)
		{
			printf("Phone Number:%s\n",data);
			break;

		}
		buffer++;
	}

	rewind(file);


/*	while(*buffer !='\0')
	{
		for( i = 0; i < 11; i++)
		{
			*(data+i) = *(buffer+i);
		}
		if(isDate(data) == 1)
		{
			printf("Date: %s\n",data);
			break;
		}
		buffer++;
	}
*/

	rewind(file);

	while(*buffer !='\0')
	{
		for(i = 0; i < 18; i++)
		{
			*(data+i) = *(buffer+i);
		}
		if(isEmail(data) == 1)
		{
			printf("Email: %s\n",data);
			break;
		}
		buffer++;
	}
	rewind(file);
	printf("Bonus\n");
	rewind(file);

	while(*buffer !='\0')
	{
		for(i = 0; i < 13; i++)
		{
			*(data+i) = *(buffer+i);
		}
		if(isName(data) == 1)
		{
			printf("Full Name:%s\n", data);
			break;
		}
		buffer++;
	}

	fclose(file);

	return 0;




}


int isDate(char* token)
{
/*
	if(token[2] == '/' && token[5] == '/')
		if(token[6] == '2'&& token[7]>47 && token[7] < 58 && token[8] > 47 && token[8] <58 && token[9]>47 && token[9] <58)
			if((token[3] == '0' && token[4] > 47 && token[4] <58 )|| (token[3] =  '1'&& token[4] > 47 && token[4] < 51)){
				
				printf("month okay\n");
				if((token[3] =='0' && (token[4] == '1' || token[4] == '3' ||  token[4] == '5'  || token[4] == '7'  || token[4] == '8'  ))||( token[3] =='1' &&(token[4] == '0'  || token[4] == '2')))
				{
					printf("1 3 5 7 8 10 12  okay\n");
					if(token[0]>47 && token[0]<51)
						if(token[1]>47 && token[1]<58)
							return 1;
					if(token[0] == '3'&& (token[4] == '0'|| token[4] == '1'))
						return 1;
				}	
				 
				if((token[3] == '0'&&(token[4]=='4'||token[4] == '6'||token[4] == '9'))||(token[3] =='1'&& token[4] == '1'))
				{
					if(token[0]>47 && token[0]<51)
						if(token[1]>47 && token[1]<58)
							return 1;
					if(token[0] == '3'&& token[4] == '0')
						return 1;
				}
				
				if(token[3] == '0' && token[4]== '2'){
					int year = (token[6]-48)*1000 + (token[7]-48)*100 + (token[8]-48)*10 + (token[9]-48)*1;
					if((year%4 == 0 && year%100 != 0)||(year%400 == 0)){

						if(token[0]>47 && token[0]<51)
							if(token[1]>47 && token[1]<58)
								return 1;
					}
					else{

						if(token[0]>47 && token[0]<50)
							if(token[1]>47 && token[1]<58)
								return 1;
						if(token[0] == '2')
*/
	if(strlen(token) !=10)
	{
		return 0;
	}
	if(*(token+2) != '/' || *(token+5) !='/')
	{
		return 0;
	}
	int month = atoi(token);
	int day = atoi(token+3);
	int year = atoi(token+5);
	if( month < 1 || month >12 || day < 1 || day > 31 || year <2000)
	{
		return 0;
	}
	if( month == 2)
	{
		if(year / 4 ==0)
		{
			if(day > 29)
			{
				return 0;
			}
		}
		else
		{
			if(day > 28)
			{
				return 0;
			}
		}
	}
	if((month == 4 || month == 6 || month == 9 || month ==11) &&day > 30)
	{
		return 0;
	}
	return 1;

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

int isEmail(char *token)
{
	int i;

	if( '@' == *(token+4) && '.' == *(token+13)  && 'c' == *(token+14) && 'o' == *(token+15) && 'm' == *(token+16))
	{
		for( i = 0; i < 4; i++)
		{
			if(isdigit(*(token+i)!= 1))
			{
				return 0;
			}
		}
		for( i = 5; i <  13; i++)
		{
			if( islower(*(token+i) != 1))
			{
				return 0;
			}
		}

		return 1;
	}
	return 0;
}
/*int isName(char *token)
{
	int i;
	char *temp;
	temp = "Seth Wiesman";
	//char *string = temp;
	
//	int a;
	for( i = 0; i < 12; i++)
	{
		if(strcmp((token+i),(temp+i)) == 0)
		{
			return 1;
		}
		
	}
	return 0;
		 
}
*/
int isName(char *token)
{
	int len = strlen(token);

	if(len < 3)
		return 0;

	if(!isupper(token[0]))
		return 0;

	if(strchr(token, ' ') == NULL)
		return 0;

	int i = 1;

	for(; i < len; i++)
	{
		if(token[i] == ' ')
		{
			 
			if(i == len-1)
				return 0;

			
			else if(!isupper(token[i+1]))
				return 0;

			i++;
		}
		else
		{

			if(!islower(token[i]))
				return 0;
		}
	}

	return 1;
}



