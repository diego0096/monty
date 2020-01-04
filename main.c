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

	/* Check that exactly one file argument was given */
	if (argc != 2)
	{
		fputs("USAGE: monty file\n", stderr);
		exit(EXIT_FAILURE);
	}
	/* Try to open the file */
	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	/* Register call to memory cleanup wrapper function */
	atexit(free_at_exit);
	/* read every line in file and try executing it */
	while (getline(&global.line, &lenght, global.file) != -1)
		exec_line_ops(global.line, ++num);
	return (EXIT_SUCCESS);
}

/**
 *exec_line_ops - read line
 *@line: line
 *@num: number of line
 */
void exec_line_ops(char *line, size_t num)
{
	char *comm = strtok(line, DELIMS);

	if (comm && comm[0] != '#')
		fetch_instruction(comm, num);
}

/**
 *fetch_instruction - get line
 *@comm: command line
 *@num: number of line in file
 */
void fetch_instruction(char *comm, size_t num)
{
	int i = 0;

	static const instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{NULL, NULL}
	};
	for (; ops[i].opcode; ++i)
		if (strcmp(comm, ops[i].opcode) == 0)
		{
			ops[i].f(&global.stack, num);
			return;
		}
	fprintf(stderr, "L%d: unknown instruction %s\n", (int)num, comm);
	exit(EXIT_FAILURE);
}
