#include "monty.h"
#include "utility.h"

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

/**
 * queue -  sets the format of the data to a queue (FIFO).
 *
 * @stack: A reference to the stack
 * @line_number: Current line number
 *
 * Return: void
 */
void queue(stack_t **stack, u_int line_number)
{

	(void)stack;
	(void)line_number;

	reference.mode = QUEUE;
}

/**
 * stack -  sets the format of the data to a stack (LIFO).
 *
 * @stack: A reference to the stack
 * @line_number: Current line number
 *
 * Return: void
 */
void stack(stack_t **stack, u_int line_number)
{
	(void)stack;
	(void)line_number;

	reference.mode = STACK;
}
