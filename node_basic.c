#include "libft/libft.h"
#include "struct.h"
#include <stdlib.h>

t_node *lstnew(int content)
{
	t_node *node;

	node = (t_node *) malloc(sizeof(struct s_list));
	if (!node)
		return ((t_node *) 0);
	node->val = content;
	node->next = (t_node *) 0;
	return (node);
}
