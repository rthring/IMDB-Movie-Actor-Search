/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include "name.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name_array *get_name(char *directory)
{
	char *p;
	char q[1001];
	char r[1001];
	char *value;
	struct name_array *array;
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
	array = malloc(sizeof(struct name_array));
	info = malloc(actors * sizeof(struct name_basics));
	array->nelements = actors;
	array->arr = info;
	array->nconst_root = NULL;
	array->name_root = NULL;
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
	fclose(fp);
	free(p);
	return array;
}