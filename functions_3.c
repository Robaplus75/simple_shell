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

/**
 * _strtok - separates string into tokens
 * @string: the string to be separated
 * @delimiter: the delimiter that is used to separate the string
 * Return: the token
 */

char *_strtok(char *string, const char *delimiter)
{
	static char *ptr;
	char *token;
	int i;
	int j;

	if (string != NULL)
		ptr = string;
	if (ptr == NULL || *ptr == '\0')
		return (NULL);
	token = ptr;
	for (i = 0; token[i] != '\0'; i++)
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (token[i] == delimiter[j])
			{
				token[i] = '\0';
				ptr = &token[i + 1];
				return (token);
			}
		}
	}
	ptr = NULL;
	return (token);
}
