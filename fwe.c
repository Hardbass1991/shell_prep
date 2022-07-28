#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
	pid_t pids[5];
	int i, n = 5, status;
	pid_t pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	for (i = 0; i < n; i++)
	{
		if ((pids[i] = fork()) < 0)
		{
			perror("fork");
			abort();
		}
		else if (pids[i] == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			exit(0);
		}
	}
	while (n > 0)
	{
		pid = wait(&status);
		printf("Child %d exited with status %d\n", pid, status);
		n--;
	}
	return (0);
}
