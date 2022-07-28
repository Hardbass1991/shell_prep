#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[])
{
	char *var_name;

	if (argc != 2)
	{
		printf("Usage: _getenv [environment variable]\n");
		return 1;
	}
	for (char **env = envp; *env != 0; env++)
	{
		char *thisEnv = *env;
		int i = 0;

		while (thisEnv[i])
		{
			i++;
			if (thisEnv[i] == '=')
				break;
		}
		var_name = malloc(i + 1);
		strncpy(var_name, thisEnv, i);
		if (!strcmp(var_name, argv[1]))
		{
			printf("%s\n", thisEnv + i + 1);
			free(var_name);
			break;
		}
		free(var_name);
	}
	return 0;
}
