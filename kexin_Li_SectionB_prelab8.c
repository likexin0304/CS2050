#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
	int data;
	struct node_* left;
	struct node_* right;
} Node;


void printTree(Node* root, int depth);
Node* insert(Node* root, int data);

int main(void) {
	int arr[] = {5, 3, 8, 2, 7, 4, 9};
	Node* root = NULL;
	int i;
	for (i = 0; i < 7; i++) {
		root = insert(root, arr[i]);
	}

	printTree(root, 0);
	return 0;
}

Node* insert(Node* root, int data) 
{

	
	Node * temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->left = temp->right = NULL;
	
	if(root == NULL)
	{
		return temp;
	}
	if( data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if(data >root->data)
	{
		root->right = insert(root->right, data);
	}
	return root;
	
		
}

void padding(int depth) {
	int i;
	for (i = 0; i < depth; i++) {
		putchar('\t');
	}
}

void printTree(Node* root, int depth) {
	if (root == NULL) {
		padding(depth);
		printf("~\n");
	} else {
		printTree(root->right, depth + 1);
		padding(depth);
		printf("%d\n", root->data);
		printTree(root->left, depth + 1);
	}
}
