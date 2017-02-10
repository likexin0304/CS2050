//Name : KEXIn Li
//Section : B
//Lab Code : Spring?
//Date : 4/12/2016

#include <stdlib.h>
#include <stdio.h>

typedef struct node_ {
        int data;
        struct node_* left;
        struct node_* right;
} Node;

void printarray(int *path, int depth);
void quicksort(int array[], int low, int high);
Node* buildBalancedTree(int array[], int low, int high);
void preorder(Node *root);
void inorder(Node *root);
void postorder(Node *root);
void freeTree(Node *root);
int height(Node *root);
void printEveryPath(Node *root, int *path, int depth);
int main(int argc, char *argv[])
{
	int i;
	
	int array[] = {44,9,7,23,30,72,49,58,73,78};
	//int array[] ={1,2,3,4,5,6,7,8,9,10};
	printf("check the sort\n");
	quicksort(array, 0, 9);
	for (  i = 0; i < 10; i++)
	{
		printf("%2d\n", array[i]);
	}
	Node* root = buildBalancedTree(array, 0, 9);
	printf("The heigh of the tree:%d\n",height(root));
	
	printf("\nPre-Order:\n");
	preorder(root);
	
	printf("\nIn-Order:\n");
	inorder(root);
	
	printf("\nPost-Order:\n");
	postorder(root);
	printf("\n");
	printf("Bonus\n");
	printEveryPath(root, array, 0);
	
	return 0;
	


}
void quicksort(int array[], int low, int high)
{
	int p, i, j, temp;
  	if(low < high) {
    	p = low; // select a pivot element
    	i = low;
    	j = high;
    	while(i < j) {
      
      		while(array[i] <= array[p] && i <= high)
        		i++;
      // decrement j till you get a number less than the pivot element
      		while(array[j] > array[p] && j >= low)
        		j--;
      // if i < j swap the elements in locations i and j
      		if(i < j) {
        		temp = array[i];
        		array[i] = array[j];
        		array[j] = temp;
      			}
    		}

    
    	temp = array[j];
   	array[j] = array[p];
    	array[p] = temp;
    	
    	quicksort(array, low, j-1);
    	quicksort(array, j+1, high);
  }

}
Node *buildBalancedTree(int array[], int low, int high)
{
        if( low > high)
        {
                return NULL;
        }
        int mid = ( low + high) / 2;
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data = array[mid];
        temp->left = buildBalancedTree(array, low, mid - 1);
        temp->right = buildBalancedTree(array, mid + 1, high);
        return temp;
}

void preorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	printf("%2d ", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%2d ", root->data);
	inorder(root->right);
}
void postorder(Node *root)
{
	if(root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%2d ", root->data);
}

int height(Node* root)
{
	if(root == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(root->left);
		int rheight = height(root->right);
		
		if(lheight > rheight)
		{
			return (lheight + 1);
		}
		else
		{
			return (rheight + 1);
		}
	}
}

void printEveryPath(Node *root, int *path, int depth)
{
	if( root == NULL)
	{
		return;
	}
	path[depth] = root->data;
	depth++;
	if(root->left == NULL && root->right == NULL)
	{
		printarray(path, depth);
	}
	else
	{
		printEveryPath(root->left,  path, depth);
		printEveryPath(root->right, path, depth);
	}
}
void printarray(int *path, int depth)
{
	int i;
	for( i = 0; i < depth; i++)
	{
		printf("%d ", path[i]);
	}
	printf("\n");
}
		
