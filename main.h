#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int _putchar(char c);
void _puts(char *s);
void _sputs(char *s);
char *read_commands();
char **_strsplit(char *s);
int execute_command(char **args, char *prog_name);
void free2darr(char **arr);

#endif
