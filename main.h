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
int _strcmp(char *s1, char *s2);
void print_env(void);
char *read_commands(int status);
char **_strsplit(char *s);
int execute_command(char **args, char *prog_name);
void free2darr(char **arr);

#endif
