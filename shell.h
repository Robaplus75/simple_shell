#ifndef S_SHELL_H
#define S_SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdbool.h>


int _strncmp(const char *str_1, const char *str_2, size_t num);
void string_splitter(char *command, char *delimit, char *argv[]);
void execute(char **argv, char **env, char *argvv[]);
int command_handler(char *command);
void new_process(char *argv[], char *env[], char *argvv[]);
char *_getenv(char *key, size_t len, char **env);
void concat(char *str1, char *str2, char *str3, char *path);
int _strlen(char *string);
char *check_file(char **argv, char **argvv, char **path_splitted);
void print_env(char **env);
int _putchar(char c);
void prompt_handler(bool *pipe_test);
int exit_handler(char **argv, char *command);

#endif
