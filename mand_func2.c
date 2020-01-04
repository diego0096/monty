#include "monty.h"
/**
 *_swap - swap the first 2 elements.
 *
 *@stack: double pointer to the head of stack
 *@line_number: line number.
 */
void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *t;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
		}
		t = (*stack)->next;
		(*stack)->prev = t;
		(*stack)->next = t->next;
		t->prev = NULL;
		if (t->next != NULL)
			t->next->prev = *stack;
			t->next = *stack;
			*stack = t;
}

/**
 *_add - add the first 2 elements.
 *@stack: double pointer that point to the head of stack.
 *@line_number: line number.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *t;
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	t = *stack;
	s = t->n + t->next->n;
	t->next->n = s;
	*stack = t->next;
	free(t);
}

/**
 *_nop - it does't do anything.
 *
 *@stack: double pointer that point to the head of stack.
 *@line_number: line number.
 *
 */
void _nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
