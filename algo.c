/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 20:26:16 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:55 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"
#include "struct.h"

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
