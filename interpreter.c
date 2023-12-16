#include "monty.h"
#include "utility.h"

/**
 * interpret - Inteprets line by line
 *
 * @file: The file that contains Monty byte code
 * @stack: The stack
 *
 * Return: void (Nothing)
 */
void interpret(FILE *file, stack_t **stack)
{
	size_t n;
	Op_func operation;
	char *line = NULL;
	memory_record memory;
	u_int line_number = 1;
	instruction_t *mapped = create_map_structure(file);

	memory.file = file;
	memory.mapped = mapped, memory.stack = NULL;

	while (getline(&line, &n, file) > 0)
	{
		initialize_record(&memory, stack, line);  /* store allocated address */

		if (parse_line(&memory, line))
		{
			free_line(&line), line_number++;
			continue;
		}
		/* get the operation to execute */
		operation = get_operation(reference.tokens[0], mapped);

		/* checks if the instruction is valid */
		if (check_instruction(operation, reference.tokens[0], line_number))
			free_records(&memory), exit(EXIT_FAILURE);

		/* check if error occurred with the operations */
		handle_errors(&memory, line_number);

		/* call the function that is mapped to the upcode */
		operation(stack, line_number);

		free_line(&line), deleteTokens();
		line_number++;
	}

	free_line(&line);
	memory.line = NULL;
	free_records(&memory);
}

/**
 * get_operation - Get the function that correctly maps to the opcode
 *
 * @opcode: The opcode
 * @mapped: The structure that maps opcode to function
 *
 * Return: The function
 */
Op_func get_operation(const char *opcode, instruction_t *mapped)
{
	int i = 0;

	while (mapped[i].opcode)
	{
		if (!strcmp(mapped[i].opcode, opcode))
			return (mapped[i].f);
		i++;
	}

	return (NULL);
}

/**
 * create_map_structure - Creates a map structure that maps
 * opcode to it respective functions and store in an array
 *
 * @file: Bytecode file
 *
 * Return: The array
 */
instruction_t *create_map_structure(FILE *file)
{
	int i;

	char *opcodes[] = {"push", "pop", "pall", "pint",
		"add", "sub", "div", "swap", "nop", NULL};
	Op_func const operations[] = {push, pop, pall, pint,
		add, sub, _div, swap, nop, NULL};

	instruction_t *mapped = malloc(sizeof(instruction_t) * 10);
	/* Memory allocation failed */
	if (!mapped)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	/* Assign */
	i = 0;
	while (opcodes[i])
	{
		mapped[i].opcode = opcodes[i];
		mapped[i].f = operations[i];
		i++;
	}

	/* NULL terminate */
	mapped[i].opcode = NULL;
	mapped[i].f = NULL;

	return (mapped);
}
