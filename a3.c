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

struct tree *build_ptindex (struct title_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, (array->arr + i)->primaryTitle, (array->arr + i));
	}
	return root;
}

struct tree *find_primary_title (struct title_array *array, char *value) {
	return find_node(array->title_root, value);
}

struct tree *build_pnindex (struct name_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, (array->arr + i)->primaryName, (array->arr + i));
	}
	return root;
}

struct tree *find_primary_name (struct name_array *array, char *value) {
	return find_node(array->title_root, value);
}

int main (int argc, char *argv[])
{
	struct name_array *test1;
	struct title_array *test2;
	struct principals_array *test3;
	struct tree *root;
	int i;
	if (argc != 2)
	{
		printf("You entered the wrong amount of arguments \n");
	}
	/*
	test1 = get_name(argv[1]);
	
	for (i = 0; i < test1->nelements; i++) {
		free(((test1->arr) + i)->nconst);
		free(((test1->arr) + i)->primaryName);
	}
	free(test1->arr);
	free(test1);
	*/
	
	test2 = get_title(argv[1]);
	printf("\n 1 \n");
	test2->title_root = build_ptindex(test2);
	printf("\n 2 \n");
	root = find_primary_title(test2, "Star Wars: Episode V - The Empire Strikes Back");
	printf("Title: %s, tconst: %s \n", ((struct title_basics *)root->data)->primaryTitle, ((struct title_basics *)root->data)->tconst);
	printf("\n 3 \n");
	free_nodes(test2->title_root);
	printf("\n 4 \n");
	test2->title_root = NULL;
	for (i = 0; i < test2->nelements; i++) {
		free(((test2->arr) + i)->tconst);
		free(((test2->arr) + i)->primaryTitle);
	}
	free(test2->arr);
	free(test2);
	
	/*
	test3 = get_principals(argv[1]);
	for (i = 0; i < test3->nelements; i++) {
		free(((test3->arr) + i)->tconst);
		free(((test3->arr) + i)->nconst);
		free(((test3->arr) + i)->characters);
	}
	free(test3->arr);
	free(test3); */
}