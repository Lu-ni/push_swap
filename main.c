/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:38:54 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 13:02:34 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "struct.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int	parser(int count, char **argv, t_stacks *stacks)
{
	t_node	*node;
	int		i;

	i = 2;
	node = lstnew(atoi_ps(argv[1]));
	stacks->a = node;
	while (i < count)
	{
		node->next = lstnew(atoi_ps(argv[i]));
		node = node->next;
		i++;
	}
	return (0);
}

int	parser_str(char **argv, t_stacks *stacks)
{
	t_node	*node;
	int		i;

	i = 1;
	node = lstnew(atoi_ps(argv[0]));
	stacks->a = node;
	while (argv[i])
	{
		node->next = lstnew(atoi_ps(argv[i]));
		node = node->next;
		i++;
	}
	stacks->n = i;
	return (0);
}

int	check_double(t_stacks *stacks)
{
	t_node	*node;
	t_node	*tmp;

	node = stacks->a;
	while (node->next)
	{
		tmp = node->next;
		while (tmp)
		{
			if (tmp->val == node->val)
				return (1);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (0);
}

void free_stacks(t_stacks *stacks)
{
	t_node *actual;
	t_node *next;

	actual = stacks->a;
	while(actual)
	{
		next = actual->next;
		free(actual);
		actual = next;
	}
	actual = stacks->b;
	while(actual)
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
		return 0;
	if (argc == 2)
	{
		argv = ft_split((const char *)argv[1], ' ');
		if(!argv)
			return 1;
	}
	//if (check_errors(argv, argc))
	//{
	//	write_str("Error", 2);
	//	return (1);
	//}
	if(argc ==2)
		parser_str(argv, &stacks);
	else
		parser(argc, argv, &stacks);
	if (check_double(&stacks))
	{
		write_str("Error", 2);
		free_stacks(&stacks);
		return (1);
	}
	/// don't change
	add_index(&stacks);
	if (check_sorted(&stacks))
	{
		free_stacks(&stacks);
		return (0);
	}
	if (stacks.n < 4)
		algo_low_n(&stacks);
	else
		algo_pushb2(&stacks);
	free_stacks(&stacks);
	return (0);
}
