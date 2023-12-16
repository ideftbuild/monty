#include "monty.h"

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
		reference.head =  *stack;
		reference.tail = reference.head;
	}
	else
	{
	/* insertion at the beginning */
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
 * delete_stack - Deletes the stack
 *
 * @stack: Reference of the pointer to the first element
 *
 * Return: void (Nothing)
 */
void delete_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp)
	{
		stack_t *next = temp->next;

		temp->prev = NULL;

		free(temp);

		temp = next;
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
