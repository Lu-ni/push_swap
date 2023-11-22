#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>

int check_errors(char **argv, int count)
{
	int i;
	int ii;

	i = 1;
	ii = 0;
	while (i < count)
	{	
		ii= 0;
		while(argv[i][ii])
		{
			if(!('0' <= argv[i][ii] && argv[i][ii] <= '9'))
				return 1;
			ii++;
		}
		i++;
	}
	return (0);
}

int parser(int count, char **argv, t_stacks *stacks)
{
	t_node *node;
	int     i;

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
	if (check_sorted(&stacks))
		return (0);
	if (stacks.n < 4)
		algo_low_n(&stacks);
	else
		algo_pushb2(&stacks);

	return (0);
}
