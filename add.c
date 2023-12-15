#include "monty.h"
/**
 * add_s - add the element in the top
 * @top: the top of stack
 * @count: the line_number
 */
void add_s(stack_t **top, unsigned int count)
{
	stack_t *h;
	int len = 0, aux;

	h = *top;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", count);
		fclose(cv.file);
		free(cv.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	h = *top;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*top = h->next;
	free(h);
}
