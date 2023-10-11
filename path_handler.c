#include "main.h"
int compare_path(char *str)
{
	char *str1 = _strdup(str);
	char *token=strtok(str1, " \n\t\r");
	struct stat buffer;
	if (stat(token, &buffer)!=-1)
	{
		return(_fork_proc(str,str1,token));
	}
	free(str1);
	free(str);
	return 1;
}
int _fork_proc(char *str, char *str1, char *token)
{
	pid_t pid = 0;
	int i=0;
	char *argv[100];
	argv[i]=token;
	i++;
	token=strtok(NULL, " \n\t\r");
	for (; token!=NULL; i++)
	{
		argv[i]=token;
		token =strtok(NULL, " \n\t\r");
	}
	argv[i]=NULL;
	pid = fork();
	if (pid==-1)
	{
		perror("fork");
		free(str);
		free(str1);
		return 1;
	}
	if (pid == 0)
	{
		if (execve(argv[0],argv,NULL)==-1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	wait(NULL);
	free(str1);
	free(str);
	return 0;
}
