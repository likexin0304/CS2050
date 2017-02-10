//Name: KEXIN LI
//Date:2/9/16
//Section: B
//pawprint: klft2
//Code: It's cold

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
        int id;
        char name[20];
        float gpa;
} Student;
Student findStudent(FILE *fp, int studentId);
Student *getClass(const char *classFile, const char *studentFile, int *len);
void bubbleSort(Student *students, int len);
void storeClass(const char *filename, Student *student, int len);
void printClass(Student *student, int len);

int main(int argc, char *argv[])
{
        if (argc != 4)
        {
                printf(" incorrect usage\n");
                return 0;
        }
        FILE *fp = fopen(argv[2], "rb");
	if (fp == NULL)
	{
		printf("cannot to open \n");
		return 0;
	}
	
	int len;
	
	Student * B = getClass(argv[1],argv[2], &len);
	
	//fclose(fp);	
	bubbleSort(B, len);
	
	storeClass(argv[3], B, len);
	
	printClass(B, len);
        

	

	fclose(fp);
        return 0;
}

Student findStudent(FILE *fp, int studentId)
{
        Student A;
        fseek(fp, (sizeof(Student)*(studentId-1)), SEEK_SET);
        fread(&A, sizeof(struct student), 1, fp);

        //printf("%-10d%-6s%14.2f\n", A.id, A.name, A.gpa);
        //fclose(fp);
        return A;
}

Student *getClass(const char *classFile, const char *studentFile, int *len)
{
	FILE *file = fopen(classFile, "r");
	if (file == NULL)
	{
		return 0;
	}
	FILE *file1 = fopen(studentFile, "rb+");
	if (file1 == NULL)
	{
		return 0;
	}
	
	fscanf(file, "%d", len);
	
	int i;
	
	Student *a = malloc(sizeof(Student)*(*len));
	Student s;
	for( i = 0; i < *len; i++)
	{


		fscanf(file, "%d", &s.id);
		fwrite(a,*len, i, file1);
		*(a+i) = findStudent(file1, s.id);
	}
	// *a = findStudent(file1, s.id);
	fclose(file);
	fclose(file1);

	return a;
}

void bubbleSort(Student *students, int len)
{
	int i, j;
	for ( i = 0; i < len - 1; i++)
	{
		for ( j = 0; j < len - 1 - i; j++)
		{
			if ( students[j].gpa > students[j+1].gpa )
			{
				Student temp = students[j+1];
				students[j+1] = students[j];
				students[j] = temp;
			}
		}
	}
	
}
void storeClass(const char *filename, Student *students, int len)
{
	int i;
	FILE *file2 = fopen(filename, "wb+");
	if (file2 == NULL)
	{
		return;
	}
	
	
	
		 fwrite(students, sizeof(Student), len, file2);
	//	 fprintf(file2, "%d%s%.2f\n", (students+i)->id, (students+i)->name, (students+i)->gpa);

	
	fclose(file2);
}

void printClass(Student *students, int len)
{
	int i;
	for ( i = 0; i < len; i++)
	{
		printf("%-2d%8s%16.2f\n", (students+i)->id, (students+i)->name, (students+i)->gpa);
	}
}



	
