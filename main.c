#include "libft/libft.h"
#include "node_utils.h"
#include "struct.h"
#include <stdio.h>

int check_errors(char **argv, int count)
{
	return (0);
}

void print_stack(t_stacks *stacks)
{
	t_node *a;
	t_node *b;

	a = stacks->a;
	b = stacks->b;
	printf("--------\n");
	while (a || b)
	{
		if (a)
		{
			printf("a:%i\t", a->val);
			a = a->next;
		}
		if (b)
		{
			printf("b:%i", b->val);
			b = b->next;
		}
		printf("\n");
	}
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

	if (check_errors(argv, argc)) // todo
		return (1); // the stack passed as argv contain incorrect value
	parser(argc, argv, &stacks);
	print_stack(&stacks);
	stacks.action(PB, &stacks);
	print_stack(&stacks);
	stacks.action(PB, &stacks);
	print_stack(&stacks);
	stacks.action(RRR, &stacks);
	print_stack(&stacks);

	return (0);
}
