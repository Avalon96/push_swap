#include "bucket_sort.h"
#include "stack.h"
#include "utils.h"
#include "dll.h"
#include "push_swap.h"
#include "generics.h"


int	pushb_buckets_num(t_collector *ctor)
{
	t_bucket_sort * const sorter = ctor->data;
	
	if (bucket_selective(&ctor->ps->a.head->value, 0, &sorter->pushing_bucket) == 0)
	{
		ctor->ps->instruction[ctor->shift_cmd](ctor->ps);
		return (0);
	}
	cdll_iter(ctor->ps->a.head, clear_gap_attr, NULL); // for print_stacks
	ctor->collect_fun(ctor->ps);
	cdll_iter(ctor->ps->a.head, indexer, NULL); // index must correct for finding gap
	sorter->pushing_remaining--;
	return (1);

}

void	push_last_bucket(t_ps *ps)
{
	int i;
	
	i = ps->a.size - 1;
	while (i--)
	{
		push_b(ps);
	}
	push_b_last(ps);
	cdll_iter(ps->b.head, indexer, NULL);
}

void	update_collector(t_ps *ps, t_collector *ctor)
{
	t_find_gap const	*fg = ps->bucket_sort.fg;
	ssize_t 			nearest;

	get_biggest_gap(fg);
	nearest = get_nearest(fg->duo[0]->value.index, fg->duo[1]->value.index, fg->stack); // get_nearest is better than find_gap
	nearest = get_nearest_node(fg->stack, fg->filter, &ps->bucket_sort.pushing_bucket);
	if (nearest > 0)
		ctor->shift_cmd = RA;
	else if (nearest < 0)
		ctor->shift_cmd = RRA;
	ctor->limit = ft_abs(nearest);
}

void	push_first_number_of_first_bucket(t_ps *ps){
	update_collector(ps, ps->bucket_sort.ctor);
	ps->bucket_sort.ctor->collect_fun = &push_b_first;
	while (ps->bucket_sort.ctor->limit-- != (size_t)-1)
		if (pushb_buckets_num(ps->bucket_sort.ctor) == 1)
			return ;
}

void	push_bucket(t_ps *ps){
	while (ps->bucket_sort.pushing_remaining != 0)
	{
		update_collector(ps, ps->bucket_sort.ctor);
		while (ps->bucket_sort.ctor->limit-- != (size_t)-1)
			pushb_buckets_num(ps->bucket_sort.ctor);
		// cdll_iter(ps->b.head, indexer, NULL); // for print_stacks?
		// push_number_of_bucket(ps, fg, push_b);
	}
}


size_t	get_first_bucket(t_ps *ps)
{
	size_t i;

	i = 0;
	while (i < ps->bucket_sort.bucket_ct && \
		ps->bucket_sort.buckets[i].size == 0)
	{
		// printf("skipping bucket %zu, size %zu\n", i, ps->bucket_sort.buckets[i].size);
		i++;
	}
	return (i);
}

void	sort_bucket(t_ps *ps, t_bucket);

void	sort_buckets(t_ps *ps)
{
	ps->bucket_sort.ctor = &(t_collector){
		.ps = ps, .data = &ps->bucket_sort,
	};
	ps->bucket_sort.fg = &(t_find_gap){
		.stack = &ps->a, .filter = bucket_selective, .data = &ps->bucket_sort.pushing_bucket
	};
	ps->bucket_sort.pushing_bucket = get_first_bucket(ps);
	ps->bucket_sort.pushing_remaining = ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
	push_first_number_of_first_bucket(ps);
	ps->bucket_sort.ctor->collect_fun = &push_b;
	while (ps->bucket_sort.pushing_bucket < ps->bucket_sort.bucket_ct - 1)
	{
		push_bucket(ps);
		ps->bucket_sort.pushing_bucket++;
		if (ps->bucket_sort.pushing_bucket >= ps->bucket_sort.bucket_ct)
			break;
		ps->bucket_sort.pushing_remaining = ps->bucket_sort.buckets[ps->bucket_sort.pushing_bucket].size;
	}
	push_last_bucket(ps); // because last bucket not require finding gap.
}

int		bucket_selective(t_custom *v, int i, void *data)
{
	size_t * const bucket = data;
	return (v->this->value.bucket_index == *bucket);
}

/**
 * @brief count buckets
 */
void	count_buckets(t_stack *a, t_bucket_sort *bucket_sort)
{
	cdll_iter(a->head, set_bucket, bucket_sort);
}

void	set_occupied_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort * const bucket_sort = data;
	t_bucket * const bucket = &bucket_sort->buckets[ \
		bucket_sort->bucket_ct * (v->num - bucket_sort->minmax[0]) / (bucket_sort->minmax[1] - bucket_sort->minmax[0] + 1) \
	];

	if (bucket->size > 0 && !bucket->counted)
	{
		bucket->counted = 1;
		bucket_sort->occupied_ct++;
	}
}

/**
 * @brief count occupied buckets
 */
void	count_occupied_buckets(t_stack *a, t_bucket_sort *bucket_sort)
{
	cdll_iter(a->head, set_occupied_bucket, bucket_sort);
}

void	set_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort * const bucket_sort = data;
	size_t const bucket_index = bucket_sort->bucket_ct * (v->num - bucket_sort->minmax[0]) / (bucket_sort->minmax[1] - bucket_sort->minmax[0] + 1);
	t_dll	* const node = v->this;

	v->bucket_index = bucket_index;
	bucket_sort->buckets[bucket_index].size++;
}
