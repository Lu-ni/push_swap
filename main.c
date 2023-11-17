#include "libft/libft.h"
#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>

int check_errors(char **argv, int count)
{
	return (0);
}

int parser(int count, char **argv, t_stacks *stacks)
{
	t_node *node;
	int     i;

	i = 2;
	node = lstnew(ft_atoi(argv[1]));
	stacks->a = node;
	while (i < count)
	{
		node->next = lstnew(ft_atoi(argv[i]));
		node = node->next;
		i++;
	}
	return (0);
}

int algo_pushb(t_stacks *stacks)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (stacks->a)
	{
		if (stacks->a->index == i)
		{
			stacks->action(PB, stacks);
			count++;
			i++;
		}
		else
		{
			stacks->action(RA, stacks); // add direction checker (RRA or RA ?)
			count++;
		}
		// add a partial check: if what's letf in the stack is sorterd, we start to put back in a -> should devid per 2 in average... maybe ?
	}
	while (stacks->b)
	{
		stacks->action(PA, stacks);
		count++;
	}
	return (count);
}

int algo1(t_stacks *stacks) // not working
{
	t_node *node;
	int     trigger;

	node = stacks->a;
	while (!check_sorted(stacks))
	{
		if (node->next && node->index > node->next->index)
			stacks->action(SA, stacks);
		stacks->action(RRA, stacks);
		node = stacks->a;
	}
	return (0);
}

void alog_delta_sort(t_stacks *stacks) // working but shitty ~N^3
{
	while (!check_sorted(stacks))
	{
		if ((stacks->a->next->delta < stacks->a->delta))
			stacks->action(SA, stacks);
		if (check_sorted(stacks))
			return;
		stacks->action(RRA, stacks);
	}
}

int get_lastnode_index(t_stacks *stacks)
{
	t_node *node;
	node = stacks->a;
	while (node && node->next)
		node = node->next;
	return node->index;
}

void algo_insert_sort(t_stacks *stacks)
{
	t_node *node;
	t_node *last_node;

	// check if value is bigger than previous
	//	if value is bigger -> push to b and then sort it
	//	else -> do nothing
	node = stacks->a;
	while (stacks->a->i_relative != 0)
		stacks->action(RA, stacks);
	while (!check_sorted(stacks))
	{
		if (stacks->a->next->index == 0 || stacks->a->index < stacks->a->next->index)
			stacks->action(RA, stacks);
		else
		{
			stacks->action(RA, stacks);
			stacks->action(PB, stacks);
			while (get_lastnode_index(stacks) > stacks->b->index)
			{
				stacks->action(RRA, stacks);
			}
			stacks->action(PA, stacks);
		}
	}
}

int main(int argc, char **argv)
{
	t_stacks stacks;

	stacks.action = action_parser;
	stacks.a = (t_node *) 0;
	stacks.b = (t_node *) 0;
	stacks.n = argc - 1;

	if (check_errors(argv, argc)) // todo
		return (1); // the stack passed as argv contain incorrect value
	parser(argc, argv, &stacks);
	add_index(&stacks);
	add_delta(&stacks);
	add_i(&stacks);
	set_zero_relative(&stacks);
	add_i_relative(&stacks);
	////// done with mandatory stuff
	// algo_insert_sort(&stacks);
	algo_pushb(&stacks);
	// alog_delta_sort(&stacks);

	return (0);
}
