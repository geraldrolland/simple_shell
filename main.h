#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
int call_cd(char *input);
int _setenv(char *variable_name, char *variable_value);
int _unsetenv(char *variable_name);
int env(void);
int environ_cmd(char *input);
int input_env(char *str);
extern char **environ;
char *_strdup(char *str);
int write_str(char *str);
unsigned int _strcmp(char *str1, char *str2);
unsigned int _strlen(const char *str);
int compare_path(char *str);
int input_cmd(char *str);
char *_strcat(char *src, char *dest);
int _fork(char *input, char *token, int arg_size);
int _fork_proc(char *str, char *str1, char *token);
void _exit_status(char *input);
int _atoi(char *str);
#endif
