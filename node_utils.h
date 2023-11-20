#include "struct.h"

t_node *lstnew(int content);
t_node *lstlast(t_node *lst);

// stack tools
void action_s(t_stacks *stacks, char stack);
void action_parser(int act, t_stacks *stacks);
int  check_sorted(t_stacks *stacks);
void add_index(t_stacks *stacks);
void print_stack(t_stacks *stacks);
void algo_pushb2(t_stacks *stacks);
void algo_low_n(t_stacks *stacks);
