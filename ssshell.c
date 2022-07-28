#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **argv;

	while (1)
	{
		printf("#ihatec$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		argv = malloc(2 * sizeof(char *));
		argv[0] = malloc(strlen(line));
		strncpy(argv[0], line, strlen(line) - 1);
		printf("%s %ld", argv[0], strlen(argv[0]));
		argv[1] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
			perror("Error");
		free(argv);
	}
	free(line);
	return (0);
}
