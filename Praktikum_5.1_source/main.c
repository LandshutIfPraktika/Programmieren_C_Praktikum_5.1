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
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	struct branch *Root;
	char *string = "jrskepchdbammoawmelspwyosvmlqyvsslowqrtcvy";
	int i=0, choice;

	Root = initialise_root();
	while (string[i]!='\0')
	{
		sort_in(Root,string[i]);
		i++;
	}

	do
	{
		printf("1. print tree in order\n"
				"2. print depth of tree\n"
				"3. find leaf\n"
				"4. add key to tree\n"
				"0. end programm\n\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			{
				print_inOrder(Root);
				printf("\n");
				printf("\n");
				break;
			}
		case 2:
			{
				printf("\n%d\n",depth(Root));
				printf("\n");
				break;
			}
		case 3:
		{
			char a[2]="a";
			printf("key value: \n");
			scanf("%s", a);
			if (a[0]>= 'a'&& a[0]<='z')
			{
				print_branchN(find_leef(Root,a[0]));
				printf("\n");

			}

			else
			{

				printf("only a<=key<=z allowed\n");
			}
			printf("\n");
			break;
		}
		case 4:
		{
			char a[2]="a";
			printf("key value: \n");
			scanf("%s", a);
			if (a[0]>= 'a'&& a[0]<='z')
				sort_in(Root, a[0]);
			else
				printf("only a<=key<=z allowed\n");
			printf("\n");

			break;
		}
		default: break;

		}

	} while (choice != 0);



	free_bintree(Root);
	return 0;

}
