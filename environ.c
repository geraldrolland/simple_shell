#include "main.h"
int _setenv(char *variable_name, char *variable_value)
{
	int i;
	for (i=0; environ[i]!=NULL; i++)
	{
		char *token=strdup(environ[i]);
		char *tok=strtok(token, "=");
		if(_strcmp(variable_name, tok)==0)
		{
			variable_name=_strcat(variable_name, "=");
			variable_value = _strcat(variable_name, variable_value);
			environ[i]=variable_value;
			free(variable_name);
			free(token);
			token=NULL;
			return 1;
		}
		free(token);
		token=NULL;
	}
	variable_name=_strcat(variable_name, "=");
	variable_value = _strcat(variable_name, variable_value);
	environ[i]=variable_value;
	environ[i+1]=NULL;
	free(variable_name);
	return 0;
}
int _unsetenv(char *variable_name)
{
	int i;
	for (i=0; environ[i]!=NULL;i++)
	{
		char *token=_strdup(environ[i]);
		char *tok=strtok(token, "=");
		if (_strcmp(variable_name, tok)==0)
		{
			free(token);
			for (; environ[i]!=NULL; i++)
			{
				environ[i]=environ[i+1];
			}
			/*printf("error");*/
			return 0;
		}
		free(token);
	}
	return 1;
}
int env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
