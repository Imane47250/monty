#include "header.h"

/**
 * openfile -  opens the file and reads its content
 * @filename: file name
 * Owned by: Imane & Fatima Zahra
 * Return: FILE
 */
FILE *openfile(char *filename)
{
	FILE *mfile;

	mfile = fopen(filename, "r");
	if (!mfile)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	return (mfile);
}



/**
 * free_stack -  frees stack
 * @top: head of double list
 * Owned by: Imane & Fatima zahra
 * Return: void
 */
void free_stack(stack_t *top)
{
	stack_t *nav, *nav2;

	nav = top;
	while (nav)
	{
		nav2 = nav->next;
		free(nav);
		nav = nav2;
	}
	datax.top = NULL;
	fclose(datax.mfile);
}

/**
 * remove_spaces - remove spaces
 * @str: string to be manipulated
 * Owned by: Imane & Fatima Zahra
 * Return: str without spaces
 */
char *remove_spaces(char *str)
{
	while (*str)
	{
		if (*str == ' ')
			str++;
		else
			break;
	}
	return (str);
}

