#ifndef STRUCT_H
#define STRUCT_H

#define SA 1
#define SB 2
#define SS 3
#define PA 4
#define PB 5
#define RA 6
#define RB 7
#define RR 8
#define RRA 9
#define RRB 10
#define RRR 11

struct s_stacks; // declaring th struct for the compilator

typedef struct s_node
{
	int            val;
	int            index;
	struct s_node *next;
} t_node;

typedef void (*t_action)(int, struct s_stacks *);

typedef struct s_stacks
{
	t_node  *a;
	t_node  *b;
	int      n;
	t_action action;

} t_stacks;
#endif
