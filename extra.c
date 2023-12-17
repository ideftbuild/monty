#include "monty.h"
#include "utility.h"

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
 * nop - Doesn’t do anything.
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void nop(stack_t **stack, u_int line_number)
	{ (void)stack, (void)line_number; }

/**
 * rotl -  Rotates the stack to the top
 *
 * @stack: A reference to the stack
 * @line_number: Current line number
 *
 * Return: void
 */
void rotl(stack_t **stack, u_int line_number)
{
	(void)line_number;

	/* check if number of nodes is at least 2 */
	if (getMin() != MIN_NODE)
		return;

	/* rotate stack top */
	reference.head->next = reference.tail;
	reference.tail->prev = reference.head;

	reference.head = reference.tail;

	*stack = reference.tail->next;

	reference.tail->next->prev = NULL;
	reference.tail->next = NULL;

	reference.tail = *stack;  /* update tail */
}

/**
 * rotr - Rotates the stack to the bottom
 *
 * @stack: A reference to the stack
 * @line_number: Current line number
 *
 * Return: void
 */
void rotr(stack_t **stack, u_int line_number)
{
	stack_t *tail = reference.head;
	stack_t *head = NULL;

	/* check if stack is too short to rotate */
	if (getMin() != MIN_NODE)
		return;

	(void)line_number;

	/* rotate */
	head = reference.head->prev;

	reference.head->prev->next = NULL;
	reference.head->next = reference.tail;
	reference.tail->prev = reference.head;

	*stack = tail;
	reference.tail = *stack;
	reference.head = head;
}
