/*
 * bintree.c
 *
 *  Created on: 15.12.2014
 *      Author: georg
 */

#include "../Praktikum_5.1_source/bintree.h"

#include <stdlib.h>
#include <stdio.h>

struct branch *initialise_root(void)
{
	struct branch *root;
	root = malloc(sizeof(struct branch));

	root->leef = 0;

	root->father = NULL;
	root->leftson = NULL;
	root->rightson = NULL;

	return root;
}

struct branch *add_lson(struct branch *Father)
{
	struct branch *leftSon;
	leftSon = malloc(sizeof(struct branch));

	leftSon->leef = 0;

	leftSon->father = Father;
	leftSon->leftson = NULL;
	leftSon->rightson = NULL;
	Father->leftson = leftSon;

	return leftSon;
}

struct branch *add_rson(struct branch *Father)
{
	struct branch *rightSon;
	rightSon = malloc(sizeof(struct branch));

	rightSon->leef = 0;

	rightSon->father = Father;
	rightSon->leftson = NULL;
	rightSon->rightson = NULL;
	Father->rightson = rightSon;

	return rightSon;
}

struct branch *free_branch(struct branch *Branch)
{
	struct branch *Father;
	Father = Branch->father;
	free(Branch);

	return Father;
}

struct branch *free_lson(struct branch *Father)
{
	return free_branch(Father->leftson);
}

struct branch *free_rson(struct branch *Father)
{
	return free_branch(Father->rightson);
}

struct branch *moto_father(struct branch *Branch)
{
	return Branch->father;
}

struct branch *moto_lson(struct branch *Branch)
{
	return Branch->leftson;
}

struct branch *moto_rson(struct branch *Branch)
{
	return Branch->rightson;
}

int has_fathers(struct branch *Branch)
{
	if (Branch->father==NULL)
		return 0;

	else return 1 + has_fathers(Branch->father);
}

void print_branchN(struct branch *Branch)
{
	printf("%c(%d)", Branch->leef, has_fathers(Branch));
}

void print_inOrder(struct branch *Root)
{
	if (Root != NULL)
	{
		if (Root->leftson != NULL)
		{
			print_inOrder(Root->leftson);
		}

		print_branchN(Root);
		printf(" ");

		if (Root->rightson != NULL)
		{
			print_inOrder(Root->rightson);
		}

	}
}

void sort_in(struct branch *Root, char a)
{
	if (Root->leef  == 0)
		Root->leef = a;
	else if (a < Root->leef)
	{
		if (Root->leftson==NULL)
		{
			add_lson(Root);
		}
		sort_in(Root->leftson, a);
	}
	else if (a>Root->leef)
	{
		if (Root->rightson==NULL)
		{
			add_rson(Root);
		}
		sort_in(Root->rightson, a);
	}
}

int depth (struct branch *Root)
{

	if (Root == NULL)
		return 0;

	else if (depth(Root->rightson)>=depth(Root->leftson))
		return 1 + depth(Root->rightson);

	else
		return 1 + depth(Root->leftson);
}

struct branch *free_last(struct branch *Root)
{
	if (Root->leftson==NULL && Root->rightson==NULL)
	{
		return Root;
	}

}
