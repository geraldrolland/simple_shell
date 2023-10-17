#include "main.h"
char *_strdup(char *str) {
	char *str1;
	int i, size = 0;

	for (i = 0; str[i] != '\0'; i++) {
		size++;
	}
	size++;

	str1 = malloc(sizeof(char) * size);

	for (i = 0; str[i] != '\0'; i++) {
		str1[i] = str[i];
	}
	str1[i] = '\0';
	return str1;
}

int _str_len(char *str) {
	int i, len = 0;
	for (i = 0; str[i] != '\0'; i++) {
		len++;
	}
	return len;
}
int environ_cmd(char *input)
{
	char *token = strtok(input, " \n\r\t");
	char *argv[100];
	int i=0;
	argv[i]=token;
	i++;
	token=strtok(NULL, " \n\r\t");
	for (; token!=NULL; i++)
	{
		argv[i]=token;
		token=strtok(NULL, " \n\r\t");
	}
	argv[i]=NULL;
	if (_strcmp(argv[0], "env")==0 && argv[1]==NULL)
	{
		env();
		free(input);
		return 0;
	}
	if (_strcmp(argv[0], "setenv")==0 && argv[1]!=NULL && argv[2]!=NULL && argv[3]==NULL)
	{
		_setenv(argv[1], argv[2]);
		free(input);
		return 0;
	}
	if (_strcmp(argv[0], "unsetenv")==0 && argv[1]!=NULL && argv[2]==NULL)
	{
		_unsetenv(argv[1]);
		free(input);
		return 0;
	}
	if (_strcmp(argv[0], "cd") == 0 && (argv[1]==NULL || argv[1]!=NULL) && argv[2]==NULL)
	{
		call_cd(argv[1]);
		free(input);
		return 0;
	}
	free(input);
	return 1;
}
