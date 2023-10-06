#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
char *_strdup(char *str);
int _str_len(char *str);
int write_str(char *str);
char **init_argv(char *str, unsigned int *ptr);
int free_mem(char **dptr);
unsigned int _strcmp(char *str1, char *str2);
unsigned int _strlen(const char *str);
#endif
