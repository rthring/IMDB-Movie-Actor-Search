#include "name.h"
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct name_basics *get_name(char *directory)
{
	char *p;
	char q[2048];
	char r[2048];
	FILE *fp;
	int actors = 0;
	p = (char*) malloc(strlen(directory) + strlen("/name.basics.tsv") + 1);
	strcpy(p, directory);
	strcat(p, "/name.basics.tsv");
	fp = fopen(p, "r" );
	fgets(q, 1000, fp);
	while (fgets(q, 1000, fp) != NULL)
	{
		get_column(q, r, 5);
		if ((strstr(r, "actor")) || (strstr(r, "actress"))) {
			actors++;
		}
	}
	
	fclose(fp);
	free(p);
}