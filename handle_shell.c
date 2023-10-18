
int handle_cmd (char *input_copy3, char *input_copy)
{
	struct stat buffer;
	char *userinput = _strdup(input_copy);
	if (environ_cmd(userinput)==0)
	{
		free(input_copy3);
		free(input_copy);
		return 0;
	}
	if (compare_path(input_copy3) == 0)
	{
		free(input_copy);
		return 0;
	}
	if (stat(input_copy, &buffer)==-1)
	{
		free(input_copy);
		perror("./hsh");
	}
	return 1;
}
unsigned int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return 1;
		}
		str1++;
		str2++;
	}
	return 0;
}

unsigned int _strlen(const char *str)
{
	unsigned int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

int write_str(char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
	return 0;
}
int handle_EOF(char *input)
{
	if (_strlen(input)>0)
	{
		free(input);
		return 0;
	}
	return 1;
}			
