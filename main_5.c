
int _setenv(const char *name, const char *value, int overwrite)
{
	extern char **environ;
	char *this_name, *new_var;
	int i = 0, j = 0, existed = 0, len;

	n = strlen(name);
	new_var = malloc(n + strlen(value) + 2);
	if (!new_var)
		return -1;
	strncpy(new_var, name, n);
	new_var[n] = '=';
	strcpy(new_var + n + 1, value);
	while (environ[i])
	{
		while (environ[i][j])
		{
			if (environ[i][j] == '=')
			{
				j++;
				break;
			}
			j++;
		}
		strncpy(this_name, environ[i], j);
		if (!strcmp(this_name, name))
		{
			existed = 1;
			if (overwrite)
				environ[i] = new_var;
			break;	
		}
		i++;	
	}
	// if existed = 0, append new_var
	// What is the length of environ tho?
	if (!existed)
	{
		environ[i] = new_var;
		environ[i + 1] = NULL;
	}
	free(new_var);
	return 0;
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return 1;
	_setenv(argv[1], argv[2], atoi(argv[3]));
	return 0;
}
