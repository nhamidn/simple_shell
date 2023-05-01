#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

extern char **environ;

int _putchar(char c);
void _puts(char *s);
void _sputs(char *s);
int _issdigit(char *s);
void _print_illegal_num(char *prog_name, char *cmd, char *arg);
void _print_not_found(char *prog_name, char *cmd);
void free_arrays(char **path, char **env_copy);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
char **_dsplit(char *str, char d);
int _atoi(char *s);
int check_path_env(void);
char *append_to_path(char *path, char *cmd);
char *get_new_path(char *cmd);
char *get_path_env();
void print_env(void);
char *read_commands(int status, char *prog_name);
char **_strsplit(char *s);
int execute_command(char **args, char *prog_name);
void free2darr(char **arr);

#endif
