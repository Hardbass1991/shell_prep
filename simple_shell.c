#include "main.h"
/**
 * main - runs a shell
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if successful, -1 otherwise
 */
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *line = NULL, **args;
	int success, status;
	pid_t parent;

	while (1)
	{
		args = tokenize_line(line);
		if (!strncmp(args[0], "exit", 4))
			return (0);
		if (args[0][0] != '/')
		{
			args[0] = get_full_command(args[0]);
			if (!args[0])
			{
				printf("%s: No such file or directory\n", argv[0]);
				continue;
			}
		}
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
			wait(&status);
		free(args);
		free(line);
	}
	return (0);
}
