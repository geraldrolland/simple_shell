#include "main.h"

/**
 * compare_path - Compares a given path and executes if found.
 * @str: The input string.
 *
 * Return: 0 on success, 1 on failure.
 */
int compare_path(char *str)
{
	char *str1 = _strdup(str);
	char *token = strtok(str1, " \n\t\r");
	struct stat buffer;

	if (stat(token, &buffer) != -1)
	{
		return (_fork_proc(str, str1, token));
	}
	free(str1);
	return (input_cmd(str));
}

/**
 * _fork_proc - Forks a child process and executes a command.
 * @str: The input string.
 * @str1: A duplicate of the input string.
 * @token: The tokenized command.
 *
 * Return: 0 on success, 1 on failure.
 */
int _fork_proc(char *str, char *str1, char *token)
{
	pid_t pid = 0;
	int i = 0;
	char *argv[100];

	argv[i] = token;
	i++;
	token = strtok(NULL, " \n\t\r");
	for (; token != NULL; i++)
	{
		if (*token == '#')
			break;
		argv[i]=token;
		token =strtok(NULL, " \n\t\r");
	}
	argv[i] = NULL;
	free(str);
	pid = fork();
	/*free(str);*/
	if (pid == -1)
	{
		perror("fork");
		free(str1);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
	free(str1);
	return (0);
}
