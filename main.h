#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/limits.h>


extern char **environ;

#define BUFSIZE 1024
#define DELIM " \t\r\n\a"
#define PRINTER(ch) (write(STDOUT_FILENO, ch, _strlen(ch)))


/**###### STRING FUNCTION ######*/

char *_strtok(char *s, const char *tok);
unsigned int sim(char c, const char *s);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _putchar(char c);
int _atoi(char *s);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
void array_rev(char *arr, int len);
int num_len(int num);
char *_itoa(unsigned int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);

/**###### MEMORIE  MANGMENT ####*/

void free_env(char **env);
void *fill_an_array(void *a, int el, unsigned int len);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_buffers(char **input, char *line);

/**###### INPUT Function ######*/

void prompt(void);
void sigHandler(int num);
char *_getline(void);

/** ###### Command parser and extractor ###*/

int get_path(char **line);
char *_getenv(char *env_n);
char **tokenizer(char *line);
int handle_builtin(char **cmd, int er);
void file_reader(char *fl, char **argv);
char *concat_path(char *tok, char *path);
int check_builtin(char **cmd);
void _setenv(char **new_env);
int execute(char **t_argv, char *line, int c, char **argv);
void handle_file(char *line, int i, FILE *fd, char **argv);
void exit_file(char **t_argv, char *line, FILE *fd);

/** ####BUL FUNC #####*/

void handle_comments(char *line);
int display_env(char **cmd, int er);
int _cd(char **cmd, int er);
int _echo(char **cmd, int er);
void _exit(char **t_argv, char *line, char **argv, int c);
int print_echo(char **cmd);

/** ####error handle and Printer ####*/
void print_number(unsigned int n);
void print_number_in(int n);
void display_err(char *frcommand, int c, char **argv);
void custom_err(char **argv, int c, char **frcommand);


/**
 * struct bulltin - contain bultin to handle and function to excute
 * @command:pointer to char
 * @func:fun to excute when bultin true
 */

typedef struct built
{
	char *blt_cmd;
	int (*func)(char **line, int err);
} builtin;

#endif
