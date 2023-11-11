#include "struct.h"

void action_p(t_stacks *stacks, char stack)
{
	t_node *node1;
	t_node *node2;
	if (stack == 'b' && stacks->a)
	{
		node1 = stacks->a;
		stacks->a = node1->next;
		node1->next = stacks->b;
		stacks->b = node1;
	}
	if (stack == 'a' && stacks->b)
	{
		node1 = stacks->b;
		stacks->b = node1->next;
		node1->next = stacks->a;
		stacks->a = node1;
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
}
