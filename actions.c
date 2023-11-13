#include "node_utils.h"
#include "struct.h"
#include <stdio.h>

void action_r(t_stacks *stacks, char stack)
{
	t_node *node1;
	t_node *node2;
	if ((stack == 'a' || stack == 'r') && stacks->a && stacks->a->next)
	{
		node1 = stacks->a;
		stacks->a = node1->next;
		node1->next = (t_node *) 0;
		node2 = lstlast(stacks->a);
		node2->next = node1;
		printf("sa");
	}
	if ((stack == 'b' || stack == 'r') && stacks->b && stacks->b->next)
	{
		node1 = stacks->b;
		stacks->b = node1->next;
		node1->next = (t_node *) 0;
		node2 = lstlast(stacks->b);
		node2->next = node1;
		printf("sb");
	}
}
void action_rr(t_stacks *stacks, char stack)
{
	t_node *node1;
	t_node *node2;
	if ((stack == 'a' || stack == 'r') && stacks->a && stacks->a->next)
	{
		node1 = lstlast(stacks->a);
		node1->next = stacks->a;
		stacks->a = node1;
		node2 = node1;
		while (node2->next != node1)
			node2 = node2->next;
		node2->next = (t_node *) 0;
		printf("rra");
	}
	if ((stack == 'b' || stack == 'r') && stacks->b && stacks->b->next)
	{
		node1 = lstlast(stacks->b);
		node1->next = stacks->b;
		stacks->b = node1;
		node2 = node1;
		while (node2->next != node1)
			node2 = node2->next;
		node2->next = (t_node *) 0;
		printf("rrb");
	}
}
void action_p(t_stacks *stacks, char stack)
{
	t_node *node1;
	if (stack == 'b' && stacks->a)
	{
		node1 = stacks->a;
		stacks->a = node1->next;
		node1->next = stacks->b;
		stacks->b = node1;
		printf("pb");
	}
	if (stack == 'a' && stacks->b)
	{
		node1 = stacks->b;
		stacks->b = node1->next;
		node1->next = stacks->a;
		stacks->a = node1;
		printf("pa");
	}
}
void action_s(t_stacks *stacks, char stack)
{
	// this should manage a & b, not the case yet. It should also be protecting against edge case (only one element in stack)
	t_node *node1;
	t_node *node2;

	if (stack == 'a' || stack == 's')
	{
		node1 = stacks->a;
		node2 = node1->next;
		node1->next = node2->next;
		node2->next = node1;
		stacks->a = node2;
	}
	if (stack == 'b' || stack == 's')
	{
		node1 = stacks->b;
		node2 = node1->next;
		node1->next = node2->next;
		node2->next = node1;
		stacks->b = node2;
	}
}

void action_parser(int act, t_stacks *stacks)
{
	if (act == SA)
		action_s(stacks, 'a');
	if (act == SB)
		action_s(stacks, 'b');
	if (act == SS)
		action_s(stacks, 's');
	if (act == PA)
		action_p(stacks, 'a');
	if (act == PB)
		action_p(stacks, 'b');
	if (act == RA)
		action_r(stacks, 'a');
	if (act == RB)
		action_r(stacks, 'b');
	if (act == RR)
		action_r(stacks, 'r');
	if (act == RRA)
		action_rr(stacks, 'a');
	if (act == RRB)
		action_rr(stacks, 'b');
	if (act == RRR)
		action_rr(stacks, 'r');
	printf("\n");
	add_delta(stacks);
}
