#include "monty.h"

/**
 *free_ex - free allocated memory at exit
 *Description: free memory
 */
void free_ex(void)
{
    free_stack_t(global.stack);
    fclose(global.file);
    if (global.line)
        free(global.line);
}

/**
 *free_stack_t - free top of the stack
 *@top: top of the stack
 */
void free_stack_t(stack_t *top)
{
    stack_t *t;

    while (top != NULL)
    {
        t = top;
        top = top->next;
        free(t);
    }
}
