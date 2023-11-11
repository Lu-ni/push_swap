#ifndef STRUCT_H
#define STRUCT_H
typedef struct s_node
{
	int            val;
	struct s_node *next;
} t_node;

typedef struct s_stacks
{
	t_node *a;
	t_node *b;
} t_stacks;
#endif
