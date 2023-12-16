#include "monty.h"
#include "utility.h"

/**
 * push_error - Handler error for push opcode
 *
 * @memory: Stores memory address that was allocated
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void push_error(memory_record *memory, u_int line_number)
{
	/* an integer is not passed */
	if (!reference.tokens[1] || !digits(reference.tokens[1]))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
}

/**
 * pint_error - Handles error for pint opcode
 *
 * @memory: Stores memory address that was allocated
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void pint_error(memory_record *memory, u_int line_number)
{
	/* stack is empty so can't pint */
	if (!reference.tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
}

/**
 * pop_error - Handles error for pop opcode
 *
 * @memory: Stores memory address that was allocated
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void pop_error(memory_record *memory, u_int line_number)
{
	/* stack is empty so can't pop */
	if (!reference.tail)
	{
		dprintf(STDERR_FILENO, "L%d: can't pop an empty stack\n", line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
}
