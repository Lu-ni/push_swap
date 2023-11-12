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
			printf("a (%i):%i\t", a->index, a->val);
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

void add_index(t_stacks *stacks)
{
	int     min;
	t_node *node;
	int     i;

	i = 0;
	node = stacks->a;
	min = 9999; // set to maxint
	while (i < stacks->n)
	{
		node = stacks->a;
		while (node)
		{
			if (node->val < min && node->index == -1)
				min = node->val;
			node = node->next;
		}
		node = stacks->a;
		while (node)
		{
			if (node->val == min)
				node->index = i++;
			node = node->next;
		}
		min = 9999; // set to maxint
	}
}

int check_sorted(t_stacks *stacks)
{
	int     index;
	t_node *node;

	index = 0;
	node = stacks->a;
	while (node)
	{
		if (node->index == index)
		{
			node = node->next;
			index++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

int algo1(t_stacks *stacks) // not working
{
	t_node *node;
	int     trigger;

	node = stacks->a;
	while (!check_sorted(stacks))
	{
		if (node->next && node->index > node->next->index)
			stacks->action(SA, stacks);
		stacks->action(RRA, stacks);
		node = stacks->a;
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
	print_stack(&stacks);
	algo1(&stacks);
	print_stack(&stacks);

	return (0);
}
