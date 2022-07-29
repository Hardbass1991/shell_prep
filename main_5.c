#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *this_name, *new_var;
	int n, i = 0, j, existed = 0;

	n = strlen(name);
	new_var = malloc(n + strlen(value) + 2);
	if (!new_var)
		return -1;
	strncpy(new_var, name, n);
	printf("%s\n", new_var);

	new_var[n] = '=';
	printf("%s\n", new_var);

	strcpy(new_var + n + 1, value);
	printf("%s\n", new_var);

	while (environ[i])
	{
		/*printf("%d\n", i);*/
		j = 0;
		while (environ[i][j])
		{
			/*printf("%d\n", j);*/
			if (environ[i][j] == '=')
			{
				j++;
				break;
			}
			j++;
		}
		this_name = malloc(j + 1);
		strncpy(this_name, environ[i], j);
		/*printf("%s\n", this_name);*/
		if (!strcmp(this_name, name))
		{
			existed = 1;
			if (overwrite)
				environ[i] = new_var;
			break;	
		}
		free(this_name);
		i++;	
	}
	// if existed = 0, append new_var
	// What is the length of environ tho?
	if (!existed)
	{
		environ[i] = new_var;
		environ[i + 1] = NULL;
	}
	return 0;
}

int main(int argc, char *argv[], char *envp[])
{
	int i = 0;
	extern char **environ;

	if (argc != 4)
		return 1;
	for (; environ[i]; i++)
		printf("%s\n", environ[i]);
	printf("-----------------------------------------------\n");
	_setenv(argv[1], argv[2], atoi(argv[3]));

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	
	return 0;
}
