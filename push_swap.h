/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:31:10 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 09:46:28 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "struct.h"

t_node	*lstnew(int content);
t_node	*lstlast(t_node *lst);

// stack tools
void	action_s(t_stacks *stacks, char stack);
void	action_parser(int act, t_stacks *stacks);
int		check_sorted(t_stacks *stacks);
void	add_index(t_stacks *stacks);
void	print_stack(t_stacks *stacks);
void	algo_pushb2(t_stacks *stacks);
void	algo_low_n(t_stacks *stacks);
void	sort_n_3(t_stacks *stacks);
int		atoi_ps(const char *str);
int		strlen_ps(const char *str);
int		check_errors(char **argv, int count);
void	write_str(char *str, int fd);
#endif
