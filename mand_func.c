#include "monty.h"
/**
 *_push - push a new node at the end of the stack
 *
 *@stack: double pointer to the head of the stack
 *@line_number: line number
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t *nw;
	char *number;

	number = strtok(NULL, DELIMS);
	if (number == NULL || (!isdigit(number[0]) && number[0] != '-'))
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	nw = malloc(sizeof(stack_t));
	if (nw == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	nw->n = atoi(number);
	nw->prev = NULL;
	nw->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = nw;
	*stack = nw;
}

/**
 *_pall - print all the values from the stack
 *
 *@stack: double pointer point to the head of stack
 *@line_number: line number
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *t = *stack;

	(void) line_number;

	while (t != NULL)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}

/**
 *_pint - print the value at the top of the stack
 *
 *@stack: double pointer to the head of the stack
 *@line_number: line number
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 *_pop - remove the first element.
 *
 *@stack: double pointer that point to the head of the stack
 *@line_number: line number
 */
void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (*stack == NULL || stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	(*stack) = (*stack)->next;
	free(t);
}
