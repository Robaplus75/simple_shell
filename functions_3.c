#include "shell.h"

/**
 * prompt_handler - checks if its from a pipe or not if not
 * it prints the prompt
 * @pipe_test: the boolean for the logic
 */

void prompt_handler(bool *pipe_test, int *i)
{
	*i = 0;
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
	char *tokn;
	int i;
	int j;

	if (string != NULL)
		ptr = string;
	if (ptr == NULL || *ptr == '\0')
		return (NULL);
	tokn = ptr;
	for (i = 0; tokn[i] != '\0'; i++)
	{
		for (j = 0; delimiter[j] != '\0'; j++)
		{
			if (tokn[i] == delimiter[j])
			{
				tokn[i] = '\0';
				ptr = &tokn[i + 1];
				return (tokn);
			}
		}
	}
	ptr = NULL;
	return (tokn);
}

/**
 * _isspace - checks if the character is whitespace or not
 * @c: the character to be checked
 * Return: 1 if its whitespace, 0 else
 */

int _isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * check_whitespace - checks if the string is a whitespace or not
 * @command: the string to be checked
 * Return: 1 if its whitespace, 0 else
 */

int check_whitespace(const char *command)
{
	while (*command != '\0')
	{
		if (!_isspace((unsigned char)*command))
			return (0);
		command++;
	}
	return (1);
}
