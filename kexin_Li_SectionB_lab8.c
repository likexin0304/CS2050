#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
        int data;
        struct node_* left;
        struct node_* right;
} Node;
void printTree(Node *root, int depth);
Node *insert(Node* root, int data);
Node *buildTree(char *filename);
int min(Node *root);
Node *delete(Node *root, int data);
void freeTree(Node *root);
Node *flipTree(Node *root);

int main(int argc, char *argv[])
{
	Node *root = NULL;
	int x;
	if(argc != 2)
	{
		printf("Incorrect  usage\n");
		return 0;
	}
	printf("The initail tree\n");
	
	root = buildTree(argv[1]);
	
	printTree(root, 0);
	
	printf("Enter a number to delete:\n");
	scanf("%d", &x);
	
	delete(root, x);
	printf("The tree without %d\n", x);
	printTree(root,0);
	printf("Bonus\n");
	root = flipTree(root);
	printTree(root, 0);

	freeTree(root);
	//printTree(root,0);
	return 0;
	
		

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

Node *buildTree(char *filename)
{
		


	FILE *file = fopen(filename, "r");
        if(file == NULL)
        {
                return 0;
        }
	Node *root = NULL;
	int data;
	while(1)
	{
	//	int data;
		fscanf(file, "%d", &data);
		if(feof(file))
		{
			printf("read all data\n");
			return root;
		}
		root = insert(root, data);
		
	}

}




int min(Node *root)
{
	Node *current = root;
	while( current->left != NULL)
	{
		current = current->left;
	}
	return(current->data);
}

Node *delete(Node *root, int data)
{
	if( root == NULL)
	{
		return root;
	}
	if( data < root->data)
	{
		root->left = delete(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = delete(root->right, data);
	}
	else
	{
		if(root->left == NULL)
		{
			Node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Node *temp = root->left;
			free(root);
			return temp;
		}
		Node *temp = root;
		temp->data = min(root->right);
		root->data = temp->data;
		root->right = delete(root->right, temp->data);
	}
	return root;

	
}
void freeTree(Node *root)
{
	while(1)
	{
		if(root == NULL)
		{
			break;
		}
		else if(root->left != NULL)
		{
			freeTree(root->left);
			root->left = NULL;
		}
		else if(root->right != NULL)
		{
			freeTree(root->right);
			root->right = NULL ;
		}
		else
		{
			free(root);
			return;
		}
	}
}

Node *flipTree(Node *root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		Node *temp;
		flipTree(root->left);
		flipTree(root->right);
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
	return root;
}

