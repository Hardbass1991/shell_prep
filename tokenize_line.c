#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
char **tokenize_line(char *line)
{
	char *token;
	size_t len = 0, i = 0, n = 0;
	ssize_t read;
	char **argv;

	printf("ihatec$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
		return (NULL);
	while (line[i])
	{
		if (line[i] == ' ')
			n++;
		i++;	
	}
	n++;
	argv = malloc((n + 1)* sizeof(char *));
	token = strtok(line, " ");
	i = 0;
	if (n > 1)
	{
		i = 0;
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " ");
			i++;
		}
		//printf("%s %ld\n", argv[i - 1], strlen(argv[i - 1]));
		argv[i - 1][strlen(argv[i - 1]) - 1] = '\0';
		//printf("%s %ld\n", argv[i - 1], strlen(argv[i - 1]));
		argv[i] = NULL;
	}
	else
	{
		argv[0] = token;
		//printf("%s %ld\n", argv[0], strlen(argv[0]));
		argv[0][strlen(argv[0]) - 1] = '\0';
		//printf("%s %ld\n", argv[0], strlen(argv[0]));
		argv[1] = NULL;
	}
	return (argv);
}
