/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */
 
 #include "principals.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct principals_array *get_principals(char *directory)
{
	char *p;
	char q[1001];
	char category[1001];
	char adult[1001];
	char *value;
	struct principals_array *array;
	struct title_principals *info;
	FILE *fp;
	int principals = 0;
	int i = 0;
	p = (char*) malloc(strlen(directory) + strlen("/title.principals.tsv") + 1);
	strcpy(p, directory);
	strcat(p, "/title.principals.tsv");
	fp = fopen(p, "r" );
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, category, 4);
		if ((strstr(category, "actor")) || (strstr(category, "actor"))) {
			principals++;
		}
	}
	array = malloc(sizeof(struct principals_array));
	info = malloc(principals * sizeof(struct title_principals));
	array->nelements = principals;
	array->arr = info;
	array->tconst_root = NULL;
	array->nconst_root = NULL;
	fseek(fp, 0, SEEK_SET);
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, category, 4);
		if ((strstr(category, "actor")) || (strstr(category, "actor"))) {
			get_column(q, category, 1);
			value = malloc (strlen(category) + 1);
			value = strcpy(value, category);
			(info + i)->tconst = value;
			get_column(q, category, 3);
			value = malloc (strlen(category) + 1);
			value = strcpy(value, category);
			(info + i)->nconst = value;
			get_column(q, category, 6);
			value = malloc (strlen(category) + 1);
			value = strcpy(value, category);
			(info + i)->characters = value;
			i++;
		}
	}
	printf("Principals: %d, Counted principals: %d \n", principals, i);
	fclose(fp);
	free(p);
	return array;
}