/*
 * main.c
 *
 *  Created on: 15.12.2014
 *      Author: georg
 */

#include<stdio.h>
#include "../Praktikum_5.1_source/bintree.h"

int main(int argc, char **argv)
{
	struct branch *Root;

	Root = initialise_root();
	fill_rootToBranch(Root, 'a');
	fill_rootToBranch(Root, 'b');
	fill_rootToBranch(Root, 'c');
	fill_rootToBranch(Root, 'd');

	print_inOrder(Root);

	return 0;

}
