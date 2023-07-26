#include "monty.h"

/**
 * rotl - rotates the stack to the left
 * @stack: double pointer to the top of the stack
 * @line_num: line number (not used in this function)
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	(void)line_num;

    /* Checks if the stack has at least two elements to rotate */
	if ((*stack)->next != NULL)
	{
		temp = *stack;

		while (temp->next != NULL)
			temp = temp->next;

		(*stack)->prev = temp;
		temp->next = *stack;
		(*stack)->next->prev = NULL;
		*stack = (*stack)->next;
		temp->next->next = NULL;
	}
}

/**
 * rotr - rotates the stack to the right
 * @stack: node to be rotated
 * @line_num: node number
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	(void) line_num;

	if ((*stack)->next != NULL)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*stack)->prev = tmp;
		tmp->next = *stack;
		tmp->prev->next = NULL;
		tmp->prev = NULL;
		(*stack) = (*stack)->prev;
	}
}
