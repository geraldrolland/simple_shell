#include "main.h"
void env(void)
{
	int i;
	for (i=0; environ[i]!=NULL;i++)
	{
		write_str(environ[i]);
		write_str("\n");
	}
}
