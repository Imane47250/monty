#include "header.h"
/**
 * _mode -  aswitch the mode queue/stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _mode(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;

	if (strcmp(datax.opcode, "queue") == 0)
		datax.mode = 1;
	else if (strcmp(datax.opcode, "stack") == 0)
		datax.mode = 0;
}


/**
 * _pall -  prints all the elements of a dlistint_t list
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _pall(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;

	(void)line_number;
	for (i = 0; current; i++)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
	fflush(stdout);
}

/**
 * _pint -  prints the value at the top of the stack
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _pint(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*top)->n);
	fflush(stdout);
}



/**
 * _pchar - prints the char at the top of the stack (ascii).
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _pchar(stack_t **top, unsigned int line_number)
{
	if (!*top)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	if ((*top)->n > 127 || (*top)->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*top)->n);
}

/**
 * _pstr - prints the string starting at the top of the stack.
 * @top: head of double list
 * @line_number: line number of opcode
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void _pstr(stack_t **top, unsigned int line_number)
{
	stack_t *current = *top;
	int i;
	(void)line_number;

	for (i = 0; current && current->n != 0 &&
				!(current->n > 127 || current->n < 0);
		 i++)
	{
		fprintf(stdout, "%c", current->n);
		current = current->next;
	}
	fprintf(stdout, "\n");
}

