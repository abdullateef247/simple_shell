#include "Hell.h"



/**
 * exit_builtin - Exit the shell program.
 *
 * Description:
 * This function prints a farewell message and exits the program with
 * a success status.
 */

void exit_builtin(void)
{
	sayne_print("Exiting program.\n");
	exit(EXIT_SUCCESS);
}

