#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
int main(__attribute__((unused)) int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;
	int success, status;
	pid_t parent;

	while (1)
	{
		printf("#ihatec$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		args = malloc(2 * sizeof(char *));
		args[0] = malloc(strlen(line));
		strncpy(args[0], line, strlen(line) - 1);
		/*printf("%s %ld", args[0], strlen(args[0]));*/
		args[1] = NULL;

		parent = fork();
		if (!parent)
		{
			success = execve(args[0], args, NULL);
		
			if (success)
			{
				printf("%s: No such file or directory\n", argv[0]);
				return (-1);
			}
			else
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
