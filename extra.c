#include "monty.h"

/**
 * check_instruction - Checks if the instruction passed is valid
 *
 * @operation: Operation to perform
 * @opcode: The opcode
 * @line_number: current line number
 *
 * Return: 1 if the instruction is unknown, 0 otherwise
 */
int check_instruction(Op_func operation, char *opcode, u_int line_number)
{
	/* instruction is not valid */
	if (!operation)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
				line_number, opcode);
		deleteTokens();
		return (1);
	}

	return (0);
}

/**
 * display - Displays the data stored in tokens
 *
 * Return: void (Nothing)
 */
void display(void)
{
	int i = 0;

	while (reference.tokens[i])
		printf("%s\n", reference.tokens[i++]);
}

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
