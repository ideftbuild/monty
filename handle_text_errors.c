#include "monty.h"
#include "utility.h"

/**
 * pchar_error - Prints the char at the top of the stack
 *
 * @memory: Stores memory address that was allocated
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void pchar_error(memory_record *memory, u_int line_number)
{
	int n;

	/* stack is empty so can't pchar */
	if (!reference.tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, stack empty\n",
				line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
	n = reference.tail->n;

	/* ascii range */
	if (n < 0 || n > 127)
	{
		dprintf(STDERR_FILENO, "L%d: can't pchar, value out of range\n",
				line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
}
