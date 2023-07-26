#include "monty.h"

 /**
 * is_valid_integer - checks if a string represents a valid int
 * @n: pointer to the string that needs to be checked
 * Owned by: Imane & Fatima Zahra
 * Description: checking
 * Return: 0 if is number, else -1 if not
 */
int is_valid_integer(const char *n)
{
	int i = 0;

	if (*n == '-') /* handling negative numbers */
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}
