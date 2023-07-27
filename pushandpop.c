#include "header.h"

/**
 * _push -  adds a new node at the beginning
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane and Fatima Zahra
 * Return: void
 */
void push(stack_t **top, unsigned int line_number)
{
	stack_t *new;
	int num;

	if (!datax.push_value)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}

	num = atoi(datax.push_value);
	if (!num && strcmp(datax.push_value, "0") != 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}

	new->n = num;
	new->next = *top;
	new->prev = NULL;

	if (*top)
		(*top)->prev = new;

	*top = new;
}

/**
 * _pop - removes the top element of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
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

