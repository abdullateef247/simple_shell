#include "Hell.h"

/**
 * execute_command - Execute the given command in a child process
 * @command: The command to be executed
 */

void execute_command(const char *command)
{
	pid_t child_pid =fork();

	if (child_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		handle_child_process(command);
	}
	else
	{
		handle_parent_process(child_pid);
	}
}
