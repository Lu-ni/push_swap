/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:31:40 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 10:05:44 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_H
# define ALGO_H

# include "push_swap.h"
# include "struct.h"

int		max_b(t_stacks *stacks);
int		last_index_b(t_stacks *stacks);
int		min_b(t_stacks *stacks);
int		previous_index(t_stacks *stacks, int index);
int		size_stack(t_stacks *stacks, char c);
int		count_pos_b(t_node *node_, t_stacks *stacks);
int		min(int a, int b);
void	copy_t_cost(t_cost *dest, t_cost *src);
int		b_direction(int index, t_stacks *stacks);
t_cost	leastcost(t_stacks *stacks, t_cost *final_cost);
void	find_min_cost(t_cost *cost);
#endif
