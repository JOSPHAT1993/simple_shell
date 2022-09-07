#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <signal.h>

extern char **environ;

void prompt(void);
int _putchar(char c);
void msg(int sig);
void process(char *buffer);
unsigned int token_num(char *str);
char **split_token(char **split_str, char *str, unsigned int n);
char **str_to_arrays(char *buffer_size);
char *_strdup(char *str);
void msgerr(const char *str, int n);
#endif
