#include "header.h"

/**
 * find_op - selects the correct operation function based on the input
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void find_op(void)
{
	instruction_t ins[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _mode},
		{"stack", _mode},
		{NULL, NULL},
	};
	int j = 0;

	for (j = 0; ins[j].opcode; j++)
	{
		if (strcmp(datax.opcode, ins[j].opcode) == 0)
		{
			ins[j].f(&datax.top, datax.line_num);
			break;
		}
	}
	if (!ins[j].opcode)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
				datax.line_num, datax.opcode);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
}
