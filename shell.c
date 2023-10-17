#include "main.h"
int no_input(char *input);
int handle_cmd (char *input_copy3, char *input_copy);
int main(void)
{
	char *input=NULL;
	size_t size = 0;
	int isterminal=0;
	char *input_copy2, *input_copy3,*tok, *input_copy;
	while (1)
	{
		if (isatty(isterminal) != 0)
			write_str("$ ");
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			break;
		}
		input_copy2 = _strdup(input);
		input_copy3 = _strdup(input);
		tok = strtok(input_copy2, " \t\r");
		if (_strcmp(tok, "exit\n") == 0)
		{
			free(input);
			free(input_copy3);
			free(input_copy2);
			break;
		}
		if (no_input(input_copy2)==0)
		{
			free(input_copy3);
			continue;
		}
		input_copy = _strdup(input);
		if (handle_cmd(input_copy3, input_copy)==0)
			continue;
		if (isterminal != 0)
			break;
		continue;
	}
	return 0;
}
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
int no_input(char *input)
{
	int count=0;
	char *token = strtok(input, " \n\r\t");
	for (; token!=NULL;)
	{
		count++;
		token = strtok(NULL, " \n\r\t");
	}
	count++;
	free(input);
	if (count == 1)
	{
		return 0;
	}
	return 1;
	
}
