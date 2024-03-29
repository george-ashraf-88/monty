#include "monty.h"


/**
 * add_to_stack - Adds a node to the stack.
 * @new_node: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */

void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *p;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	p = head;
	head = *new_node;
	head->next = p;
	p->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */

void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	p = *stack;
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	p = *stack;
	*stack = p->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(p);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */

void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
