#include "struct.h"

t_node *lstnew(int content);
t_node *lstlast(t_node *lst);

// stack tools
void action_s(t_stacks *stacks, char stack);
void action_parser(int act, t_stacks *stacks);
