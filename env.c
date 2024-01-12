#include "Hell.h"

/**
 * env_builtin - Print the current environment.
 *
 * Description:
 * This function prints the current environment variables to standard output.
 */


void env_builtin(void)
{
	char **env_var = environ;

	while (*env_var != NULL)
	{
		sayne_print(*env_var);
		sayne_print("\n");
		env_var++;
	}
}
