#include "monty.h"
/**
 * swap - swaps positions of top two elements of the stack.
 * @sw: node to be swapped
 * @line_number: node number
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void swap(stack_t **sw, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (*sw == NULL || (*sw)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*sw)->next;
	if (tmp->next != NULL)
	{
		(*sw)->next = tmp->next;
		(*sw)->next->prev = *sw;

	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *sw;
	(*sw) = tmp;
}
