#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char *argv[], char *envp[])
{
	char *lit_path;
	int i = 0;

	for (char **env = envp; *env != 0; env++)
	{
		char *thisEnv = *env;
		lit_path = malloc(5);
		strncpy(lit_path, thisEnv, 4);
		if (!strcmp(lit_path, "PATH"))
		{
			thisEnv += 5;
			while (thisEnv[i])
			{
				if (thisEnv[i] == ':')
					putchar('\n');
				else
					putchar(thisEnv[i]);
				i++;
			}
		}
	}
	putchar('\n');
	return 0;
}
