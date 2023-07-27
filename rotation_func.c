#include "monty.h"

/**
 * _rotl -  rotates the stack to the left.
 * @head: double pointer to the top of the stack
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _rotl(stack_t **head, unsigned int line_number)
{
	stack_t *last = *head;
	int i;

	if (!*head)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	(*head)->prev = last;
	(*head) = (*head)->next;
	(*head)->prev->next = NULL;
	(*head)->prev = NULL;
}

/**
 * _rotr - rotates the stack to the right.
 * @head: node to be rotated
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _rotr(stack_t **head, unsigned int line_number)
{
	stack_t *last = *head;
	int i;

	if (!*head || (*head)->next == NULL)
		return;
	(void)line_number;
	for (i = 0; last; i++)
	{
		if (!last->next)
			break;
		last = last->next;
	}
	last->next = *head;
	last->prev->next = NULL;
	(*head)->prev = last;
	(*head) = last;
	last->prev = NULL;
}
