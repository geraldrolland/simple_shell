#include "main.h"
<<<<<<< HEAD
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
			/*free(variable_value);*/
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
	/*free(variable_value);*/
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
			return 0;
		}
		free(token);
	}
	return 1;
}
int env(void)
=======
/**
  * env - enviromental variable
 *
 */
void env(void)
>>>>>>> 4cbba174815029f43d6c481e0be12c3da8768995
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return 0;
}
