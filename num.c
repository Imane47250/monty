#include "header.h"

/**
 * num_len -  count how many charachter in number
 * @num: number
 * Owned by: Imane & Fatima Zahra
 * Return: length of num
 */
size_t num_len(int num)
{
	int len = 0;

	if (!num)
		return (1);
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

/**
 * is_number -  checks if a string represents a valid int
 * @token: token string
 * Owned by:Imane & Fatima Zahra
 * Return: void
 */
void is_number(char *token)
{
	int i = 0;

	if (atoi(token) < 0)
		i++;
	if ((isdigit(token[i]) && strlen(token) == num_len(atoi(token))) ||
		(token[0] == '-' && isdigit(token[1])))
		datax.push_value = atoi(token);
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", datax.line_num);
		free_stack(datax.top);
		exit(EXIT_FAILURE);
	}
}

