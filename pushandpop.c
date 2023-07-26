#include "monty.h"


/**
 * push - adds node to the start of the list
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 * Owned by: Imane & Fatima Zahra
 * Return: 0
 */
void push(stack_t **h, unsigned int line_number, const char *n)
{
	if (!h)
		return;
	if (is_valid_integer(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(h, atoi(n)) == -1)
		{
			free_dlist(h);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * pop - removes node at front of the list
 * @h: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * Owned by: Imane & Fatima Zahra
 * Return: 0
 */
void pop(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_dlist(h);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(h);
}

