/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */
 
struct principals_array
{
	struct title_principals *arr;
	int nelements;
};

struct title_principals {
	char *tconst;
	char *nconst;
	char *characters;
	struct tree *tconst_root;
	struct tree *nconst_root;
};

struct principals_array *get_principals(char []);