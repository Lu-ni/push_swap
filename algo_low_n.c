#include "node_utils.h"
#include "struct.h"
#include <stdio.h>
void sort_n_3(t_stacks *stacks)
{
	t_node *n;
	n = stacks->a;

	if (n->index < n->next->index && n->index < n->next->next->index)
	{
		stacks->action(SA, stacks);
		stacks->action(RA, stacks);
	}
	else if (n->index > n->next->index && n->index < n->next->next->index)
		stacks->action(SA, stacks);
	else if (n->index < n->next->index && n->index > n->next->next->index)
		stacks->action(RRA, stacks);
	else if (n->index > n->next->index && n->next->index < n->next->next->index)
		stacks->action(RA, stacks);
	else
	{
		stacks->action(RA, stacks);
		stacks->action(SA, stacks);
	}
}
void algo_low_n(t_stacks *stacks)
{
	if (check_sorted(stacks))
		return;
	else if (stacks->n == 2)
		stacks->action(SA, stacks);
	else if (stacks->n == 3)
	{
		sort_n_3(stacks);
	}
}
