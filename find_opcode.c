#include "monty.h"

/**
 * find_opcode_func - selects the correct operation function based on the input
 * @token1: pointer to a string representing the opcode
 * Owned by: Imane & Fatima Zahra
 * Return: pointer to correct operation function
 */
void (*find_opcode_func(char *token1))(stack_t **stack, unsigned int line_num)
{
	instruction_t instruction_s[] = {
		{"pop", pop},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"nop", nop},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instruction_s[i].f != NULL)
	{
		if (strcmp(token1, instruction_s[i].opcode) == 0)
			return (instruction_s[i].f);
		i++;
	}
	return (NULL);
}

