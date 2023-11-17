#include "libft/libft.h"
#include "node_utils.h"
#include "struct.h"
#include <limits.h>
#include <stdio.h>
void add_delta(t_stacks *stacks)
{
	int     i;
	t_node *node;

	i = 0;
	node = stacks->a;
	while (node)
	{
		node->delta = i - node->index;
		node = node->next;
		i++;
	}
}

void add_i(t_stacks *stacks)
{
	int     i;
	t_node *node;

	i = 0;
	node = stacks->a;
	while (node)
	{
		node->i = i++;
		node = node->next;
	}
}

void add_i_relative(t_stacks *stacks)
{
	int     i;
	t_node *node;

	i = 0;
	node = stacks->a;
	while (node)
	{
		if (node->i_relative == 0)
			break;
		node = node->next;
	}
	while (node && i < stacks->n)
	{
		node->i_relative = i++;
		if (node->next)
			node = node->next;
		else
			node = stacks->a;
	}
}

void set_zero_relative(t_stacks *stacks)
{
	t_node *node;
	node = stacks->a;
	while (node)
	{
		if (node->index == 0)
		{
			node->i_relative = 0;
			return;
		}
		node = node->next;
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
	printf("--------\n");
	printf("|a|\tindex\tdelta\tval\ti\ti_rel\n");
	while (a || b)
	{
		if (a)
		{
			printf("a\t%i\t%i\t%i\t%i\t%i\t", a->index, a->delta, a->val, a->i, a->i_relative);
			a = a->next;
		}
		if (b)
		{
			printf("b:%i", b->index);
			b = b->next;
		}
		printf("\n");
	}
}
