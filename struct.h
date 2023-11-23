/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:04:36 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/23 10:34:16 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

struct s_stacks;
typedef struct s_node
{
	int				val;
	int				index;
	int				errors;
	struct s_node	*next;
}					t_node;
typedef struct s_cost
{
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				min_cost;
}					t_cost;

typedef void		(*t_action)(int, struct s_stacks *);
typedef struct s_stacks
{
	t_node			*a;
	t_node			*b;
	int				n;
	t_action		action;
	int				size_a;
	int				size_b;

}					t_stacks;
#endif
