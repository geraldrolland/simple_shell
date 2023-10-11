#include "main.h"
int main(int ac, char **av)
{
	char *input=NULL;
	size_t size = 0;
	int isterminal=0;
	char *input_copy2, *input_copy3, *tok, *input_copy;
	(void)ac;
	while (1)
	{
		if (isatty(isterminal) != 0)
			write_str("$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			write_str("\n");
			break;
		}
		input_copy2 = _strdup(input);
		input_copy3 = _strdup(input);
		tok = strtok(input_copy2, " \t\r");
		if (_strcmp(tok, "exit\n") == 0)
			break;
		if (_strcmp(input, "\n") == 0 || _strcmp(tok, "\n") == 0)
		{
			free(input_copy2);
			continue;
		}
		free(input_copy2);
		if (compare_path(input_copy3) == 0)
			continue;
		input_copy = _strdup(input);
		if (input_cmd(input_copy) == 0)
			continue;
		print_error(input, input_copy, av);
		if (isterminal != 0)
			break;
		continue;
	}
	return 0;
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
int print_error(char *str1, char *str2, char **v)
{
	if (access(str1,F_OK & X_OK)==-1)
		write(2,v[0], strlen(v[0]));
	write(2, ": ", strlen(": "));
	perror("");
	free(str2);
	str2=NULL;
	str1 = NULL;
	return 1;
}
