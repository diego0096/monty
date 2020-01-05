#include "monty.h"
/**
 *_sub - subtracts the first 2 elements
 *
 *@stack: double pointer that point to the head of stack
 *@line_number: line number
 *
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *t;
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	res = t->next->n - t->n;
	t->next->n = res;
	*stack = t->next;
	free(t);
}

/**
 *_div - divide the second first element.
 *
 *@stack: double pointer that point to the head of stack
 *@line_number: line number
 *
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *t;
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	if (t->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	res = t->next->n / t->n;
	t->next->n = res;
	*stack = t->next;
	free(t);
}

/**
 *_mul - mul the first 2 elements.
 *
 *@stack: double pointer that point to the head of stack
 *@line_number: line number
 *
 */
void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *t;
	int res;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	res = t->next->n * t->n;
	t->next->n = res;
	*stack = t->next;
	free(t);
}
