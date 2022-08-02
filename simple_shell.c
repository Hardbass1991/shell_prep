#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *line = NULL;
	char **args;
	int success, status, i = 0;
	pid_t parent;
	extern char **environ;

	while (1)
	{
		args = tokenize_line(line);
		while (args[i])
		{
			printf("%s %ld\n", args[i], strlen(args[i]));
			i++;
		}
		if (!strncmp(args[0], "exit", 4))
			return (0);
		if (args[0][0] != '/')
			args[0] = get_full_command(args[0]);
		if (!args[0])
			continue;
		parent = fork();
		if (!parent)
		{
			if (!strcmp(args[0], "env"))
			{
				print_env();
				return (0);
			}
			success = execve(args[0], args, environ);
			if (success)
			{
				printf("%s: No such file or directory\n", argv[0]);
				return (-1);
			}
				return (0);
		}
		else
		{
			wait(&status);
		}
		free(args);

	}
	free(line);
	return (0);
}
