#include "main.h"

/**
 * sigHandler - Handle ^C
 * @num:Captured Signal
 * Return: Void
 */
void sigHandler(int num)
{
	if (num == SIGINT)
		PRINTER("\n$ ");
}

/**
 * main - shell entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: entry value
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *line, **av_tok;
	int i = 0, entry = 1, st = 0;

	if (argv[1] != NULL)
		file_reader(argv[1], argv);
	signal(SIGINT, sigHandler);
	while (entry)
	{
		i++;
		if (isatty(STDIN_FILENO))
			prompt();
		line = _getline();
		if (argv[0] == '\0')
			continue;
		av_tok = tokenizer(line);
		if (_strcmp(av_tok[0], "exit") == 0)
		{
			_exit_sh(av_tok, line, argv, i);
		}
		else if (check_builtin(av_tok) == 0)
		{
			st = handle_builtin(av_tok, st);
			free_buffers(av_tok, line);
			continue;
		}
		else
		{
			st = execute(av_tok, line, i, argv);
		}
		free_buffers(av_tok, line);
	}
	return (entry);
}
