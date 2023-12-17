#include "monty.h"
#include "utility.h"

/**
 * check_usage - Checks if the user matches the required usage
 *
 * @ac: Number of arguments passed must be exactly 1
 *
 * Return: void (Nothing)
 *
 * exit on failure
 */
void check_usage(int ac)
{
	if (ac != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}


/**
 * digits - Checks if a string contains only digit
 *
 * @str: The string
 *
 * Return: 1 on succes (all digits), otherwise 0
 */
int digits(char *str)
{
	if (*str == '-')  /* negative number */
		str++;

	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (0); /* not a number */

		str++;
	}

	return (1);  /* a number */
}

/**
 * parse_line - Parse the current line from a file
 *
 * @memory: Stores address of allocated memories
 * @line: The line read from the file
 *
 * Return: Vector
 */
int parse_line(memory_record *memory, char *line)
{
	 int size = 0, i;
	 const char *delim = " \t\n", *current;
	 char *copy = strdup(line);

	if (!copy)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_records(memory), free(copy);
		exit(EXIT_FAILURE);
	}
	 /* get number of tokens */
	size = getNumOfTokens(copy, delim);
	if (size < 0)
	{
		free(copy);
		return (1);
	}

	free(copy);
	/* allocate memory */
	reference.tokens = malloc(sizeof(char *) * (size));
	if (!reference.tokens)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		free_records(memory);
		exit(EXIT_FAILURE);
	}
	/* store tokens */
	current = strtok(line, delim);
	i = 0;
	while (current)
	{
		reference.tokens[i] = strdup(current);
		current = strtok(NULL, delim);
		i++;
	}

	reference.tokens[i] = NULL;

	return (0);
}

/**
 * handle_errors - Handles errors related to each operation
 *
 * @memory: The structure stores memory address and frees
 * when errors is encountered
 * @line_number: Current line_number in the file
 *
 * Return: void (Nothing)
 */
void handle_errors(memory_record *memory, u_int line_number)
{
	const char *opcode = reference.tokens[0];

	if (!strcmp(opcode, "push"))
		push_error(memory, line_number);
	if (!strcmp(opcode, "pint"))
		pint_error(memory, line_number);
	if (!strcmp(opcode, "pop"))
		pop_error(memory, line_number);
	if (!strcmp(opcode, "swap"))
		swap_error(memory, line_number);
	if (!strcmp(opcode, "add"))
		add_error(memory, line_number);
	if (!strcmp(opcode, "sub"))
		sub_error(memory, line_number);
	if (!strcmp(opcode, "div"))
		div_error(memory, line_number);
	if (!strcmp(opcode, "mul"))
		mul_error(memory, line_number);
	if (!strcmp(opcode, "mod"))
		mod_error(memory, line_number);
	if (!strcmp(opcode, "pchar"))
		pchar_error(memory, line_number);
	/* Handle other operation errors */
}

/**
 * initialize_record - Initializes the structure to store
 * memory address
 *
 * @memory: The structure to initialize the address to
 * @stack: The stack
 * @line: Text from the file
 *
 * Return: void (Nothing)
 */
void initialize_record(memory_record *memory, stack_t **stack, char *line)
{
	memory->line = line;
	memory->stack = stack;
}
