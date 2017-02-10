//Name:KEXIN LI
//Section: B
//Date: 3/15/16
//lab Code:Heating up

#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
        int data;
        struct node_* next;
} Node;

Node* enqueue(Node* head, int data);
int dequeue(Node **frontPtr);
void printQueue(Node *front);
void freeQueue(Node *front);
Node *filterEven(Node *head);

int main(void)
{
	Node *head = NULL;
	int x, number;
	printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Quit\n>");
	scanf("%d", &x);
	
	while (x != 0)
	{
		if( x == 1)
		{
			printf("Enter a number to enqueue:");
			scanf("%d", &number);
			head = enqueue(head, number);
			printQueue(head);
			printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Quit\n>");
        		scanf("%d", &x);
	
		}
		
		if ( x == 2)
		{
			int y;
		//	head = enqueue(head, number);
			y = dequeue(&head);
			printf("%d was dequeued\n", y);
			
			printQueue(head);
			printf("Enter 1 to Enqueue\nEnter 2 to Dequeue\nEnter 3 to Quit\n>");
                        scanf("%d", &x);

			
		}
		
		if( x == 3)
		{
			break;
		}
	}
	printf("Bnous\n");
	Node *A = filterEven(head);
	printQueue(A);	
		
	return 0;
}


Node* enqueue(Node* head, int data)
{

        Node *rear;
        Node *temp = malloc(sizeof(Node));
        temp->data = data;
        temp->next = NULL;

        if(head ==  NULL)
        {
                return temp;
        }
	
        rear = head;
        while( rear->next)
        {
                rear = rear->next;
        }
        rear->next = temp;

        return head;


}

int dequeue(Node **frontPtr)
{
	Node *temp;
	int element;
	
	if( *frontPtr == NULL)
	{
		printf("List is empty)");
		return 0;
	}
	else
	{
		temp = *frontPtr;
		element = temp->data;
		temp = temp->next;
		free(*frontPtr);
		*frontPtr = temp;
	}

	return element; 
}	

void printQueue(Node *front)
{
	
	if(front == NULL)
        {
                printf("List is empty.\n\n");
        }
        else
        {
                while(front != NULL)
                {
                        printf("%d -> ", front->data);
                        front = front->next;
                }
                printf("NULL\n");
        }
	
}

void freeQueue(Node* front)
{
	Node *temp = front;
	while(front)
	{
		front = front->next;
		free(temp);
		temp = front;
	}
}

Node *filterEven(Node *head)
{
/*	Node *temp;
	temp = head;	
	while (head != NULL)
	{
		if(head->data % 2 != 0)
		{
			temp->data = head->data;
			break;			
		}		
	}
	temp->next = NULL;
	return temp;
*/

	Node *ptr = head;
	Node *pre = NULL;
	Node *temp;
//	head = ptr;
	while( ptr->data%2 == 0 && pre == NULL)
	{
		temp = ptr;
		ptr = ptr->next;
		head = ptr;
		free(temp);
	}
	pre = ptr;
	ptr = ptr->next;
	while(ptr != NULL)
	{
		if(ptr->data %2 ==0)
		{
			temp = ptr;
			free(temp);
			pre->next = ptr->next;
			ptr = ptr->next;
		}
		else
		{
			pre = ptr;
			ptr = ptr->next;
		}
	}
	return head;
/*
	Node *temp;
    	while( (head->data %2) != 0)
    	{
        	temp->data = head->data;
        	temp = temp->next;
        	
    	}
        return head;
 

*/
}



