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
