#include "Hell.h"


/**
 * parse_command - Parse the command string into an array of arguments.
 * @command: The command string to be parsed.
 * @argv: The array to store the parsed arguments.
 */


void parse_command(char *command, char *argv[])
{
	int i = 0;

	argv[i++] = strtok(command, " ");
	while ((argv[i++] = strtok(NULL, " ")) != NULL)
	argv[i - 1] = NULL;
}


/**
 * is_executable - Check if the specified command is executable.
 * @command: The command to be checked.
 * @argv: The array of arguments (including the command).
 * Return: 1 if the command is executable, 0 otherwise.
 */

int is_executable(char *command, char *argv[])
{
	int result;
	char *full_path;

	if (_strchr(argv[0], '/') != NULL)
	{
		return (access(command, X_OK) == 0);
	}
	else
	{
		full_path = _strconcat("/bin/", command);
		result = (access(full_path, X_OK) == 0);

		free(full_path);
		return (result);
	}
}

/**
 * execute_command_child - Execute the command in a child process.
 * @command: The command to be executed.
 * @argv: The array of arguments (including the command).
 */

void execute_command_child(char *command, char *argv[])
{
	if (execve(command, argv, NULL) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}


/**
 * execute_command - Execute the command and handle errors.
 * @command: The command to be executed.
 * @argv: The array of arguments (including the command).
 */


void execute_command(char *command, char *argv[])
{
	pid_t pikin_pid = fork();

	if (pikin_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pikin_pid == 0)
	{
		parse_command(command, argv);
		if (argv[0] != NULL)
		{
			if (is_executable(command, argv))
			{
				execute_command_child(command, argv);
			}
			else
			{
				sayne_print("%: command not found\n", argv[0]);
				exit(EXIT_FAILURE);
			}
		}

	}
	else
	{
		waitpid(pikin_pid, NULL, 0);
	}
}
