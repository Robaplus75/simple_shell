#include "shell.h"

/**
 * main - main Shell Funciton
 * @argc: argument counter
 * @argvv: argument vector
 * @env: the enviroment
 * Return: 0 if everything works, -1 else
 */

int main(int argc, char *argvv[], char **env)
{
	char *path = _getenv("PATH", 4, env), *pathh = NULL, *path_splitted[20];
	size_t cmdsize = 0;
	char *command = NULL, *argv[10];
	bool pipe_test = false;
	int characters;

	argc = argc;
	string_splitter(path, ":", path_splitted);
	while (1 && !pipe_test)
	{
		if (isatty(STDIN_FILENO) == 0)
			pipe_test = true;
		else
			write(1, "$ ", 2);
		characters = getline(&command, &cmdsize, stdin);
		if (characters == -1)
		{
			_putchar('\n');
			exit(0);
		}
		if (command[0] == '\n')
			continue;
		if (command[characters - 1] == '\n')
			command[characters - 1] = '\0';
		string_splitter(command, " ",  argv);
		if (_strncmp(argv[0], "exit", 4) == 0)
			return (0);
		if (_strncmp(argv[0], "env", 3) == 0)
		{
			print_env(env);
			continue;
		}
		pathh = check_file(argv, argvv, path_splitted);
		if (pathh == NULL)
			continue;
		else
			argv[0] = pathh;
		new_process(argv, env, argvv);
	}
	return (0);
}
