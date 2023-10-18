#include "main.h"

/**
 * _strdup - Duplicates a string.
 * @str: The string to duplicate.
 *
 * Return: Pointer to the duplicated string or NULL if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *str1;
	int i, size = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		size++;
	}
	size++;

	str1 = malloc(sizeof(char) * size);

	for (i = 0; str[i] != '\0'; i++)
	{
		str1[i] = str[i];
	}
	str1[i] = '\0';
	return (str1);
}

/**
 * environ_cmd - Handles environmental commands.
 * @input: The user input.
 *
 * Return: 0 on success, 1 on failure.
 */
int environ_cmd(char *input)
{
	char *token = strtok(input, " \n\r\t");
	char *argv[100];
	int i = 0;

	argv[i] = token;
	i++;
	token = strtok(NULL, " \n\r\t");
	for (; token != NULL; i++)
	{
		argv[i] = token;
		token = strtok(NULL, " \n\r\t");
	}
	argv[i] = NULL;
	if (_strcmp(argv[0], "env") == 0 && argv[1] == NULL)
	{
		env();
		free(input);
		return (0);
	}
	if (_strcmp(argv[0], "setenv") == 0 && argv[1] != NULL && argv[2] != NULL
			&& argv[3] == NULL)
	{
		_setenv(argv[1], argv[2]);
		free(input);
		return (0);
	}
	if (_strcmp(argv[0], "unsetenv") == 0 && argv[1] != NULL
			&& argv[2] == NULL)
	{
		if (_unsetenv(argv[1]) == 0)
		{
			free(input);
			return (0);
		}
		free(input);
		return (1);
	}
	if (_strcmp(argv[0], "cd") == 0 && ((argv[1] == NULL || argv[1] != NULL) || argv[2] == NULL))
		{
			call_cd(argv[1]);
			free(input);
			return (0);
		}
	free(input);
	return (1);
}
int _atoi(char *str)
{
	int arr_num[]={0,1,2,3,4,5,6,7,8,9};
	char arr_str[]="0123456789";
	int i,j,k, num=0, temp1;
	for (k=0; *(str+k)!='\0'; k++)
	{
		if ((*(str+k)<'0' || *(str+k)>'9') && (*(str+k)!='-'))
			return 0;
		if (*(str+k)=='-' && k!=0)
			return 0;
		continue;
	}
	if (*(str)=='-')
	{
		i=1;
	}
	else
	{
	i=0;
	}
	for (; *(str+i)!='\0'; i++)
	{
		for (j=0; *(arr_str +j)!='\0'; j++)
		{
			if (*(str+i)==*(arr_str+j))
			{
				temp1=*(arr_num+j);
				break;
			}
			continue;
		}
		num=num+temp1;
		if (*(str+i+1)=='\0'){
			break;
		}
		num=num*10;

	}
	if (*(str)=='-')
	{
		num=num*(-1);
		return num;
	}
	return num;
}
void _exit_status(char *input)
{
	char *token;
	int status, i;
	if (input!=NULL)
	{
		i=0;
		token = strtok(input, " \n\r\t");
		for (; token!=NULL;i++)
		{
			if(i==1)
			{
				status = _atoi(token);
				free(input);
				exit(status);
			}
			token =strtok(NULL, " \n\t\r");
		}
		exit(1);
	}
}
