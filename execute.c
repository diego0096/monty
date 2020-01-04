#include "monty.h"
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