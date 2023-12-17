#include "monty.h"
#include "utility.h"

/**
 * comment - When the first non-space character of a line is #,
 * treat this line as a comment
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void comment(stack_t **stack, u_int line_number)
{ (void)stack, (void)line_number; }

/**
 * pchar - Prints the char at the top of the stack
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void
 */
void pchar(stack_t **stack, u_int line_number)
{
	/* unsused variables */
	(void)line_number;

	printf("%c\n", (*stack)->n);
}

/**
 * pstr - Prints the string starting at the top of stack
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void
 */
void pstr(stack_t **stack, u_int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;

	while (temp)
	{
		int c = temp->n;

		if (!c)
			break;
		else if (c < 0 || c > 127)
			break;

		printf("%c", temp->n);

		temp = temp->next;
	}
	putchar('\n');
}
