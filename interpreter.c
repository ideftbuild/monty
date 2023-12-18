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

	char *opcodes[] = {"stack", "queue", "push", "pop", "pall", "pint",
		"add", "sub", "div", "mul", "mod", "swap", "pchar", "pstr",
		"#", "rotl", "rotr", "nop", NULL};
	Op_func const operations[] = {stack, queue, push, pop, pall, pint,
		add, sub, _div, mul, mod, swap, pchar, pstr, comment, rotl,
		rotr, nop, NULL};

	instruction_t *mapped = malloc(sizeof(instruction_t) * 19);
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
