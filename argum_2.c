#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char *line = NULL, *token;
	size_t len = 0, i = 0, n = 0;
	ssize_t read;
	char **argv;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
			break;
		printf("%s", line);
		while (line[i])
		{
			if (line[i] == ' ')
				n++;
			i++;	
		}
		n++;
		argv = malloc(n * sizeof(char *) + 1);

		token = strtok(line, " ");
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		i = 0;
		while (argv[i])
		{
			printf("argv[%ld]: %s\n", i, argv[i]);
			i++;
		}
		free(line);
	}
	return 0;
}
