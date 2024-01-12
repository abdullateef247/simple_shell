#include "Hell.h"

/**
 * exit_with_status - Exit the shell program with a specified status.
 * @status: The exit status to use.
 *
 * Description:
 * This function prints a farewell message and exits the program with
 * the specified status.
 */

void exit_with_status(int status)
{
	sayne_print("Exiting program with status %d.\n", status);
	exit(status);
}
