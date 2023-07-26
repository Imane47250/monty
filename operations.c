#include "monty.h"
/**
 * _add - adds the first 2 elements
 * @top: top node
 * @line_num: node number
 * Owned by: Imane & Fatima Zahra
 * Return: Void
 */
void _add(stack_t **top, unsigned int line_num)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n += (*top)->n;
	(*top) = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
/**
 * _sub - substracts second node from top node
 * @top: top of list
 * @line_num: line of command
 * Owned by: Imane & Fatima Zahra
 * Return: Void
 */
void _sub(stack_t **top, unsigned int line_num)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n -= (*top)->n;
	(*top) = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
/**
 * _mul - multiplies second node with top one
 * @top: top of list
 * @line_num: line of command
 * Owned by: Imane & Fatima Zahra
 * Return: Void
 */
void _mul(stack_t **top, unsigned int line_num)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	(*top)->next->n *= (*top)->n;
	(*top) = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
/**
 * _div - divides second node from top node
 * @top: top of list
 * @line_num: line of command
 * Owned by: Imane & Fatima Zahra
 * Return: Void
 */
void _div(stack_t **top, unsigned int line_num)
{
	if (*top == NULL || (*top)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0 || (*top)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_num);
	}
	(*top)->next->n /= (*top)->n;
	(*top) = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
/**
 * _mod - mod second node from top node
 * @h: top of list
 * @line_number: line of command
 * Owned by: Imane & Fatima Zahra
 * Return: Void
 */
void _mod(stack_t **h, unsigned int line_number)
{
	if (h == NULL || *h == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*h)->n == 0 || (*h)->next->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
	}
	(*h)->next->n %= (*h)->n;
	(*h) = (*h)->next;
	free((*h)->prev);
	(*h)->prev = NULL;
}
