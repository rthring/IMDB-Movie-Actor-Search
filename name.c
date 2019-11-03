#include "name.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name_array *get_name(char *directory)
{
	char *p;
	char q[2048];
	char r[2048];
	char *value;
	struct array *name_array;
	struct name_basics *info;
	FILE *fp;
	int actors = 0;
	int i = 0;
	p = (char*) malloc(strlen(directory) + strlen("/name.basics.tsv") + 1);
	strcpy(p, directory);
	strcat(p, "/name.basics.tsv");
	fp = fopen(p, "r" );
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, r, 5);
		if ((strstr(r, "actor")) || (strstr(r, "actress"))) {
			actors++;
		}
	}
	name_array = malloc(sizeof(struct array));
	info = malloc(actors * sizeof(struct name_basics));
	name_array->nelements = actors;
	name_array->arr = info;
	fseek(fp, 0, SEEK_SET);
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, r, 5);
		if ((strstr(r, "actor")) || (strstr(r, "actress"))) {
			get_column(q, r, 1);
			value = malloc (strlen(r) + 1);
			value = strcpy(value, r);
			(info + i)->nconst = value;
			get_column(q, r, 2);
			value = malloc (strlen(r) + 1);
			value = strcpy(value, r);
			(info + i)->primaryName = value;
			i++;
		}
	}
	printf("Actors: %d, Counted actors: %d \n", actors, i);
	fclose(fp);
	free(p);
	return name_array;
}