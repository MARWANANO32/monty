#include "monty.h"
/**
 * open_file - the function that open and read the file
 * @file_name: the name path
 * Return:void
 */
void open_file(const char *file_name)
{
	FILE *fil = fopen(file_name, "r");

	if (fil == NULL)
		fprintf(stderr, "Cannot open file: %s\n", file_name);
		exit(EXIT_FAILURE);
	read_file(fil);
	fclose(fil);
}
