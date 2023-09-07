#ifndef SHED_H_
#define SHED_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for write/read buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for converting_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE
#define HIST_MAX 4096

extern char **environ;

#define win(x) write(STDOUT_FILENO, x, _strlen(x))
#define din() write(STDOUT_FILENO, "###\n", 4)

#define ERR_EXIT(a, b, c)\
do {\
	write(STDERR_FILENO, a, _strlen(a));\
	write(STDERR_FILENO, ": ", 2);\
	write(STDERR_FILENO, b, _strlen(b));\
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);\
	write(STDERR_FILENO, c, _strlen(c));\
	write(STDERR_FILENO, "\n", 1);\
} while (0)

#define ERR_EXE(a, b, c)\
do {\
	write(STDERR_FILENO, a, _strlen(a));\
	write(STDERR_FILENO, ": ", 2);\
	write(STDERR_FILENO, b, _strlen(b));\
	write(STDERR_FILENO, ": ", 2);\
	write(STDERR_FILENO, c, _strlen(c));\
	write(STDERR_FILENO, ": not found", 11);\
	write(STDERR_FILENO, "\n", 1);\
} while (0)

int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char **tokenizer(char *str, const char *delim);
char *smart_cat(char **path, char *name);
int forking_helper(char **av);
int print_env(char **env);
int custom_atoi(int *status, char *s);
char *_strdup(char *str);
char *_itoa(int num);
char *var_finder(char *var, char **env);
void free_array(char **array);
int life(char **array, char **argv, char **env, char **p_t, int i, int *e_c);
int run_shell(int go);

#endif
