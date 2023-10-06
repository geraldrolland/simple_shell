#include "main.h"
/*#include <stdio.h>

int main(void)
{
    int i;
    char *input = "ls -l /tmp"; // Input string
    char *input_copy = _strdup(input); // Make a copy of the input
    char **arr = init_argv(input_copy, NULL);

    for (i = 0; arr[i] != NULL; i++)
    {
        printf("%s\n", arr[i]);
    }

    free_mem(arr);
    free(input_copy); // Free the copied input
    return 0;
}*/
char **init_argv(char *str/*ls -l*/, unsigned int *ptr) /*{"ls", "-l", NULL}ptr=NULL*/
{
	char *str_cpy = _strdup(str);
	char **argv;
	char *token = strtok(str_cpy, " \n\r\t");
	unsigned int count = 0, i;

	while (token != NULL) 
	{
		count++;
		token = strtok(NULL, " \n\r\t");
		continue;
	}
	count++;
	argv = malloc(sizeof(char *) * count);

	if (ptr == NULL) {
		i = 0;
		argv[i] = strtok(str, " \n\r\t");
		i++;
		for (; i < count; i++) {
			argv[i] = strtok(NULL, " \n\r\t");
		}
		argv[i] = NULL;
		free(str_cpy);
		return argv;
	}

	i = 0;
	argv[i] = strtok(str, " \n\r\t");
	i++;
	for (; i < *ptr; i++) {
		argv[i] = strtok(NULL, " \n\r\t");
	}
	argv[i] = NULL;
	free(str_cpy);
	return argv;
}

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
	return str1;
}

int _str_len(char *str)
{
	int i, len = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}

/*void write_str(char *str) {
    write(STDOUT_FILENO, str, _str_len(str));
}*/
int free_mem(char **dptr)
{
	/*int i;*/
	/*for (i = 0; dptr[i] != NULL; i++) {
		free(dptr[i]);
	}*/
	free(dptr);
	return 1;
}
