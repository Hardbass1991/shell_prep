#ifndef FUNCS
#define FUNCS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

extern char **environ;

list_t *add_node_end(list_t **head, const char *str);
char **tokenize_line(char *line);
void print_env();
char *get_full_command(char *command);
#endif
