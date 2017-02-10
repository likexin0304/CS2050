#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef struct node_ {
    int data;
    struct node_* next;
} Node;
Node* build_list(const char* filename);
void free_list(Node* head);
void print_list(Node* head);
void multiply_by(Node *head, int val);
Node* reverse_list(Node* head);
int main(int argc, char *argv[])
{
	int x;
	if(argc != 2)
	{
		printf("Incorrect usage\n");
                return 0;
        }
	Node *A = build_list(argv[1]);
	
	print_list(A);
	
	printf("Enter a number to multiply by:");
	scanf("%d", &x);
	
	multiply_by(A, x);
	print_list(A);
	
	
	
	printf("Bonus:\n");
	Node *B = reverse_list(A);
	print_list(B);
	free_list(A);
	free_list(B);
	return 0;
}

Node* build_list(const char* filename)
{
	Node *A, *head;
	head = NULL;
	FILE *fp = fopen(filename,"r");
	while ( A != NULL)
	{
		A = malloc(sizeof(Node));
		fscanf(fp, "%d", &A->data);
		if(feof(fp))
		{
			break;
		}
		A->next = head;
		head = A;
	}
	fclose(fp);
	return head;
}
void print_list(Node *head)
{
	if(head == NULL)
	{
		printf("List is empty.\n\n");
	}
	else
	{
		while(head != NULL)
		{
			printf("%d -> ", head->data);
			head = head->next;
		}
		printf("NULL\n");
	}
}
void multiply_by(Node *head, int val)
{
/*	
	Node *temp;
	temp = head;
	do
	{	
		temp->data = (temp->data) *val;
		temp = temp->next;
	}while(temp != NULL);	

	Node *temp;
	
	temp = malloc(sizeof(Node));
	if(head != NULL)
	{
		temp =head;
		while(temp !=NULL)
		{
			temp->data = (temp->data) *val;
			temp = temp->next;
		}	
	}

	Node *temp =malloc(sizeof(Node));
//	Node *next = NULL;
	temp = head;
	while( temp !=NULL)
	{
	//	temp = head->next;
	//	temp = head;
		temp->data = (temp->data) * val;
		temp = temp->next;
	//	next = temp->next;
	//
	next->next = NULL;
	}
*/
	while(head != NULL)
	{
		head ->data = (head->data) *val;
		head = head->next;
	}
}
	

void free_list(Node *head)
{
/*	while(head != NULL)
	{
		Node *temp;
		temp = head;
		free(head);
		if(head->next !=NULL)
		{
			head = head->next;
			head = NULL;
		}
		else
		{
			head = NULL;
		}
	}
	return ;
*/
	Node *pre = head;
	while(head)
	{
		head = head->next;
		free(pre);
		pre = head;
	}
}

Node *reverse_list(Node *head)
{
	Node *prev = NULL;
	Node *temp;
	while(head != NULL)
	{
		temp = head->next;
		head->next = prev;
		prev = head;
		head = temp;
	}
	
	
	return prev;
	

}
	



