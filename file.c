#include "monty.h"

/**
 * process_instructions - Process the instructions from the file
 * @h: Pointer to the stack
 * @lines: Number of lines in the file
 * Return: 0 on success, 1 on failure
 */
int process_instructions(stack_t **h, char **lines)
{
	unsigned int line = 1;
	char *token;
	int ispush = 0;

	token = strtok(lines[0], "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (ispush == 1)
		{
			push(h, line, token);
			ispush = 0;
		}
		else if (strcmp(token, "push") == 0)
		{
			ispush = 1;
		}
		else
		{
			if (find_opcode_func(token) != 0)
			{
				find_opcode_func(token)(h, line);
			}
			else
			{
				free_dlist(h);
				printf("L%d: unknown instruction %s\n", line, token);
				return (1);
			}
		}
		line++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}

	return (0);
}

/**
 * read_file - Reads the contents of the file
 * @file_path: Path of the file to read
 * Return: Array of lines read from the file
 */
char **read_file(const char *file_path)
{
	int file, lines_allocated = 1, max_line_len = 10000, current_line = 0;
	char **lines, *buffer;
	ssize_t bytes_read;

	file = open(file_path, O_RDONLY);
	if (file == -1)
	{
		printf("Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	lines = malloc(sizeof(char *) * lines_allocated);
	buffer = malloc(sizeof(char) * max_line_len);

	if (!lines || !buffer)
		exit(EXIT_FAILURE);

	bytes_read = read(file, buffer, max_line_len);

	while (bytes_read > 0)
	{
		if (current_line >= lines_allocated)
		{
			lines_allocated *= 2;
			lines = realloc(lines, sizeof(char *) * lines_allocated);
			if (!lines)
				exit(EXIT_FAILURE);
		}
		lines[current_line] = buffer;
		current_line++;

		buffer = malloc(sizeof(char) * max_line_len);
		if (!buffer)
			exit(EXIT_FAILURE);

		bytes_read = read(file, buffer, max_line_len);
	}
	lines[current_line] = NULL;
	close(file);
	return (lines);
}

/**
 * free_lines - Free the memory allocated for lines
 * @lines: Array of lines
 * Owned by: Imane & Fatima Zahra
 * Return: void
 */
void free_lines(char **lines)
{
	int i = 0;

	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
