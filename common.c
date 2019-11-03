/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */
 
#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_column (char *line, char *dest, int column) {
	int start;
	int i = 0;
	int tabCount = 0;
	int end = -1;
	if (column == 1) {
		start = 0;
	}
	while ((end == -1) && (line[i] != '\0')) {
		if (line[i] == '\t') {
			tabCount++;
			if (tabCount == column) {
				end = i;
			} else if (tabCount == column - 1)
			{
				start = i + 1;
			}
		}
		i++;
	}
	if (line[i] == '\0') {
		strcpy(dest, "\0");
	} else {
		strncpy(dest, (line + start), end - start);
		dest[end - start] = '\0';
	}
}

char *reverse (char *string) {
	char temp;
	int last = strlen(string) - 1;
	int start = 0;
	char *reversed = malloc(i + 2);
	strcpy(reversed, string);
	while (start < last) {
		temp = reversed[start];
		reversed[start] = reversed[end];
		reversed[end] = temp;
	}
	return reversed;
}