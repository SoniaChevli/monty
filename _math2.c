#include "monty.h"
/**
 * _mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 *@head: pointer to the head of the linked list
 *@line_num: line number
 */
void _mod(stack_t **head, unsigned int line_num)
{
	unsigned int mod = 0;
	stack_t *tmp;

	if ((*head) == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		printf("L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	mod = (*head)->next->n % (*head)->n;
	(*head)->next->n = mod;

	*head = (*head)->next;
	(*head)->prev = NULL;

	free(tmp);
}

/**
 * _pchar - prints the char at the top of the stack, followed by a new line.
 *
 *@head: pointer to the head of the linked list
 *@line_num: line number
 */
void _pchar(stack_t **head, unsigned int line_num)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
