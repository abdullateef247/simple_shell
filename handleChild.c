#include "Hell.h"

/**
 * handle_child_process - Handle operations in the child process
 * @command: The command to be executed
 */

void handle_child_process(const char *command)
{
	char *args[2];

	args[0] = (char *)command;
	args[1] = NULL;
	if (execve(command, args, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
