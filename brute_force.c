#include "push_swap.h"
#include "insertion_sort.h"

int		brute_force(t_ps *ps)
{
	int		flag;

	if (ps->a.size > 5)
		return (0);
	flag = ps->a.size - 3;
	while (ps->a.size > 3)
	{
		rotate_a_to_top(ps, get_min_pos(&ps->a));
		push_b(ps);
	}
	sort_three_a(ps);
	while (flag--)
		push_a(ps);
	return (1);
}
