#include "monty.h"
#include "utility.h"

/**
 * getNumOfTokens - Get the number of tokens tokenize
 *
 * @copy: A copy of the line or text
 * @delim: Delimeter
 *
 * Return: Number of tokens, -1 on failure
 */
int getNumOfTokens(char *copy, const char *delim)
{
	char *current = strtok(copy, delim);
	int count = 0;

	if (!current)
		return (-1);

	while (current)
	{
		count++;
		current = strtok(NULL, delim);
	}

	return (count + 1);
}

/**
 * get_operation - Get the function that correctly maps to the opcode
 *
 * @opcode: The opcode
 * @mapped: The structure that maps opcode to function
 *
 * Return: The function
 */
Op_func get_operation(const char *opcode, instruction_t *mapped)
{
	int i = 0;

	while (mapped[i].opcode)
	{
		if (!strcmp(mapped[i].opcode, opcode))
			return (mapped[i].f);
		i++;
	}

	/* For commenting of lines only */
	if (!strncmp(opcode, "#", 1))
		return (comment);

	return (NULL);
}

/**
 * getMin - Check if the stack contains at least 2 node
 *
 * Return: The minimum node the stack contains
 * which are 0, 1 and 2
 */
int getMin(void)
{
	short count;
	stack_t *temp = reference.tail;

	count = 0;
	while (temp && count < 2)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
