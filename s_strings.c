#include "monty.h"

/**
 * print_char - Prints the Ascii(a) value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int a;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	a = (*stack)->n;
	if (a < 0 || a > 127)
		string_err(10, line_number);
	printf("%c\n", a);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int a;
	stack_t *p;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	p = *stack;
	while (p != NULL)
	{
		a = p->n;
		if (a <= 0 || a > 127)
			break;
		printf("%c", a);
		p = p->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *p;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	p = *stack;
	while (p->next != NULL)
		p = p->next;

	p->next = *stack;
	(*stack)->prev = p;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *p;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	p = *stack;

	while (p->next != NULL)
		p = p->next;

	p->next = *stack;
	p->prev->next = NULL;
	p->prev = NULL;
	(*stack)->prev = p;
	(*stack) = p;
}
