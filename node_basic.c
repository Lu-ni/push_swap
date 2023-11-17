#include "libft/libft.h"
#include "struct.h"
#include <stdlib.h>

t_node *lstnew(int content)
{
	t_node *node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return ((t_node *) 0);
	node->val = content;
	node->index = -1;
	node->delta = 0;
	node->i = -1;
	node->i_relative = -1;
	node->next = (t_node *) 0;
	return (node);
}

t_node *lstlast(t_node *lst)
{
	if (!lst)
		return ((t_node *) 0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
