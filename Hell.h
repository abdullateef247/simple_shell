#ifndef HELL_H
#define HELL_H

/*
 * Macros
 */
#define INITIAL_BUFFER_SIZE 1024
#define MAX_ARGUMENTS 100
#define MAX_COMMAND_LENGTH 1000

/*
 * Declarations
 */

extern char **environ;

/*
 * Header files
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdarg.h>


/*
 * Functions
 */
void sayne_print(const char *format, ...);
int interpret_command(char *instruction, size_t size);
void display_prompt(void);
int compare_strings(const char *str1, const char *str2);
int main(void);
void env_builtin(void);
void exit_with_status(int status);
void env_builtin(void);
void exit_builtin(void);
void execute_command(const char *command);
void handle_parent_process(pid_t child_pid);
void handle_child_process(const char *command);




























#endif
