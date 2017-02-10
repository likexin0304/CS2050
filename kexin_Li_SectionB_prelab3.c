#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
        int id;
        char name[20];
        float gpa;
} Student;
Student findStudent(FILE *fp, int studentId);
int main(int argc, char *argv[])
{
        if (argc != 2)
        {
                printf(" incorrect usage\n");
                return 0;
        }
        FILE *fp = fopen(argv[1], "rb");
        if (fp == NULL)
        {
                printf("File was not opened\n");
                return 0;
        }

	int i;
	for ( i = 49; i < 61; i+=5)
	{
        	findStudent(fp, i);
	}
	
	fclose(fp);
        return 0;
}

Student findStudent(FILE *fp, int studentId)
{
        Student A; 
        fseek(fp, (sizeof(Student)*(studentId-1)), SEEK_SET);
        fread(&A, sizeof(struct student), 1, fp);

        printf("%-2d%10s%16lf\n", A.id, A.name, A.gpa);
        //fclose(fp);
        return A;
}            
