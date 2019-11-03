/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

struct name_array
{
	struct name_basics *arr;
	int nelements;
	struct tree *nconst_root;
	struct tree *name_root;
};

struct name_basics {
	char *nconst;
	char *primaryName;
};

struct name_array *get_name(char []);