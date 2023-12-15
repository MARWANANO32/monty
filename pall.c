#include "monty.h"
/**
 * pall_s - the function that print the stack
 * @top: the top of stack
 * @count: not for used
 */
void pall_s(stack_t **top, unsigned int count)
{
	stack_t *h;
	(void)count;

	if (top == NULL)
		exit(EXIT_FAILURE);
	h = *top
	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
