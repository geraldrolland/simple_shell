#include "main.h"
#include <string.h>

int main(void)
{
    char *userinput = NULL;
    size_t size = 0;
    int isterminal = 0;
    ssize_t check;
    char *userinput_copy = NULL;
    char *token = NULL;
    char **argv = NULL;
    pid_t pid;

    while (1)
    {
	    isterminal = isatty(STDIN_FILENO);
	    if (isterminal !=0)
	    {
		    write_str("$ ");
	}
        check = getline(&userinput, &size, stdin);
        if (strcmp(userinput, "exit\n") == 1)
        {
            free(userinput);
            break;
        }
	if (check == -1)
        {
            free(userinput);
            break;
        }
	if (userinput == NULL)
            continue;
        userinput_copy = _strdup(userinput);
        token = strtok(userinput_copy, "\t\n\r ");

        if (strcmp(token, "ls") == 0)
        {
            free(userinput_copy);
            argv = init_argv(userinput, NULL);/*arg={"ls", "-l", NULL};*/
	    pid = fork();
            if (pid == -1)
            {
                perror("fork process failed");
                free_mem(argv);
                continue;
            }
            if (pid == 0)
            {
                if (execve("/bin/ls", argv, NULL) == -1)
                {
                    perror("not found");
                    free_mem(argv);
                    exit(EXIT_FAILURE);
                }
            }
            else
            {
                wait(NULL);
                free_mem(argv);
                if (isterminal == 0)
                    break;
                continue;
            }
        }
        /*perror("not found");
        free(userinput);
        free(userinput_copy);*/
        if (isterminal == 0)
            break;
        continue;
    }
    perror("not found");
    free(userinput);
    free(userinput_copy);
    return 0;
}
/*unsigned int _strcmp(char *str1, char *str2) {
    while (*str1 != '\0' && *str2 != '\0') {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return 1;
}*/

unsigned int _strlen(const char *str) {
    unsigned int count = 0;
    while (*str != '\0') {
        count++;
        str++;
    }
    return count;
}

int write_str(char *str) {
    write(STDOUT_FILENO, str, _strlen(str));
    return 1;
}
