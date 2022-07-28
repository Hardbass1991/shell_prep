#include <stdio.h>
int main(__attribute__((unused)) int argc, char *argv[])
{
	int i = 1;

	while (argv[i])
		printf("%s\n", argv[i++]);
	return (0);
}
