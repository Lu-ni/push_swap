/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:42:29 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 13:59:39 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdlib.h"

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
int	init_str(char **argv, t_stacks *stacks)
{
	int	i;

	i = 0;
	argv = ft_split((const char *)argv[1], ' ');
	if (!argv)
		return (1);
	if (check_errors(argv, 0, 1))
	{
		write_str("Error", 2);
		while (argv[i])
			free(argv[i++]);
		free(argv);
		return (1);
	}
	parser_str(argv, stacks);
	while (argv[i])
		free(argv[i++]);
	free(argv);
	if (check_double(stacks))
	{
		write_str("Error", 2);
		free_stacks(stacks);
		return (1);
	}
	return (0);
}
int	init(char **argv, int argc, t_stacks *stacks)
{
	if (check_errors(argv, argc, 0))
	{
		write_str("Error", 2);
		return (1);
	}
	parser(argc, argv, stacks);
	if (check_double(stacks))
	{
		write_str("Error", 2);
		free_stacks(stacks);
		return (1);
	}
	return (0);
}
