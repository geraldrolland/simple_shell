#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
extern char **environ;
char *_strdup(char *str);
int _str_len(char *str);
int write_str(char *str);
char **init_argv(char *str, unsigned int *ptr);
/* free_mem(char **dptr);*/
unsigned int _strcmp(char *str1, char *str2);
unsigned int _strlen(const char *str);
void env(void);
int compare_path(char *str);
int input_cmd(char *str);
char *_strcat(char *src, char *dest);
int token_num(char *str);
int _fork(char *input, char *token, int arg_size);
int _fork_proc(char *str, char *str1, char *token);
int print_error(char *str1, char *str2, char **v);
#endif
