/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include "binary.h"
#include "name.h"
#include "title.h"
#include "principals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
struct tree *add_node (struct tree *root, char *value, void *element) {
	if (root == NULL) {
		root = malloc(sizeof(struct tree));
		root->value = value;
		root->data = element;
		root->left = NULL;
		root->right = NULL;
	} else if (strcmp(value, root->value) < 0) {
		root->left = add_node(root->left, value, element);
	} else {
		root->right = add_node(root->right, value, element);
	}
	return root;
}

struct tree *find_node (struct tree *root, char *value) {
	int i;
	if (root == NULL) {
		return root;
	}
	i = strcmp(value, root->value);
	if (i == 0) {
		return root;
	}
	else if (i < 0) {
		return find_node(root->left, value);
	} else {
		return find_node(root->right, value);
	}
}

void free_normal_nodes (struct tree *root) {
	if (root != NULL)
	{
		free_normal_nodes(root->left);
		free_normal_nodes(root->right);
		free(root);
	}
}

void free_reverse_nodes (struct tree *root) {
	if (root != NULL)
	{
		free_reverse_nodes(root->left);
		free_reverse_nodes(root->right);
		free(root->value);
		free(root);
	}
}