#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * add_node_end - adds node at the end of input linked list
 * @head: pointer to first element of list
 * @str: string that will be given as as value to element of list
 *
 * Return: pointer to first element of list
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *end_node, *last;

	end_node = malloc(sizeof(list_t));
	if (!end_node)
	{
		free(end_node);
		return (NULL);
	}
	end_node->str = strdup(str);
	end_node->next = NULL;

	if (!*head)
	{
		*head = end_node;
		return (*head);
	}
	else
	{
		last = *head;
		while (last->next)
			last = last->next;
		last->next = end_node;
	}
	return (last);
}
