struct array
{
	struct name_basics *arr;
	int nelements;
};

struct name_basics {
	char *nconst;
	char *primaryName;
};

struct name_array *get_name(char []);