#include "main.h"
/**
 * PATH_to_dirs - returns string with value of variable PATH
 *
 * Return: string with value of PATH
 */
char *PATH_to_dirs()
{
	char *this_name, *line;
	int i = 0;

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
	free(this_name);
	return (line);
}

/**
 * get_full_command - searches for an input command in each
 * directory of PATH
 * @command: input command
 *
 * Return: command with directory if founf, NULL otherwise
 */
char *get_full_command(char *command)
{
	char *line, *token, *check_com;
	size_t n, command_found = 0;
	list_t *paths, *ptr;
	struct stat st;

	line = PATH_to_dirs();

	paths = NULL;
	token = strtok(line, ":");
	while (token != NULL)
	{
		add_node_end(&paths, token);
		token = strtok(NULL, ":");
	}
	ptr = malloc(sizeof(list_t));
	free(line);
	ptr = paths;
	while (ptr)
	{
		n = strlen(ptr->str);
		check_com = malloc(n + strlen(command) + 2);
		strncpy(check_com, ptr->str, n);
		check_com[n] = '/';
		strcpy(check_com + n + 1, command);
		if (stat(check_com, &st) == 0)
		{
			command_found = 1;
			break;
		}
		ptr = ptr->next;
	}
	if (command_found)
		return (check_com);
	return (NULL);
}
