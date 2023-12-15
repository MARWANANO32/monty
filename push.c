#include "monty.h"
/**
 * push_s - the function that add element for stack
 * @top: the top of stack
 * @count: the line number
 */
void push_s(stack_t **top, unsigned int count)
{
	int n;
	int j = 0, flags = 0;

	if (cv.arg)
	{
		if (cv.arg[0] == '-')
			j++;
		for (int j = 0; cv.arg[j] != '\0'; j++)
		{
			if (cv.arg[j] > 57 || cv.arg[j] < 48)
				flags = 1;
			if (flags == 1)
				fprintf(stderr, "L%d: usage: push integer\n", count);
				fclose(cv.file);
				free(cv.content);
				free_stack(*top);
				exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", count);
		fclose(cv.file);
		free(cv.content);
		free_stack(*top);
		exit(EXIT_FAILURE); }
	n = atoi(cv.arg);
	if (cv.flag == 0)
		addnode(top, n);
	else
		addqueue(top, n);
}
