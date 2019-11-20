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
	int i = 0;
	int tabCount = 0;
	int end = -1;
	int start = -1;
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
	if ((end == -1) && (start == -1)) {
		strcpy(dest, "\0");
	}
	else {
		end = i - 1;
		strncpy(dest, (line + start), end - start);
		dest[end - start] = '\0';
	}
}

char *reverse (char *string) {
	char temp;
	int end = strlen(string) - 1;
	int start = 0;
	char *reversed = malloc(end + 2);
	strcpy(reversed, string);
	while (start < end) {
		temp = reversed[start];
		reversed[start] = reversed[end];
		reversed[end] = temp;
		start++;
		end--;
	}
	return reversed;
}