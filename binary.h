/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */
 
 struct tree {
	char *value;
	void *data;
	struct tree *left;
	struct tree *right;
 };
 struct tree *add_node (struct tree *root, char *value, void *element);
 struct tree *find_node (struct tree *root, char *value);
 void free_normal_nodes (struct tree *root);
 void free_reverse_nodes (struct tree *root);