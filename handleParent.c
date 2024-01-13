#include "Hell.h"


/**
 * handle_parent_process - Handle operations in the parent process
 * @child_pid: The process ID of the child process
 */

void handle_parent_process(pid_t child_pid)
{
	int status;
	int exit_status;

	if (waitpid(child_pid, &status, 0) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
	if (WIFEXITED(status))
	{
		exit_status = WEXITSTATUS(status);
		sayne_print("child proc exited with status:%d\n", exit_status);
	}
	else
	{
		sayne_print("child process did not exit normally\n");
	}

}
