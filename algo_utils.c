/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:34:12 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 09:59:02 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
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
