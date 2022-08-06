#include "main.h"
/**
 * get_num_words - gets number of words in an input string
 * @line: input string
 *
 * Return: word count
 */
int get_num_words(char *line)
{
	int i = 0, n = 1;

	while (line[i])
	{
		if (line[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

/**
 * tokenize_line - tokenizes an input string
 * @line: input string
 *
 * Return: array of tokens obtained from variable line
 */

char **tokenize_line(char *line)
{
	char *token;
	size_t len = 0, i, n;
	ssize_t read;
	char **argv;

	printf("ihatec$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
		return (NULL);

	n = get_num_words(line);

	argv = malloc((n + 1) * sizeof(char *));
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
		argv[i - 1][strlen(argv[i - 1]) - 1] = '\0';
		argv[i] = NULL;
	}
	else
	{
		argv[0] = token;
		argv[0][strlen(argv[0]) - 1] = '\0';
		argv[1] = NULL;
	}
	return (argv);
}
