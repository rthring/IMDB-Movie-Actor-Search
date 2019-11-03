/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */
 
 struct title_array
{
	struct title_basics *arr;
	int nelements;
	struct tree *tconst_root;
	struct tree *title_root;
};

struct title_basics {
	char *tconst;
	char *primaryTitle;
};

struct title_array *get_title(char []);