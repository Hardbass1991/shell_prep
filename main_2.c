#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[])
{
	char *var_name;
	int n;

	if (argc != 2)
	{
		printf("Usage: _getenv [environment variable]\n");
		return 1;
	}
	n = strlen(argv[1]);
	for (char **env = envp; *env != 0; env++)
	{
		char *thisEnv = *env;
		var_name = malloc(n + 1);
		strncpy(var_name, thisEnv, n);
		if (!strcmp(var_name, argv[1]))
		{
			printf("%s\n", thisEnv + n + 1);
			free(var_name);
			break;
		}
		free(var_name);
	}
	return 0;
}
