#include "push_swap.h"
#include "insertion_sort.h"

int		brute_force(t_ps *ps)
{
	float	disorder;
	int		flag;

	if (ps->a.size > 5)
		return (0);
	flag = ps->a.size - 3;
	if (ps->a.size == 5)
	{
		rotate_a_to_top(ps, get_max_pos(&ps->a));
		push_b(ps);
	}
	if (ps->a.size == 4)
	{
		rotate_a_to_top(ps, get_min_pos(&ps->a));
		push_b(ps);
	}
	sort_three_a(ps);
	while (flag--)
		push_a(ps);
	compute_disorder(&ps->a, &disorder);
	if (disorder != 0)
		rotate_a_to_top(ps, get_min_pos(&ps->a));
	return (1);
}
