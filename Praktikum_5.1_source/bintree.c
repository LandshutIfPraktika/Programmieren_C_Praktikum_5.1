/*
 * bintree.c
 *
 *  Created on: 15.12.2014
 *      Author: georg
 */

#include "../Praktikum_5.1_source/bintree.h"

#include <stdlib.h>
#include <stdio.h>

struct branch *initialise_root(char a)
{
	struct branch *root;
	root = malloc(sizeof(struct branch));

	root->leef = a;

	root->father = NULL;
	root->leftson = NULL;
	root->rightson = NULL;

	return root;
}

struct branch *add_lson(struct branch *Father, char a)
{
	struct branch *leftSon;
	leftSon = malloc(sizeof(struct branch));

	leftSon->leef = a;

	leftSon->father = Father;
	leftSon->leftson = NULL;
	leftSon->rightson = NULL;
	Father->leftson = leftSon;

	return leftSon;
}

struct branch *add_rson(struct branch *Father, char a)
{
	struct branch *rightSon;
	rightSon = malloc(sizeof(struct branch));

	rightSon->leef = a;

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
	int i = 0;

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

		if (Root->rightson != NULL)
		{
			print_inOrder(Root->rightson);
		}

	}
}

