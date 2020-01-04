#include "monty.h"

/* global struct {stack, line, file} */
state_t global = {NULL, NULL, NULL};

/**
 * main - entry point to program
 * @argc: number of arguments passed to program
 * @argv: ref to array of arguments passed to program
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	size_t lenght = 0, num = 0;

	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	atexit(free_at_exit);
	while (getline(&global.line, &lenght, global.file) != -1)
		exec_line_ops(global.line, ++num);
	return (EXIT_SUCCESS);
}
