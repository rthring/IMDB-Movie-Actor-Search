#include "common.h"

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