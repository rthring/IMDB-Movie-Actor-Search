/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include "title.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct title_array *get_title(char *directory)
{
	char *p;
	char q[1001];
	char type[1001];
	char adult[1001];
	char *value;
	struct title_array *array;
	struct title_basics *info;
	FILE *fp;
	int movies = 0;
	int i = 0;
	p = (char*) malloc(strlen(directory) + strlen("/title.basics.tsv") + 1);
	strcpy(p, directory);
	strcat(p, "/title.basics.tsv");
	fp = fopen(p, "r" );
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, type, 2);
		get_column(q, adult, 5);
		if ((strstr(type, "movie")) && (strstr(adult, "0"))) {
			movies++;
		}
	}
	array = malloc(sizeof(struct title_array));
	info = malloc(movies * sizeof(struct title_basics));
	array->nelements = movies;
	array->arr = info;
	array->tconst_root = NULL;
	array->title_root = NULL;
	fseek(fp, 0, SEEK_SET);
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL) {
		get_column(q, type, 2);
		get_column(q, adult, 5);
		if ((strstr(type, "movie")) && (strstr(adult, "0"))) {
			get_column(q, type, 1);
			value = malloc (strlen(type) + 1);
			value = strcpy(value, type);
			(info + i)->tconst = value;
			get_column(q, type, 3);
			value = malloc (strlen(type) + 1);
			value = strcpy(value, type);
			(info + i)->primaryTitle = value;
			i++;
		}
	}
	printf("Movies: %d, Counted movies: %d \n", movies, i);
	fclose(fp);
	free(p);
	return array;
}