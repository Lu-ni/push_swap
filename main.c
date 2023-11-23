/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:54 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 15:34:47 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void	free_stacks(t_stacks *stacks)
{
	t_node	*actual;
	t_node	*next;

	actual = stacks->a;
	while (actual)
	{
		next = actual->next;
		free(actual);
		actual = next;
	}
	actual = stacks->b;
	while (actual)
	{
		next = actual->next;
		free(actual);
		actual = next;
	}
}
int	main(int argc, char **argv)
{
	t_stacks	stacks;

	stacks.action = action_parser;
	stacks.a = (t_node *)0;
	stacks.b = (t_node *)0;
	stacks.n = argc - 1;
	if (argc < 2)
		return (0);
	else if (argc == 2 && init_str(argv, &stacks))
		return (0);
	else if (argc > 2 && init(argv, argc, &stacks))
		return (0);
	add_index(&stacks);
	if (stacks.n < 4)
		algo_low_n(&stacks);
	else
		algo_pushb2(&stacks);
	free_stacks(&stacks);
	return (0);
}
