#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Array of pointers to command-line arguments
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	stack_t *h = NULL;
	char **lines;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	lines = read_file(argv[1]);
	if (!lines)
		exit(EXIT_FAILURE);

	if (process_instructions(&h, lines) != 0)
		exit(EXIT_FAILURE);

	free_dlist(&h);
	free_lines(lines);
	return (0);
}
