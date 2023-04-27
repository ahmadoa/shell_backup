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

void _exit(char **t_argv, char *line, char **argv, int c);
int _cd(char **t_argv, __attribute__((unused))int err);
int display_env(__attribute__((unused)) char **t_argv, __attribute__((unused)) int err);
int _echo(char **t_argv, int err);
int print_echo(char **t_argv);
void custom_err(char **argv, int c, char **frcommand);
void display_err(char *frcommand, int c, char **argv);
int execute(char **t_argv, char *line, int c, char **argv);
char *_getline();
int check_builtin(char **argv);
int handle_builtin(char **line, int err);
void handle_comments(char *line);
void _setenv(char **new_env);
void free_env(char **env);
char *_getenv(char *env_n);
void file_reader(char *fl, char **argv);
void handle_file(char *line, int i, FILE *fd, char **argv);
void exit_file(char **t_argv, char *line, FILE *fd);
int get_path(char **line);
char *concat_path(char *tok, char *path);
void sigHandler(int num);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_buffers(char **t_argv, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);
void *_calloc(unsigned int size);
int _putchar(char c);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);
int _atoi(char *s);
void _puts(char *str);
void print_number(unsigned int n);
void print_number_in(int n);
void prompt(void);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
int _isalpha(int c);
char *_itoa(int num);
void array_rev(char *arr, int len);
int num_len(int num);
unsigned int sim(char c, const char *s);
char *_strtok(char *s, const char *delim);
char **tokenizer(char *line);

#endif
