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

struct tree *build_pnindex (struct name_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, (array->arr + i)->primaryName, (array->arr + i));
	}
	return root;
}

struct tree *build_nindex (struct name_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, reverse((array->arr + i)->nconst), (array->arr + i));
	}
	return root;
}

struct tree *build_ptindex (struct title_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, (array->arr + i)->primaryTitle, (array->arr + i));
	}
	return root;
}

struct tree *build_tindex (struct title_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, reverse((array->arr + i)->tconst), (array->arr + i));
	}
	return root;
}

struct tree *build_tindex_tp (struct principals_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, reverse((array->arr + i)->tconst), (array->arr + i));
	}
	return root;
}

struct tree *build_nindex_tp (struct principals_array *array) {
	int i;
	struct tree *root = NULL;
	
	for (i = 0; i < array->nelements; i++) {
		root = add_node(root, reverse((array->arr + i)->nconst), (array->arr + i));
	}
	return root;
}

struct tree *find_primary_title (struct title_array *array, char *value) {
	return find_node(array->title_root, value);
}

struct tree *find_primary_name (struct name_array *array, char *value) {
	return find_node(array->name_root, value);
}

struct tree *find_nconst (struct name_array *array, char *value) {
	return find_node(array->nconst_root, reverse(value));
}

struct tree *find_tconst (struct title_array *array, char *value) {
	return find_node(array->tconst_root, reverse(value));
}

struct tree *find_tconst_tp (struct principals_array *array, char *value) {
	return find_node(array->tconst_root, reverse(value));
}

struct tree *find_nconst_tp (struct principals_array *array, char *value) {
	return find_node(array->nconst_root, reverse(value));
}

void free_name (struct name_array *array) {
	int i;
	for (i = 0; i < array->nelements; i++) {
		free(((array->arr) + i)->nconst);
		free(((array->arr) + i)->primaryName);
	}
	free(array->arr);
	free(array);
}

void free_title (struct title_array *array) {
	int i;
	for (i = 0; i < array->nelements; i++) {
		free(((array->arr) + i)->tconst);
		free(((array->arr) + i)->primaryTitle);
	}
	free(array->arr);
	free(array);
}

void free_principals (struct principals_array *array) {
	int i;
	for (i = 0; i < array->nelements; i++) {
		free(((array->arr) + i)->tconst);
		free(((array->arr) + i)->nconst);
		free(((array->arr) + i)->characters);
	}
	free(array->arr);
	free(array);
}

int main (int argc, char *argv[])
{
	struct name_array *name_basics;
	struct title_array *title_basics;
	struct principals_array *title_principals;
	struct tree *root;
	int i;
	if (argc != 2)
	{
		printf("You entered the wrong amount of arguments \n");
	}
	
	name_basics = get_name(argv[1]);
	title_basics = get_title(argv[1]); 
	title_principals = get_principals(argv[1]);
	
	name_basics->name_root = build_pnindex(name_basics);
	name_basics->nconst_root = build_nindex(name_basics);
	
	title_basics->title_root = build_ptindex(title_basics);
	title_basics->tconst_root = build_tindex(title_basics);
	
	title_principals->tconst_root = build_tindex_tp(title_principals);
	title_principals->nconst_root = build_nindex_tp(title_principals);
	root = title_principals->nconst_root;
	
	printf("\n Ready \n");
	root = find_primary_title(title_basics, "Blade Runner");
	printf("\n 1 \n");
	printf("\n %s \n", ((struct title_basics *) root->data)->tconst);
	root = find_tconst_tp(title_principals, ((struct title_basics *) root->data)->tconst);
	printf("\n 2 \n");
	root = find_nconst(name_basics, ((struct title_principals *) root->data)->nconst);
	printf("\n 3 \n");
	printf("\n Name %s \n", ((struct name_basics *)root->data)->primaryName);
	
	free_normal_nodes(name_basics->name_root);
	free_reverse_nodes(name_basics->nconst_root);
	free_name(name_basics);
	
	free_normal_nodes(title_basics->title_root);
	free_reverse_nodes(title_basics->tconst_root);
	free_title(title_basics);
	
	free_reverse_nodes(title_principals->nconst_root);
	free_reverse_nodes(title_principals->tconst_root);
	free_principals(title_principals);
	return 0;
}