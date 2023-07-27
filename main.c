#include "header.h"


/**
 * main -  main entry point
 * @argc: arg count
 * @argv: arg vector
 * Owned by: Imanne & Fatima Zahra
 * Return: the number lentgh
 */
int main(int argc, char **argv)
{
	char line[100], *token;
	int i = 0;

	datax.mode = 0;
	if (argc != 2) /* checks input */
	{
		fprintf(stderr, "USAGE: monty file\n"); /* shows correct usage */
		exit(EXIT_FAILURE);
	}
	datax.mfile = openfile(argv[1]);
	while (fgets(line, sizeof(line), datax.mfile) != NULL)
	{
		if (strlen(remove_spaces(line)) < 3 || remove_spaces(line)[0] == '#')
		{
			datax.line_num++;
			continue;
		}
		datax.line_num++;
		token = strtok(line, " \n");
		for (i = 0; token != NULL && i < 2; i++)
		{
			if (i == 0)
				datax.opcode = token;
			if (strcmp(datax.opcode, "push") != 0)
				break;
			if (i == 1)
				is_number(token);
			token = strtok(NULL, " \n");
		}
		if (strcmp(datax.opcode, "push") == 0 && i == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
			free_stack(datax.top);
			exit(EXIT_FAILURE); /*handling errors*/
		}
		find_op();
	}
	free_stack(datax.top); /*frees ressources*/
	exit(EXIT_SUCCESS);
}
