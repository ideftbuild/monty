#include "monty.h"

struct store reference;

int main(int ac, char **av)
{
	FILE *file = NULL;
	stack_t *stack = NULL;

	check_usage(ac);

	file = open_file(av[1]);

	interpret(file, &stack);

	return (0);
}
