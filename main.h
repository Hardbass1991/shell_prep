#ifndef FUNCS
#define FUNCS
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

list_t *add_node_end(list_t **head, const char *str);
char **tokenize_line(char *line);
void print_env();
char *get_full_command(char *command);
#endif
