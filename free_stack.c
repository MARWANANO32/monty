#include "monty.h"
/**
 * free_stack - frees a doubly linked list
 * @top: the top of stack
 */
void free_stack(stack_t *top)
{
	stack_t *aux;

	aux = top;
	while (top)
	{
		aux = top->next;
		free(top);
		top = aux;
	}
}
