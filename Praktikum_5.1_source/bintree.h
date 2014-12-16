/*
 * bintree.h
 *
 *  Created on: 15.12.2014
 *      Author: georg
 */

#ifndef PRAKTIKUM_5_1_SOURCE_BINTREE_H_
#define PRAKTIKUM_5_1_SOURCE_BINTREE_H_



struct branch
{
	char leef;
	struct branch *leftson;
	struct branch *rightson;
	struct branch *father;
};



struct branch *initialise_root (void);

struct branch *add_lson (struct branch *Father);

struct branch *add_rson(struct branch *Father);

struct branch *free_lson(struct branch *Father);

struct branch *free_rson(struct branch *Father);

struct branch *free_branch(struct branch *Branch);

struct branch *moto_father(struct branch *Branch);

struct branch *moto_lson(struct branch *Branch);

struct branch *moto_rson(struct branch *Branch);

int has_fathers(struct branch *Branch);

void print_branchN(struct branch *Branch);

void print_inOrder(struct branch *Root);

void sort_in(struct branch *Root, char a);

int depth (struct branch *Root);

#endif /* PRAKTIKUM_5_1_SOURCE_BINTREE_H_ */
