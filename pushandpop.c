#include "header.h"

/**
 * _push -  adds a new node at the beginning
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _push(stack_t **top, unsigned int line_number)
{
	stack_t *new, *last;
	int i = 0;

	(void)line_number;
	if (!top)
		return;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed");
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	new->n = datax.push_value;
	if (datax.mode == 0 || !*top)
	{
		if (*top)
		{
			new->next = *top;
			(*top)->prev = new;
		}
		else
			new->next = NULL;
		new->prev = NULL;
		*top = new;
	}
	else if (datax.mode == 1)
	{
		last = *top;
		for (i = 0; last; i++)
		{
			if (!last->next)
				break;
			last = last->next;
		}
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}


/**
 * _pop - removes the top element of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Return: none
 */
void _pop(stack_t **top, unsigned int line_number)
{

	if (!*top)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->next == NULL)
	{
		free(*top);
		*top = NULL;
	}
	else
	{
		*top = (*top)->next;
		free((*top)->prev);
		(*top)->prev = NULL;
	}
}

