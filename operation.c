#include "monty.h"

/**
 * _add - adds the first 2 elements.
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _add(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n += value;
}

/**
 * _sub - substracts second node from top node
 *  from the second top element of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _sub(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n -= value;
}

/**
 * _mul - multiplies second node with top one
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _mul(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n *= value;
}
/**
 * _div - divides second node from top node
 * @top: head of double list
 * @line_number: line number of ocommand or opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _div(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n /= value;
}



/**
 * _mod - mod second node from top node.
 * @top: top of list
 * @line_number: line num of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _mod(stack_t **top, unsigned int line_number)
{
	int value = 0;

	if (!*top || (*top)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	value = (*top)->n;
	_pop(&datax.top, datax.line_num);
	(*top)->n %= value;
}
