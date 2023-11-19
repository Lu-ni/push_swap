/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:26:16 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/18 22:24:05 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_utils.h"
#include "struct.h"
#include <stdio.h>

int max_b(t_stacks *stacks)
{
	int     max;
	t_node *node;
	max = stacks->b->index;
	node = stacks->b;

	while (node)
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
	int     min;
	t_node *node;
	min = stacks->b->index;
	node = stacks->b;

	while (node)
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
	int     last_i;

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
int size_stack(t_stacks *stacks, char c)
{
	t_node *node;
	int     size;

	size = 0;
	if (c == 'a')
		node = stacks->a;
	else
		node = stacks->b;

	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}
int count_pos_b(t_node *node_, t_stacks *stacks)
{
	int     max;
	int     min;
	int     count;
	int     size_b;
	t_node *node;

	size_b = size_stack(stacks, 'b');
	max = max_b(stacks);
	min = min_b(stacks);
	count = 0;
	node = stacks->b;
	if (min < node_->index && node_->index < max)
	{
		while (!(previous_index(stacks, node->index) > node_->index && node_->index > node->index))
		{
			count++;
			node = node->next;
		}
	}
	else
	{
		while (node->index != max)
		{
			count++;
			node = node->next;
		}
	}
	return count;
}
int min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
void find_min_cost(t_cost *cost)
{
	t_cost tmp;

	tmp.min_cost = 1000000;
	tmp.ra = 0;
	tmp.rb = 0;
	tmp.rr = 0;
	tmp.rra = 0;
	tmp.rrb = 0;
	tmp.rrr = 0;
	if (cost->ra + cost->rrb < tmp.min_cost)
	{
		tmp.ra = cost->ra;
		tmp.rb = 0;
		tmp.rra = 0;
		tmp.rrb = cost->rrb;
		tmp.min_cost = tmp.ra + tmp.rrb;
	}
	if (cost->rra + cost->rb < tmp.min_cost)
	{
		tmp.ra = 0;
		tmp.rb = cost->rb;
		tmp.rra = cost->rra;
		tmp.rrb = 0;
		tmp.min_cost = tmp.rb + tmp.rra;
	}
	if (cost->ra + cost->rb - min(cost->ra, cost->rb) < tmp.min_cost)
	{
		tmp.ra = cost->ra - min(cost->ra, cost->rb);
		tmp.rb = cost->rb - min(cost->ra, cost->rb);
		tmp.rra = 0;
		tmp.rrb = 0;
		tmp.rr = min(cost->ra, cost->rb);
		tmp.min_cost = cost->ra + cost->rb - min(cost->ra, cost->rb);
	}
	if (cost->rra + cost->rrb - min(cost->rra, cost->rrb) < tmp.min_cost)
	{
		tmp.ra = 0;
		tmp.rb = 0;
		tmp.rra = cost->rra - min(cost->rra, cost->rrb);
		tmp.rrb = cost->rrb - min(cost->rra, cost->rrb);
		tmp.rr = 0;
		tmp.rrr = min(cost->rra, cost->rrb);
		tmp.min_cost = cost->ra + cost->rb - min(cost->ra, cost->rb);
	}

	cost->ra = tmp.ra;
	cost->rb = tmp.rb;
	cost->rra = tmp.rra;
	cost->rrb = tmp.rrb;
	cost->rr = tmp.rr;
	cost->rrr = tmp.rrr;
	cost->min_cost = tmp.min_cost;
}
void copy_t_cost(t_cost *dest, t_cost *src)
{
	dest->min_cost = src->min_cost;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
}

t_cost leastcost(t_stacks *stacks, t_cost *final_cost)
{
	t_cost  tmp;
	t_cost  min_cost;
	int     i;
	t_node *node;
	int     size_a;
	int     size_b;

	size_a = size_stack(stacks, 'a');
	size_b = size_stack(stacks, 'b');
	i = 0;
	node = stacks->b;
	node = stacks->a;
	min_cost.min_cost = 10000000;
	while (node)
	{
		tmp.ra = i;
		tmp.rra = size_a - i;
		tmp.rb = count_pos_b(node, stacks);
		tmp.rrb = size_b - tmp.rb;
		find_min_cost(&tmp);

		if (tmp.min_cost < min_cost.min_cost)
			copy_t_cost(&min_cost, &tmp);
		node = node->next;
		i++;
	}
	copy_t_cost(final_cost, &min_cost);
	return (min_cost);
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
	if (count <= (size / 2))
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
void opti_action_stack(t_stacks *stacks)
{
	int i;
	int count_RA;
	int count_RB;
	int count_RRA;
	int count_RRB;
	int count = 0;
	i = 0;
	count_RA = 0;
	count_RB = 0;
	count_RRA = 0;
	count_RRB = 0;
	while (stacks->action_stack[i] != -1)
	{
		if (stacks->action_stack[i] == RA)
			count_RA++;
		else if (stacks->action_stack[i] == RB)
			count_RB++;
		else if (stacks->action_stack[i] == RRA)
			count_RRA++;
		else if (stacks->action_stack[i] == RRB)
			count_RRB++;
		i++;
	}
	if (count_RA > count_RB)
	{
		count = count_RB;
		while (count-- > 0)
			printf("rr\n");
		count = count_RA - count_RB;
		while (count-- > 0)
			printf("ra\n");
	}
	else
	{
		count = count_RA;
		while (count-- > 0)
			printf("rr\n");
		count = count_RB - count_RA;
		while (count-- > 0)
			printf("rb\n");
	}

	if (count_RRA > count_RRB)
	{
		count = count_RRB;
		while (count-- > 0)
			printf("rrr\n");
		count = count_RRA - count_RRB;
		while (count-- > 0)
			printf("rra\n");
	}
	else
	{
		count = count_RRA;
		while (count-- > 0)
			printf("rrr\n");
		count = count_RRB - count_RRA;
		while (count-- > 0)
			printf("rrb\n");
	}
}
void algo_pushb2(t_stacks *stacks)
{
	t_cost cost;
	stacks->action(PB, stacks);
	stacks->action(PB, stacks);

	while (stacks->a)
	{
		leastcost(stacks, &cost);

		while (cost.ra--)
			stacks->action(RA, stacks);
		while (cost.rb--)
			stacks->action(RB, stacks);
		while (cost.rr--)
			stacks->action(RR, stacks);
		while (cost.rra--)
			stacks->action(RRA, stacks);
		while (cost.rrb--)
			stacks->action(RRB, stacks);
		while (cost.rrr--)
			stacks->action(RRR, stacks);

		stacks->action(PB, stacks);
	}
	while (stacks->b->index != max_b(stacks))
		stacks->action(RB, stacks);
	while (stacks->b)
		stacks->action(PA, stacks);
}
