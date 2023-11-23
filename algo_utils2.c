/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:59:58 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 10:38:46 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algo.h"
#include "push_swap.h"
#include "struct.h"

int	count_pos_b(t_node *node_, t_stacks *stacks)
{
	int		max;
	int		min;
	int		count;
	t_node	*node;

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
		while (node->index != max && ++count)
			node = node->next;
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
