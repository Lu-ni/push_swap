/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicolli <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:31:24 by lnicolli          #+#    #+#             */
/*   Updated: 2023/11/22 16:31:26 by lnicolli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <unistd.h>

t_node	*lstnew(int content)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return ((t_node *)0);
	node->val = content;
	node->index = -1;
	node->next = (t_node *)0;
	return (node);
}

t_node	*lstlast(t_node *lst)
{
	if (!lst)
		return ((t_node *)0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	write_str(char *str, int fd)
{
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}
