#include "monty.h"

/**
 * freeMem - Free memories allocated
 *
 * @file: Bytcode file
 * @mapped: The structure maps opcode to function
 * @line: Text from file
 *
 * Return: void (Nothing)
 */
void freeMem(FILE *file, instruction_t *mapped, char *line)
{
	fclose(file);
	free(line);
	free(mapped);
}

/**
 * deleteTokens - Frees a 2D array
 *
 * Return: void (Nothing)
 */
void deleteTokens(void)
{
	int i = 0;
	/* free individual array */
	while (reference.tokens[i])
		free(reference.tokens[i++]);

	free(reference.tokens);
}

/**
 * free_records - Frees all the memory that was previously allocated
 *
 * @memory: The structure that holds this memory address
 *
 * Return: void (Nothing)
 */
void free_records(memory_record *memory)
{
	fclose(memory->file);

	if (memory->stack)
		delete_stack(memory->stack);

	if (memory->mapped)
		free(memory->mapped);

	if (memory->line)
		free(memory->line);
}

/**
 * free_line - Free @line
 *
 * @line: Current text in the file line
 *
 * Return: void (Nothing)
 */
void free_line(char **line)
{
	free(*line);
	*line = NULL;
}
