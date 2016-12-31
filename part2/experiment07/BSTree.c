#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BSTree.h"

typedef struct pair {
	Node * parent;
	Node * child;
}Pair;

static Node * MakeNode (const ElemType * item);
static bool ToLeft (const ElemType * i1, const ElemType * i2);
static bool ToRight (const ElemType * i1, const ElemType * i2);
static void AddNode (Node * new_node, Node * root);
static void InOrder (const Node * root, void (* pfun)(ElemType item));
static Pair SeekItem (const ElemType * item, const BSTree * T);
static void DeleteNode (Node ** ptr);
static void DeleteAllNodes (Node * ptr);

void InitBSTree(BSTree * T)
{
	T->root = NULL;	
	T->size = 0;
}

bool BSTreeIsEmpty(const BSTree * T)
{
	if (T->root == NULL)
		return true;
	else 
		return false;
}

bool BSTreeIsFull(const BSTree * T)
{
	if (T->size == MAXITEMS)
		return true;
	else
		return false;
}

bool AddItem(BSTree * T, ElemType * item)
{
	Node * new_node;
	if (BSTreeIsFull(T))
	{
		fprintf(stderr, "Tree is full.\n");
		return false;
	}
	if (SeekItem(item, T).child != NULL)
	{
		fprintf(stderr, "Attempted to add duplicate item\n");
		return false;
	}
	new_node = MakeNode(item);
	if (new_node == NULL)
	{
		fprintf(stderr, "Couldn't create node\n");
		return false;
	}

	T->size ++;
	
	if (BSTreeIsEmpty(T))
		T->root = new_node;
	else
		AddNode(new_node, T->root);
	
	return true;
}

bool DeleteItem(BSTree * T, ElemType * item)
{
	Pair look;
	look = SeekItem(item, T);
	if (look.child == NULL)
		return false;
	
	if (look.parent == NULL)
		DeleteNode(&T->root);
	else if (look.parent->left == look.child)
		DeleteNode(&look.parent->left);
	else
		DeleteNode(&look.parent->right);
	T->size --;
	
	return true;
}

bool InBSTree(const BSTree * T, ElemType * item)
{
	return (SeekItem(item, T).child == NULL) ? false : true;
}


static void InOrder (const Node * root, void (* pfun)(ElemType item)) 
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		(* pfun)(root->item);
		InOrder(root->right, pfun);
	}
}

static void DeleteAllNodes (Node * ptr)
{
	Node * pright;
	if (root != NULL)
	{
		pright = root->right;
		DeleteAllNodes(root->left);
		free(root);
		DeleteAllNodes(pright);
	}
}

static void AddNode (Node * new_node, Node * root)
{
	if (ToLeft(&new_node->item, &root->item))
	{
		if (root->left == NULL)
			root->left = new_node;
		else
			AddNode (new_node, root->left);
	}
	else if (ToRight(&new_node->item, &root->item))
	{
		if (root->right == NULL)
			root->right = new_node;
		else
			AddNode (new_node, root->right);
	}
	else  
	{
		fprintf(stderr, "location error in AddNode()\n");
		exit(1);
	}
}

static bool ToLeft (const ElemType * i1, const ElemType * i2)
{
	int comp1 = strcmp(i1->petname, i2->petname);
	if ( comp1 < 0 )
		return true;
	else if ( comp1 == 0 && strcmp(i1->petkind, i2->petkind) < 0 )
		return true;
	else
		return false;
}

static bool ToRight (const ElemType * i1, const ElemType * i2)
{
	int comp1 = strcmp(i1->petname, i2->petname);
	if ( comp1 > 0 )
		return true;
	else if ( comp1 == 0 && strcmp(i1->petkind, i2->petkind) > 0 )
		return true;
	else
		return false;
}

static Node * MakeNode (const ElemType * item)
{
	Node * new_node;
	new_node = (Node *)malloc(sizeof(Node));
	if (new_node != NULL)
	{
		new_node->item = *item;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return new_node;
}

static Pair SeekItem (const ElemType * item, const BSTree * T)
{
	Pair look;
	look.parent = NULL;
	look.child = T->root;
	
	if (look.child == NULL)
		return look;
	while (look.child != NULL)
	{
		if (ToLeft(item, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if ( ToRight(item, &(look.child->item)))
		{
			look.parent = look.child;
			look.child = look.child->right;
		}
		else
			break;
	}
	return look;
}


static void DeleteNode (Node ** ptr)
{
	Node * temp;
	if ((* ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((* ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else 
	{
		
		for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
			continue;
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

