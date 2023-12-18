#include "monty.h"
#include "utility.h"

/**
 * push - Push element on the stack
 *
 * @stack: Reference of the pointer to the first element
 * @line_number: The current line in the file
 *
 * Return: void (Nothing)
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *element = malloc(sizeof(stack_t));

	(void)line_number;

	/* failed to allocate memory */
	if (!element)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		deleteTokens(), delete_stack(stack);
		exit(EXIT_FAILURE);
	}

	element->n = atoi(reference.tokens[1]);
	element->next = NULL;
	element->prev = NULL;

	/* stack is empty */
	if (!*stack)
	{
		*stack = element;
		reference.front = *stack, reference.back = *stack;
		reference.head =  *stack, reference.tail = *stack;
	}
	else if (reference.mode)
	{ /* insertion for a queue */
		element->prev = reference.back;
		reference.back->next = element;
		element->next = NULL;
		reference.back = element;
	}
	else
	{ /* insertion at the beginning */
		(*stack)->prev = element;
		element->next = *stack;
		element->prev = NULL;
		*stack = element;
		reference.tail = *stack;
	}
}

/**
 * pall - Prints all element in the stack
 *
 * @stack: The stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse = *stack;

	(void)line_number;

	while (traverse)
	{
		printf("%d\n", traverse->n);
		traverse = traverse->next;
	}
}


/**
 * pint - Prints the value at the top of the stack
 *
 * @stack: A reference to The stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void pint(stack_t **stack, u_int line_number)
{
	/* unsude variables */
	(void)line_number;
	(void)stack;

	/* output last node data in the stack */
	printf("%d\n", reference.tail->n);
}

/**
 * pop - Removes the node at the top of the stack
 *
 * @stack: Reference to the stack
 * @line_number: Currnt line in the filei
 *
 * Return: void (Nothing)
 */
void pop(stack_t **stack, u_int line_number)
{
	stack_t *next = NULL;
	/* unused variables */
	(void)line_number;
	(void)stack;

	/* pop from top of stack */
	next = reference.tail->next;
	free(reference.tail);  /* delete current top */

	/* new top */
	*stack = next;
	reference.tail = *stack;

	if (reference.tail)
		reference.tail->prev = NULL;
}
/**
 * swap - Swaps the top two elements of the stack
 *
 * @stack: Reference to the stack
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void swap(stack_t **stack, u_int line_number)
{
	stack_t *temp2 = NULL;
	stack_t *temp1 = reference.tail->next->next;

	(void)line_number;  /* unused variable */

	/* second node next to first */
	reference.tail->next->next = reference.tail;

	/* second node previous to null */
	reference.tail->next->prev = NULL;

	/* point first node previous to second */
	reference.tail->prev  = reference.tail->next;

	/* point third node previous to first node */
	if (temp1)
		temp1->prev = reference.tail;

	temp2 = reference.tail->next;

	/* point first node next to third node */
	reference.tail->next = temp1;

	/* new top of stack */
	*stack = temp2;
	reference.tail = *stack;
}
