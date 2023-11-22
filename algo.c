/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:26:16 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/22 17:32:42 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_utils.h"
#include "struct.h"

int	max_b(t_stacks *stacks)
{
	int		max;
	t_node	*node;

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

int	last_index_b(t_stacks *stacks)
{
	t_node	*node;

	node = stacks->b;
	while (node && node->next)
		node = node->next;
	return (node->index);
}

int	min_b(t_stacks *stacks)
{
	int		min;
	t_node	*node;

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

int	previous_index(t_stacks *stacks, int index)
{
	t_node	*node;
	int		last_i;

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
	return (-1);
}

int	size_stack(t_stacks *stacks, char c)
{
	t_node	*node;
	int		size;

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

int	count_pos_b(t_node *node_, t_stacks *stacks)
{
	int		max;
	int		min;
	int		count;
	int		size_b;
	t_node	*node;

	size_b = size_stack(stacks, 'b');
	max = max_b(stacks);
	min = min_b(stacks);
	count = 0;
	node = stacks->b;
	if (min <= node_->index && node_->index <= max)
	{
		while (!(previous_index(stacks, node->index) >= node_->index
				&& node_->index >= node->index))
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
	return (count);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

void	copy_t_cost(t_cost *dest, t_cost *src)
{
	dest->min_cost = src->min_cost;
	dest->ra = src->ra;
	dest->rb = src->rb;
	dest->rr = src->rr;
	dest->rra = src->rra;
	dest->rrb = src->rrb;
	dest->rrr = src->rrr;
}

void	find_min_cost(t_cost *cost)
{
	t_cost	tmp;

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
		tmp.min_cost = cost->rra + cost->rrb - min(cost->rra, cost->rrb);
	}
	copy_t_cost(cost, &tmp);
}

int	b_direction(int index, t_stacks *stacks)
{
	t_node	*node;
	int		count;

	count = 0;
	node = stacks->b;
	while (node && node->index != index)
	{
		count++;
		node = node->next;
	}
	if (count > size_stack(stacks, 'b') / 2)
		return (0);
	else
		return (1);
}

t_cost	leastcost(t_stacks *stacks, t_cost *final_cost)
{
	t_cost	tmp;
	t_cost	min_cost;
	int		i;
	t_node	*node;
	int		size_a;
	int		size_b;

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

void	algo_pushb2(t_stacks *stacks)
{
	t_cost	cost;
	int		last_value[3];

	stacks->action(PB, stacks);
	if (stacks->n > 4)
		stacks->action(PB, stacks);
	stacks->n = size_stack(stacks, 'a');
	while (stacks->n > 3)
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
		stacks->n = size_stack(stacks, 'a');
	}
	stacks->n = size_stack(stacks, 'a');
	algo_low_n(stacks);
	if (b_direction(max_b(stacks), stacks))
	{
		while (stacks->b->index != max_b(stacks))
			stacks->action(RB, stacks);
	}
	else
	{
		while (stacks->b->index != max_b(stacks))
			stacks->action(RRB, stacks);
	}
	last_value[0] = stacks->a->index;
	last_value[1] = stacks->a->next->index;
	last_value[2] = stacks->a->next->next->index;
	while (stacks->b && stacks->b->index > last_value[2])
		stacks->action(PA, stacks);
	stacks->action(RRA, stacks);
	while (stacks->b && stacks->b->index > last_value[1])
		stacks->action(PA, stacks);
	stacks->action(RRA, stacks);
	while (stacks->b && stacks->b->index > last_value[0])
		stacks->action(PA, stacks);
	stacks->action(RRA, stacks);
	while (stacks->b)
	{
		stacks->action(PA, stacks);
	}
}
