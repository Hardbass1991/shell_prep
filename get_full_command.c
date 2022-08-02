#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "main.h"
char *get_full_command(char *command)
{
	char *line, *this_name, *token, *check_com;
	size_t i = 0, n, command_found = 0;
	extern char **environ;
	list_t *paths, *ptr;
	struct stat st;

	while (environ[i])
	{
		this_name = malloc(5);
		strncpy(this_name, environ[i], 4);
		if (!strcmp(this_name, "PATH"))
		{
			line = malloc(strlen(environ[i]) + 1 - 5);
			strcpy(line, environ[i] + 5);
			break;
		}
		i++;
	}
	//printf("%s\n", line);
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
	ptr = paths;
	while (ptr)
	{
		n = strlen(ptr->str);
		check_com = malloc(n + strlen(command) + 2);
		strncpy(check_com, ptr->str, n);
		check_com[n] = '/';
		strcpy(check_com + n + 1, command);
		printf("%s\n", check_com);
		if (stat(check_com, &st) == 0)
		{
			command_found = 1;
			break;
		}
		ptr = ptr->next;
	}
	//printf("%ld\n", command_found);
	if (command_found)
		return (check_com);
	return (NULL);
}
