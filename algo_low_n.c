#include "node_utils.h"
#include "struct.h"
#include <stdio.h>
void sort_n_3(t_stacks *stacks)
{
	t_node *n;
	int     a;
	int     b;
	int     c;

	n = stacks->a;
	a = n->index;
	b = n->next->index;
	c = n->next->next->index;

	if (a < b && a < c && b < c)
	{
		return;
	}
	else if (a < b && a < c && b > c)
	{
		stacks->action(SA, stacks);
		stacks->action(RA, stacks);
	}
	else if (a > b && a < c && b < c)
		stacks->action(SA, stacks);
	else if (a < b && a > c && b > c)
		stacks->action(RRA, stacks);
	else if (a > b && a > c && b < c)
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
