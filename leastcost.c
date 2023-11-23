/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leastcost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:04:45 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 10:34:26 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"
#include "struct.h"

void	find_min_cost(t_cost *cost)
{
	t_cost	tmp;

	tmp = (t_cost){0, 0, 0, 0, 0, 0, 100000};
	if (cost->ra + cost->rrb < tmp.min_cost)
		tmp = (t_cost){cost->ra, 0, 0, 0, cost->rrb, 0, cost->ra + cost->rrb};
	if (cost->rra + cost->rb < tmp.min_cost)
		tmp = (t_cost){0, cost->rb, 0, cost->rra, 0, 0, cost->rb + cost->rra};
	if (cost->ra + cost->rb - min(cost->ra, cost->rb) < tmp.min_cost)
	{
		tmp = (t_cost){cost->ra - min(cost->ra, cost->rb), 0, 0, 0, 0, 0,
			100000};
		tmp.rb = cost->rb - min(cost->ra, cost->rb);
		tmp.rr = min(cost->ra, cost->rb);
		tmp.min_cost = cost->ra + cost->rb - min(cost->ra, cost->rb);
	}
	if (cost->rra + cost->rrb - min(cost->rra, cost->rrb) < tmp.min_cost)
	{
		tmp = (t_cost){0, 0, 0, 0, 0, 0, 100000};
		tmp.rra = cost->rra - min(cost->rra, cost->rrb);
		tmp.rrb = cost->rrb - min(cost->rra, cost->rrb);
		tmp.rrr = min(cost->rra, cost->rrb);
		tmp.min_cost = cost->rra + cost->rrb - min(cost->rra, cost->rrb);
	}
	copy_t_cost(cost, &tmp);
}

t_cost	leastcost(t_stacks *stacks, t_cost *final_cost)
{
	t_cost	tmp;
	t_cost	min_cost;
	int		i;
	t_node	*node;

	stacks->size_a = size_stack(stacks, 'a');
	stacks->size_b = size_stack(stacks, 'b');
	i = 0;
	node = stacks->a;
	min_cost.min_cost = 10000000;
	while (node)
	{
		tmp.ra = i;
		tmp.rra = stacks->size_a - i;
		tmp.rb = count_pos_b(node, stacks);
		tmp.rrb = stacks->size_b - tmp.rb;
		find_min_cost(&tmp);
		if (tmp.min_cost < min_cost.min_cost)
			copy_t_cost(&min_cost, &tmp);
		node = node->next;
		i++;
	}
	copy_t_cost(final_cost, &min_cost);
	return (min_cost);
}
