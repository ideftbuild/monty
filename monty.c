#include "monty.h"
#include "utility.h"

struct store reference;

/**
 * main - An interpreter for monty bytecode
 *
 * @ac: Number of arguments passed
 * @av: The arguments
 *
 * Return: Always 0 (Succes)
 */
int main(int ac, char **av)
{
	FILE *file = NULL;
	stack_t *stack = NULL;

	check_usage(ac);

	file = open_file(av[1]);

	interpret(file, &stack);

	return (0);
}
