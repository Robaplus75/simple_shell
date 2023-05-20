#include "shell.h"

/**
 * _strlen - counts the length of the string
 * @string: the string
 * Return: the length of the string
 */

int _strlen(char *string)
{
	int length = 0;

	while (*string != 0)
	{
		length++;
		string++;
	}
	return (length);
}

/**
 * concat - concatnates three strings and save it to path
 * @str1: string 1
 * @str2: string 2
 * @str3: string 3
 * @path: the concatnated string to be stored
 * Return: none
 */

void concat(char *str1, char *str2, char *str3, char *path)
{
	int i, j, k;

	for (i = 0; str1[i] != '\0'; i++)
	{
		path[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; j++, i++)
	{
		path[i] = str2[j];
	}
	for (k = 0; str3[k] != '\0'; k++, i++)
	{
		path[i] = str3[k];
	}
	path[i] = '\0';
}

/**
 * check_file - checks if the file or commands exists in the path
 * @argv: the path to check
 * @argvv: the argument vector passed through the main function
 * @path_splitted: the path enviroment where the searching takes place
 * Return: the argvv if it cant be found, the located path if its found
 */
char *check_file(char **argv, char **argvv, char **path_splitted)
{
	struct stat check1;
	struct stat check2;
	char *path_location = malloc(sizeof(char) * 100);

	if (stat(argv[0], &check1) != 0)
	{
		int count = 0;

		while (path_splitted[count])
		{
			concat(path_splitted[count], "/", argv[0], path_location);
			if (stat(path_location, &check2) == 0)
			{
				return (path_location);
			}
			count++;
		}
		perror(argvv[0]);
		return (NULL);
	}
	return (argv[0]);
}
/**
 * _putchar - prints a character
 * @c: the character to be printed
 * Return: -1 when there is an error
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_env - prints the enviroment
 * @env: the enviroment
 */

void print_env(char **env)
{
	int count = 0;
	int i;

	while (env[count])
	{
		i = 0;
		while (env[count][i] != '\0')
		{
			_putchar(env[count][i]);
			i++;
		}
		_putchar('=');
		i++;
		while (env[count][i] != '\0')
		{
			_putchar(env[count][i]);
			i++;
		}
		_putchar('\n');
		count++;
	}
}
