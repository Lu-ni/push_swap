#include "libft/libft.h"
#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>

int check_errors(char **argv, int count)
{
	return (0);
}

int parser(int count, char **argv, t_stacks *stacks)
{
	t_node *node;
	int     i;

	i = 2;
	node = lstnew(ft_atoi(argv[1]));
	stacks->a = node;
	while (i < count)
	{
		node->next = lstnew(ft_atoi(argv[i]));
		node = node->next;
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_stacks stacks;

	stacks.action = action_parser;
	stacks.a = (t_node *) 0;
	stacks.b = (t_node *) 0;
	stacks.n = argc - 1;

	if (check_errors(argv, argc)) // todo
		return (1); // the stack passed as argv contain incorrect value
	parser(argc, argv, &stacks);
	add_index(&stacks);
	////// done with mandatory stuff
	if (stacks.n < 4)
		algo_low_n(&stacks);
	else
		algo_pushb2(&stacks);

	return (0);
}
