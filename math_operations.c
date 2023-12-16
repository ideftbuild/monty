#include "monty.h"
#include "utility.h"

/**
 * add - Adds the top two elements of the stack
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void add(stack_t **stack, u_int line_number)
{
	int num1, num2, result;

	(void)line_number;  /* unsused variable */

	/* Get the integer */
	num1 = reference.tail->n;
	num2 = reference.tail->next->n;

	result = num1 + num2; /* sum */

	pop(stack, line_number); /* remove top of node*/

	reference.tail->n = result;  /* new top node containing result */
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
 * sub - Subtracts the top element of the stack from the second
 * top element of the stack
 *
 * @stack: Reference to the stack
 * @line_number: line_number
 *
 * Return: void (Nothing)
 */
void sub(stack_t **stack, u_int line_number)
{
	int num1, num2, result;

	(void)line_number;  /* unsused variable */

	/* Get the integer */
	num1 = reference.tail->n;
	num2 = reference.tail->next->n;

	result = num2 - num1; /* sum */

	pop(stack, line_number); /* remove top of node*/

	reference.tail->n = result;  /* new top node containing result */
}

/**
 * _div - Divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: Reference to the stack
 * @line_number: line_number
 *
 * Return: void (Nothing)
 */
void _div(stack_t **stack, u_int line_number)
{
	double num1, num2;
	double result;

	(void)line_number;  /* unsused variable */

	/* Get the integer */
	num1 = reference.tail->n;
	num2 = reference.tail->next->n;

	result = num2 / num1; /* sum */

	printf("%f / %f = %f\n", num2, num1, result);
	pop(stack, line_number); /* remove top of node*/

	reference.tail->n = result;  /* new top node containing result */
}
