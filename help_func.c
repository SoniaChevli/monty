#include "monty.h"

/**
 * _pint - prints the value at the top of the stack, followed by a new line.
 *
 * @head: pointer to an adress of the doubly linked list
 * @i: unused parameter
 *
 */
void _pint(stack_t **head, unsigned int i __attribute__ ((unused)))
{
	stack_t *tmp;

	tmp = *head;
	if (tmp == NULL)
		exit(0);
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
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
 * @pushnum: value of the lement to save
 *
 */
void _push(stack_t **head, unsigned int pushnum)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		_free(*head);
		exit(EXIT_FAILURE);
	}
	new->n = pushnum;
	new->next = *head;
	new->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = new;
	}
	*head = new;
}
