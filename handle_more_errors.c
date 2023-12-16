#include "monty.h"
#include "utility.h"

/**
 * sub_error - Handle error for sub opcode
 *
 * @memory: Stores memory address that was allocated
 * @line_number: Current line in the file
 *
 * Return: void (Nothing)
 */
void sub_error(memory_record *memory, u_int line_number)
{
	short count;
	stack_t *temp = *(memory->stack);

	/* Check if number of nodes is at least 2 */
	count = 0;
	while (temp && count < 2)
	{
		temp = temp->next;
		count++;
	}

	/* number of node is less than 2, so can't swap */
	if (count != 2)
	{
		dprintf(STDERR_FILENO, "L%d: can't add, stack too short\n", line_number);
		free_records(memory), deleteTokens();
		exit(EXIT_FAILURE);
	}
}
