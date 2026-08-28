#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *saved_head;
	unsigned int p;

	if (head == NULL || *head == NULL)
		return (-1);

	saved_head = *head;

	/* Case 1: Delete head node (index 0) */
	if (index == 0)
	{
		*head = saved_head->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(saved_head);
		return (1);
	}

	/* Traverse to node at target index */
	p = 0;
	while (p < index && saved_head != NULL)
	{
		saved_head = saved_head->next;
		p++;
	}

	/* Index out of bounds */
	if (saved_head == NULL)
		return (-1);

	/* Case 2: Delete middle or last node */
	saved_head->prev->next = saved_head->next;

	if (saved_head->next != NULL)
		saved_head->next->prev = saved_head->prev;

	free(saved_head);
	return (1);
}
