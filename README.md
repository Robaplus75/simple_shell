Simple shell Project(ALX 0x16.C-Simple Shell)
By Robel.G and Robel.I May 2023

Description
This shell program reads a command from the user and tokenizes it into individual arguments then executes the command using execve. 
The shell uses fork to create a child process and wait for the child process to complete before accepting the next command.
this project is mainly prepared to accomplish the mandatory tasks from task 0 to task 5. the advanced from tasks 6 to 16 are on progress and will be included on completion

List of Files.
1. shell.c
2. shell.h
3. function_1.c
4. functions_2.c
5. functions_3.c
6. hsh.exe
7. AUthors
8. README.md

Function breakdown. 

shell.h

Has header file named "s_shell.h" for a shell program. and perfromes the below functions and gard the program from multiple inclusions of the header file in the same source file using (#ifndef, #define, and #endif)

_strncmp: A function that compares two strings up to a specified number of characters.
string_splitter: A function that splits a string into tokens using a delimiter and stores them in an array.
execute: A function that executes a command with the given arguments and environment variables.
command_handler: A function that handles a command by parsing and executing it.
new_process: A function that creates a new process to execute a command.
_getenv: A function that retrieves the value of an environment variable.
concat: A function that concatenates multiple strings.
_strlen: A function that returns the length of a string.
check_file: A function that checks if a file exists in the provided paths.
print_env: A function that prints the environment variables.
_putchar: A function that writes a character to the standard output.
prompt_handler: A function that handles the shell prompt.
exit_handler: A function that handles the exit command.

shell.c

This is the main function of our shell program.
1. It will read user input using getline,
	1.1 checks if characters =-1, the command variable is freed using free, 
	1.2 Newline character is printed using _putchar, and the program exits with a status of 0.
2. chcek for inputtype
	2.1 If the first character of the command is a newline character, it means the user pressed Enter without entering any command. In 		this case, the loop continues to the next input.
	2.2 If the last character of the command is a newline character, it is replaced with a null character, effectively removing the 		newline character from the command.
3. Once input is verifide/valid string_splitter function is used to split the command into individual arguments which are stored in the argv array.
4. check_file function is called to check if the entered command exists in the provided paths. 
	4.1 If a valid path is found, it replaces the first argument in the argv array with the full path.
	4.2 The new_process function is called to create a new process and execute the command with the updated argv, env, and argvv arguments.
5. If the loop continues, the memory allocated for pathh is freed before ready to the next input.
	5.1 If the user entered the "env" command, the print_env function is called to display the environment variables. The loop then 		continues to the next.
6. The exit_handler function is called to check if the user entered the "exit" command. If so, the main function returns 0, indicating successful execution and termination of the program.


Below three file is created to handel different functions defined in the header and integrated using "shell.h" and this help us not to  without compromising minimum function requirement per file.

functions_1.c
Perfrom the below five functions.

_strncmp: This function compares two strings to specified number of characters via the strings and checks for differences. 
	a. return 0 if the strings are the same, 
	b. return 1 if the first string is greater
	C. Return -1 if the second string is greater.

string_splitter: This function splits a given string using a delimiter and stores the resulting tokens in an array. 
	a. the function uses the strtok function to tokenize the string and stores each token in the argv array.

execute: This function executes a command by calling execve with the provided arguments and environment variables. 
	a. If execve returns -1, indicating an error then function prints an error message using perror.

new_process: This function creates a new process using fork and executes a command in the child process using the execute function. 
	a. The parent process waits for the child process to finish using wait. 
	b. If an error occurs during fork or wait, an error message is printed using perror.

_getenv: This function retrieves the value of an environment variable specified by the given key. It iterates through the env array and uses strtok to extract the key from each environment variable string. 
	a. If the key matches the specified key, the corresponding value is returned. 
	b. Otherwise, it returns NULL.


functions_2.c
Perfroms the below five functions.

_strlen: This function counts the length of a string by iterating through the characters until it reaches the null terminator ('\0'). 
	a. It increments a counter variable and returns the length of the string.

concat: This function concatenates three strings (str1, str2, and str3) and stores the result in the path string. 
	a. It uses three separate loops to copy each character from the input strings to the path string, ensuring that the resulting string is terminated with a null character.

check_file: This function checks if a file or command exists in the provided paths. 
	a. It first checks if the file exists at the specified path in argv[0]. 
	b. If not, it iterates through the path_splitted array, concatenates each path with the file name using the concat function, and 		checks if the file exists at the generated path. 
	c. If a valid path is found, it returns the located path; 
	d. otherwise, it returns NULL. 
	3. If there's an error with stat or if the file is not found, an error message is printed using perror.

_putchar: This function prints a single character to the standard output by using the write system call. 
	a. It takes a character as input and returns the result of the write call, 
		a.a number of characters written 
		a.b or -1 if an error occurs.

print_env: This function prints the environment variables by iterating through the env array. 
	a. It iterates through each character of each environment variable string and uses _putchar to print each character. 
	b. It also adds an equal sign ('=') to separate the variable name and value, and a newline character ('\n') after each variable.


functions_3.c
perfrom the below three functions.

prompt_handler: This function checks if the input is from a pipe or not. 
	a. If the input is not from a pipe (determined by checking the file descriptor STDIN_FILENO with isatty), it means the shell is receiving input from the user interactively. 
		a.a In that case, it prints the prompt symbol ($ ) to the standard output using the write system call. 
		a.b If the input is from a pipe, the function sets the pipe_test boolean variable to true.

exit_handler: This function checks if the command is an "exit" command. 
	a. It compares the command against the string "exit" using _strncmp to check for an exact match. 
	b. If the command is an "exit" command, the function frees the dynamically allocated memory for the command string and 			returns 1, indicating that the shell should exit. Otherwise, it returns 0 to continue executing other commands.


Thank you for reading.

