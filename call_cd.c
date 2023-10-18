#include "main.h"
/**
 * call_cd - Change directory function
 * @input: The directory to change to
 *
 * Return: 0 on success, 1 on failure
 */

int call_cd(char *input);
int call_cd(char *input)
{

	char buffer[1024];
	char *ptr;

	if (input != NULL)
	{
		if (opendir(input) != NULL)
		{
			if (chdir(input) == -1)
				return (1);
			ptr = getcwd(buffer, 1024);
			if (ptr == NULL)
				perror("getcwd");
			_setenv("PWD", ptr);
			return (0);
		}
		perror("./hsh");
		return (0);
	}
	chdir("/root");
	ptr = getcwd(buffer, 1024);
	if (ptr == NULL)
		perror("getcwd");
	_setenv("PWD", "/root");
	return (0);
}
