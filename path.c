#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[])
{
	char *lit_path;

	for (char **env = envp; *env != 0; env++)
	{
		char *thisEnv = *env;
		lit_path = malloc(5);
		strncpy(lit_path, thisEnv, 4);
		if (!strcmp(lit_path, "PATH"))
			printf("%s\n", thisEnv + 5);
	}
	return 0;
}
