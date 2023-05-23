#include "shell.h"

/**
 * _strncmp - checks if the two strings are the same or not
 * @str_1: string 1
 * @str_2: string 2
 * @num: the number of characters to be compared
 * Return: 0 if they r z same, -1 else
 */

int _strncmp(const char *str_1, const char *str_2, size_t num)
{
	size_t count;

	for (count = 0; count < num && str_1[count] == str_2[count]; count++)
	{
	}

	if (count == num)
	{
		return (0);
	}
	else if (str_1[count] > str_2[count])
	{
		return (1);
	}
	else
	{
		return (-1);
	}
}

/**
 * string_splitter - splits the given string
 * @command: the string to be splitted
 * @delimit: the delimiter that separated the string
 * @argv: the place where the splitted string stored
 */

void string_splitter(char *command, char *delimit, char *argv[])
{
	char *token;
	int count = 0;

	token = _strtok(command, delimit);
	while (token)
	{
		argv[count] = token;
		count++;
		token = _strtok(NULL, delimit);
	}
	argv[count] = NULL;
}

/**
 * execute - executes a command
 * @argv: the argument
 * @env: the enviroment
 * @argvv: the argument vector of the amin function;
 */

void execute(char **argv, char **env, char *argvv[])
{
	int val = execve(argv[0], argv, env);

	if (val == -1)
		perror(argvv[0]);
}

/**
 * new_process - creates new process and executes
 * @argv: the argument for the execution
 * @env: the enviroment for the execv
 * @argvv: the argument vector of the main function
 */

void new_process(char *argv[], char *env[], char *argvv[])
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror(argvv[0]);
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		execute(argv, env, argvv);
	}
	else
	{
		int wait_val = wait(NULL);

		if (wait_val == -1)
		{
			perror(argvv[0]);
			exit(EXIT_FAILURE);
		}
	}
}
/**
 * _getenv - gets the specified enviroment
 * @key: the key for the value to be found
 * @env: the enviroment
 * @len: size of the key
 * Return: the value
 */

char *_getenv(char *key, size_t len, char **env)
{
	int i = 0;
	char *token = NULL, *value = NULL;

	while (env[i])
	{
		token = _strtok(env[i], "=");
		if (_strncmp(token, key, len) == 0)
		{
			value = _strtok(NULL, "=");
			return (value);
		}
		i++;
	}
	return (NULL);
}

