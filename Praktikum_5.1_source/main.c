/*
 * main.c
 *
 *  Created on: 15.12.2014
 *      Author: georg
 */

#include<stdio.h>
#include<string.h>
#include "../Praktikum_5.1_source/bintree.h"

int main(int argc, char **argv)
{
	struct branch *Root;
	char *string = "jrskepchdbammoawmelspwyosvmlqyvsslowqrtcvy";
	int i=0;

	Root = initialise_root();
	while (string[i]!='\0')
	{
		sort_in(Root,string[i]);
		i++;
	}
	print_inOrder(Root);
	printf("\n %d",depth(Root));
	free_bintree(Root);
	print_branchN(find_last(Root));


	return 0;

}
