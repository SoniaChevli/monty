#include "monty.h"

/**
 * _swap - swaps the top two elements in stack
 *@head: pointer to the doubly linked list
 *@line_num: keeps track of line number
 */
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if ((*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*head)->next;
	if ((*head)->next->next == NULL)
	{
		(*head)->next = NULL;
	}
	else
		(*head)->next = (*head)->next->next;

	tmp->prev = NULL;

	(*head)->prev = tmp;

	tmp->next = *head;

	*head = tmp;
}
/**
 * _pop - removes the top element
 * @head: pointer to the doubly linked list
 * @line_num: keeps track of line number
 *
 */
void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	if (head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if ((*head)->next != NULL)
	{
		*head = (*head)->next;

		(*head)->prev = NULL;
		free(tmp);
	}
	else
	{
		free(tmp);
		*head = NULL;
	}
}
/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 *
 * @head: pointer to an adress of the doubly linked list
 * @line_num: line number count
 *
 */
void _pint(stack_t **head, unsigned int line_num)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp == NULL)
	{
		printf("L%d: can't pint, stack empty\n", line_num);
		_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", tmp->n);
}

/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack.
 *
 * @head: pointer to an adress of the doubly linked list
 * @i: unused parameter
 *
 */
void _pall(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	stack_t *tmp;
	int count = 0;

	tmp = *head;

	while (tmp != NULL)
	{

		printf("%d\n", tmp->n);
		count++;
		tmp = tmp->next;
	}
}

/**
 * _push - pushes an element to the stack.
 *
 * @head: pointer to an adress of the doubly linked list
 * @line_num: value of the lement to save
 *
 */
void _push(stack_t **head, unsigned int line_num __attribute__ ((unused)))
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		_free(*head);
		exit(EXIT_FAILURE);
	}
	new->n = tokennum;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
}