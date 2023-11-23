/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:31:31 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 09:50:10 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"
#include <limits.h>

int	check_sorted(t_stacks *stacks)
{
	int		index;
	t_node	*node;

	index = 0;
	node = stacks->a;
	while (node)
	{
		if (node->index == index)
		{
			node = node->next;
			index++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

void	add_index(t_stacks *stacks)
{
	int		min;
	t_node	*node;
	int		i;

	i = 0;
	node = stacks->a;
	min = INT_MAX;
	while (i < stacks->n)
	{
		node = stacks->a;
		while (node)
		{
			if (node->val < min && node->index == -1)
				min = node->val;
			node = node->next;
		}
		node = stacks->a;
		while (node)
		{
			if (node->val == min)
				node->index = i++;
			node = node->next;
		}
		min = INT_MAX;
	}
}
