#include "monty.h"
/**
 * add_end_node - add node to front of doubly linked list
 * @stack: pointer to head of list
 * @n: node data
 * Owned by: Imane & Fatima Zahra
 * Return: 0 if success else -1
 */
int add_end_node(stack_t **stack, int n)
{
	stack_t *new;

	if (!stack)
		return (-1);

	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	return (0);
}
/**
 * delete_end_node - deletes node at end of doubly linked list
 * @stack: pointer to head of doubly linked list
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void delete_end_node(stack_t **stack)
{
	stack_t *del = NULL;

	del = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(del);
	}
	else
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(del);
	}
}
/**
 * free_dlist - frees a doubly linked list
 * @stack: pointer to head of list
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void free_dlist(stack_t **stack)
{
	if (!stack)
		return;

	while (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
