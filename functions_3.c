#include "shell.h"

/**
 * prompt_handler - checks if its from a pipe or not if not
 * it prints the prompt
 * @pipe_test: the boolean for the logic
 */

void prompt_handler(bool *pipe_test)
{
	if (isatty(STDIN_FILENO) == 0)
		*pipe_test = true;
	else
		write(1, "$ ", 2);
}

/**
 * exit_handler - exits the shell and frees the allocated command
 * @argv: the command given
 * @command: the command to be freed
 * Return: 1 for exiting
 */

int exit_handler(char **argv, char *command)
{
	if (_strncmp(argv[0], "exit", 4) == 0)
	{
		free(command);
		return (1);
	}
	return (0);
}
