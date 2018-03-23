#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node * AVLTree;
struct Node {
	int reach;
	char ** id;
	char ** link;
	char ** message;
	char ** type;
	char ** date;
	int *engaged;
	struct Node *left;
	struct Node *right;
	int height;
	int elements;
	//Node declaration. Note that for all link id message type date engaged I have created a 2 dimentional array, so that if I find a post with same reach value their contents will be in this 2D array!
};
AVLTree CreateTree(void);
AVLTree MakeEmptyTree(AVLTree);
AVLTree SingleRotateWithLeft(AVLTree);
AVLTree SingleRotateWithRight(AVLTree);
AVLTree DoubleRotateWithLeft(AVLTree);
AVLTree DoubleRotateWithRight(AVLTree);
void DisplayTree(AVLTree);
void DisplayTreeStructure(AVLTree, int);
int AVLTreeHeight(AVLTree);
int Max(int,int);
//My function and some auxilliary function declarations

AVLTree CreateTree(void)
{
	return NULL;
}
AVLTree MakeEmptyTree(AVLTree t)
{
	if (t != NULL)
	{
		MakeEmptyTree(t->left);
		MakeEmptyTree(t->right);
		free(t);
	}
	return NULL;
}


	
	
	
	int AVLTreeHeight(AVLTree t)
{
	if (t == NULL)
		return -1;
	else
		return t->height;
}

AVLTree SingleRotateWithLeft(AVLTree k2)
{
	struct Node *t=k2->left;
	k2->left=t->right;
	t->right=k2;
	t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;
	k2->height = Max(AVLTreeHeight(k2->left), AVLTreeHeight(k2->right)) + 1;
	return t;
}

AVLTree SingleRotateWithRight(AVLTree k1)
{
	struct Node *t=k1->right;
	k1->right=t->left;
	t->left=k1;
	t->height = Max(AVLTreeHeight(t->left), AVLTreeHeight(t->right)) + 1;
	k1->height = Max(AVLTreeHeight(k1->left), AVLTreeHeight(k1->right)) + 1;
	return t;
}

AVLTree DoubleRotateWithLeft(AVLTree k3)
{
	k3->left=SingleRotateWithRight(k3->left);
 	return SingleRotateWithLeft(k3);
	
	
}

AVLTree DoubleRotateWithRight(AVLTree k3)
{
	k3->right=	SingleRotateWithLeft(k3->right);
return 	SingleRotateWithRight(k3);
	
}

int Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

void DisplayTreeStructure(AVLTree t, int depth)
{
	int i;

	if (t != NULL)
	{
		DisplayTreeStructure(t->right, depth + 1);

		for (i = 0; i < depth; i++)
			printf("     ");
		printf("%s",(t->message)[0]);

		DisplayTreeStructure(t->left, depth + 1);
	}
}
void displayNode(AVLTree t){
	int i=0;
	for(i;i<t->elements;i++){
		printf("%s %s %s %s %s %d %d\n",(t->id)[i],(t->link)[i],(t->message)[i],(t->type)[i],(t->date)[i],t->reach,(t->engaged)[i]);
	}
}
