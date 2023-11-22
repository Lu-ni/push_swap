#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>

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

void add_index(t_stacks *stacks)
{
	int     min;
	t_node *node;
	int     i;

	i = 0;
	node = stacks->a;
	min = INT_MAX;
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
		min = INT_MAX;
	}
}
void print_stack(t_stacks *stacks)
{
	t_node *a;
	t_node *b;

	a = stacks->a;
	b = stacks->b;
	printf("--------------------\n");
	while (a || b)
	{
		if (a)
		{
			printf("a:%i", a->index);
			a = a->next;
		}
		printf("\t");
		if (b)
		{
			printf("b:%i", b->index);
			b = b->next;
		}
		printf("\n");
	}
	printf("--------------------\n");
}
