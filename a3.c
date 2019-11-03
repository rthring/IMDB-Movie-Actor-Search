/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
#include "common.h"
#include "title.h"
#include "name.h"
#include "principals.h"

int main (int argc, char *argv[])
{
	struct name_array *test1;
	struct title_array *test2;
	struct principals_array *test3;
	int i;
	if (argc != 2)
	{
		printf("You entered the wrong amount of arguments \n");
	}
	
	test1 = get_name(argv[1]);
	for (i = 0; i < test1->nelements; i++) {
		free(((test1->arr) + i)->nconst);
		free(((test1->arr) + i)->primaryName);
	}
	free(test1->arr);
	free(test1);
	
	test2 = get_title(argv[1]);
	for (i = 0; i < test2->nelements; i++) {
		free(((test2->arr) + i)->tconst);
		free(((test2->arr) + i)->primaryTitle);
	}
	free(test2->arr);
	free(test2);
	
	test3 = get_principals(argv[1]);
	for (i = 0; i < test3->nelements; i++) {
		free(((test3->arr) + i)->tconst);
		free(((test3->arr) + i)->nconst);
		free(((test3->arr) + i)->characters);
	}
	free(test3->arr);
	free(test3);
}