#include "monty.h"
/**
 * open_file - the function that open and read the file
 * @file_name: the name path
 * Return:void
 */
void open_file(const char *file_name)
{
	FILE *fl = fopen(file_name, "r");

	if (file_name == NULL)
	{
		err(2, file_name);
	}
	if (fl == NULL)
		err(2, file_name);
	read_file(fl);
	fclose(fl);
}

/**
 * read_file - the function that reads a file
 * @fl: the pointer for description
 * Return: void
 */
void read_file(FILE *fl)
{
	int line_number = 1;
	char *buffer = NULL;
	size_t len = 0;

	while (getline(&buffer, &len, fl) != -1)
	{
		int format = parse_line(buffer, line_number);

		line_number++;
	}

	free(buffer);
}
