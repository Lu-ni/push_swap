#include "node_utils.h"
#include "struct.h"
#include <stdio.h>

int max_b(t_stacks *stacks)
{
	int max;
	t_node *node;
	max = stacks->b->index;
	node = stacks->b;

	while(node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	return (max);
}
int last_index_b(t_stacks *stacks)
{
	t_node *node;
	node = stacks->b;
	while (node && node->next)
		node = node->next;
	return node->index;
}
int min_b(t_stacks *stacks)
{
	int min;
	t_node *node;
	min = stacks->b->index;
	node = stacks->b;

	while(node)
	{
		if (node->index < min)
			min = node->index;
		node = node->next;
	}
	return (min);
}
int previous_index(t_stacks *stacks, int index)
{
	t_node *node;
	int last_i;

	node = stacks->b;
	if (index == node->index)
	{
		while (node)
		{
			last_i = node->index;
			node = node->next;
		}
		return (last_i);
	}
	while (node)
	{
		if (node->index == index)
			return (last_i);
		last_i = node->index;
		node = node->next;
	}
	return -1;
}

int count_pos_b(t_node *node_,t_stacks *stacks)
{
	int max;
	int min;
	int count;
	t_node *node;

	max = max_b(stacks);
	min = min_b(stacks);
	count = 0;
	node = stacks->b;
	if (min < node_->index && node_->index < max)
	{
		while(!(previous_index(stacks, node->index) > node_->index && node_->index > node->index))
				{
					count++;
					node = node->next;
				}
	}
	else
	{
		while(node->index != max)
		{
			count++;
			node = node->next;
		}
	}
	return count;
}

int leastcost(t_stacks *stacks)
{
	int size_b;
	int cost_ra;
	int cost_rb;
	int min_cost;
	int index_min;
	t_node *node;

	cost_ra = 0;
	size_b = 0;
	min_cost = 100000000;
	index_min = -1;
	node = stacks->b;
	while (node)
	{
		node = node->next;
		size_b++;
	}
	node = stacks->a;
	while (node)
	{
		if (count_pos_b(node, stacks) > (size_b / 2))
			cost_rb = count_pos_b(node, stacks) - (size_b / 2);
		else
			cost_rb = count_pos_b(node, stacks);

		if((cost_ra + cost_rb) < min_cost)
		{
			min_cost = cost_ra + cost_rb;
			index_min = node->index;
		}
		node = node->next;
		cost_ra ++;
	}
	return(index_min);	
}

int checkdirection_a(t_stacks *stacks, int index)
{
	int     count;
	int     size;
	t_node *node;

	count = 0;
	size = 0;
	node = stacks->a;
	while (node)
	{
		if (node->index == index)
			count = size;
		node = node->next;
		size++;
	}
	if (count < (size / 2))
		return 1;
	else
		return 0;
}
int checkdirection_b(t_stacks *stacks, int count)
{
	int     size;
	t_node *node;

	size = 0;
	node = stacks->b;
	while (node)
	{
		node = node->next;
		size++;
	}
	if (count < (size / 2))
		return 1;
	else
		return 0;
}
void algo_pushb2(t_stacks *stacks)
{
	stacks->action(PB, stacks);
	stacks->action(PB, stacks);
	int min_index;
	
	while(stacks->a)
	{
		min_index = leastcost(stacks);

		while(stacks->a->index != min_index)
		{
			if(checkdirection_a(stacks, min_index))
				stacks->action(RA, stacks);
			else
				stacks->action(RRA, stacks);
		}
		while(count_pos_b(stacks->a,stacks))
		{
			if(checkdirection_b(stacks, count_pos_b(stacks->a,stacks)))
				stacks->action(RB, stacks);
			else
				stacks->action(RRB, stacks);
		}
		stacks->action(PB, stacks);
	}
	while(stacks->b->index != max_b(stacks))
		stacks->action(RB, stacks);
	while(stacks->b)
		stacks->action(PA, stacks);
}
