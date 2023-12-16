#include "monty.h"

/**
 * open_file - Opens a file
 *
 * @file: The file
 *
 * Return: A file stream pointing to the opened file, otherwise
 * exit with failure if it fails to open
 */
FILE *open_file(const char *file)
{
	FILE *pFile = fopen(file, "r");

	if (!pFile)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	return (pFile);
}

