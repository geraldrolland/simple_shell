#include "main.h"

/**
 * _setenv - Set an environment variable
 * @variable_name: The name of the variable
 * @variable_value: The value to set
 *
 * Return: (1) if successful, (0) otherwise
 */

int _setenv(char *variable_name, char *variable_value)
{
	int i;

	for (i = 0 ; environ[i] != NULL; i++)
	{
		char *token = strdup(environ[i]);
		char *tok = strtok(token, "=");

		if (_strcmp(variable_name, tok) == 0)
		{
			variable_name = _strcat(variable_name, "=");
			variable_value = _strcat(variable_name, variable_value);
			environ[i] = variable_value;
			free(variable_name);
			free(token);
			token = NULL;
			return (1);
		}
		free(token);
		token = NULL;
	}
	variable_name = _strcat(variable_name, "=");
	variable_value = _strcat(variable_name, variable_value);
	environ[i] = variable_value;
	environ[i + 1] = NULL;
	free(variable_name);
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 * @variable_name: The name of the variable to unset
 *
 * Return: (0) if successful, (1) otherwise
 */
int _unsetenv(char *variable_name)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		char *token = _strdup(environ[i]);
		char *tok = strtok(token, "=");

		if (_strcmp(variable_name, tok) == 0)
		{
			free(token);
			for (; environ[i] != NULL; i++)
			{
				environ[i] = environ[i + 1];
			}
			return (0);
		}
		free(token);
	}
	return (1);
}

/**
 * env - Print the environment variables
 *
 * Return: Always (0)
 */
int env(void)

{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
