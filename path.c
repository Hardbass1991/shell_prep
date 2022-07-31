#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
int main()
{
	char *line, *this_name, *token;
	size_t i = 0;
	extern char **environ;
	list_t *paths, *ptr;

	while (environ[i])
	{
		printf("%sAAAAA\n", environ[i]);
		this_name = malloc(5);
		strncpy(this_name, environ[i], 4);
		printf("%s\n", this_name);
		if (!strcmp(this_name, "PATH"))
		{
			line = malloc(strlen(environ[i]) + 1 - 5);
			strcpy(line, environ[i] + 5);
			break;
		}
		i++;
	}
	printf("%s\n", line);
	paths = NULL;
	token = strtok(line, ":");
	while (token != NULL)
	{
		add_node_end(&paths, token);
		//printf("%s\n", added_node->str);
		token = strtok(NULL, ":");
		i++;
	}
	ptr = malloc(sizeof(list_t));
	ptr = paths;
	while (ptr)
	{
		printf("%s\n", ptr->str);
		ptr = ptr->next;
	}
	free(line);
	return 0;
}
