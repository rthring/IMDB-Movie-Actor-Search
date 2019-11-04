/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	struct tree *root_two;
	struct tree *root_three;
	char input[1024];
	char inputTest[1024];
	char *actual_input;
	char *command;
	int end;
	int i;
	int exit_outer = 0;
	int exit_inner = 0;
	int break_flag = 0;
	int name = 0;;
	
	name_basics = get_name(argv[1]);
	title_basics = get_title(argv[1]); 
	title_principals = get_principals(argv[1]);
	name_basics->name_root = build_pnindex(name_basics);
	name_basics->nconst_root = build_nindex(name_basics);
	title_basics->title_root = build_ptindex(title_basics);
	title_basics->tconst_root = build_tindex(title_basics);
	title_principals->tconst_root = build_tindex_tp(title_principals);
	title_principals->nconst_root = build_nindex_tp(title_principals);
	
	while (exit_outer == 0) {
		end = -1;
		i = 0;
		command = NULL;
		actual_input = NULL;
		root = NULL;
		printf("> ");
		fgets(input, 1024, stdin);
		while (command == NULL) {
			if (input[i] != ' ') {
				command = input + i;
			}
			i++;
		}
		i = strlen(input) - 1;
		while (end == -1) {
			if (input[i] != ' ') {
				end = i - 1;
			}
			i--;
		}
		input[end + 1] = '\0';
		if (strncmp(command, "title", 5) == 0) {
			actual_input = command + 5;
			while (*actual_input == ' ') {
				actual_input = actual_input + 1;
			}
			root = find_primary_title(title_basics, actual_input);
			if (root != NULL) {
				root_two = find_tconst_tp(title_principals, ((struct title_basics *) root->data)->tconst);
				while (root_two != NULL) {
					root_three = find_nconst(name_basics, ((struct title_principals *) root_two->data)->nconst);
					if (root_three != NULL) {
						printf("%s : %s\n", ((struct name_basics *)root_three->data)->primaryName, ((struct title_principals *)root_two->data)->characters);
					}
					root_two = root_two->right;
					root_two = find_node(root_two, reverse(((struct title_basics *) root->data)->tconst));;
				}
			}
		} else if (strncmp(command, "name", 4) == 0) {
			actual_input = command + 4;
			while (*actual_input == ' ') {
				actual_input = actual_input + 1;
			}
			root = find_primary_name(name_basics, actual_input);
			if (root != NULL) {
				root_two = find_nconst_tp(title_principals, ((struct name_basics *) root->data)->nconst);
				while (root_two != NULL) {
					root_three = find_tconst(title_basics, ((struct title_principals *) root_two->data)->tconst);
					if (root_three != NULL) {
						printf("%s : %s\n", ((struct title_basics *)root_three->data)->primaryTitle, ((struct title_principals*)root_two->data)->characters);
					}
					root_two = root_two->right;
					root_two = find_node(root_two, reverse(((struct name_basics *) root->data)->nconst));
				}
			}
		}
	}
	
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