#include "main.h"

int call_cd(char *input);
int call_cd(char *input)
{

	char buffer[1024];
	char *ptr;
	/*char buff[1024];
	char *argv[3];*/
	/*char *prev_dir;
	prev_dir = getcwd(buff, 1024);*/
	/*argv[0]=prev_dir;*/
	if (input!=NULL)
	{
		if(opendir(input)!=NULL)
		{
		/*prev_dir = getcwd(buff, 1024);
		if (_strcmp(input, "-")==0)
		{
		}*/
		if (chdir(input) == -1)
			return 1;
		ptr = getcwd(buffer, 1024);
		if (ptr==NULL)
			perror("getcwd");
		_setenv("PWD", ptr);
		return 0;
		}
		perror("./hsh");
		return 0;
	}
	chdir("/root");
	ptr = getcwd(buffer, 1024);
	if (ptr==NULL)
		perror("getcwd");
	_setenv("PWD", "/root");
	return 0;
}
