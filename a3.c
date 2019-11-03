/*
 * Name:  Ryan Thring
 * Student ID:  1058718
 * e-mail: rthring@uoguelph.ca
 */

#include <stdio.h>
#include <stdlib.h>
#include "binary.h"
#include "common.h"
#include "title.h"
#include "name.h"
#include "principals.h"

int main (int argc, char *argv[])
{
	struct name_basics *test;
	if (argc != 2)
	{
		printf("You entered the wrong amount of arguments \n");
	}
	test = get_name(argv[1]);
}