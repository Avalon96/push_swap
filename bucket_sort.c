#include "bucket_sort.h"
#include "stack.h"
#include "utils.h"
#include "dll.h"
#include "push_swap.h"
#include "generics.h"
#include "insertion_sort.h"

void	push_number_of_bucket(t_ps *ps, t_find_gap *fg, void (*pusher)(t_ps *ps));

void	push_bucket(t_ps *ps, t_find_gap *fg, size_t bucket, size_t left_size){
	if (left_size == 0)
		return ;
	fg->data = &bucket; // < ps->bucket_sort.bucket_ct && (ps->bucket_sort.buckets[bucket].size != 0)
	while (--left_size > 0)
	{
		// printf("bucket %zu, left_size %zu\n", bucket, left_size);
		push_number_of_bucket(ps, fg, push_b);
	}
	if (fg->stack->size == 1)
	{
		// printf("pushing with push_b_last\n");
		push_number_of_bucket(ps, fg, push_b_last);
	}
	else
	{
		// printf("pushing with push_b\n");
		push_number_of_bucket(ps, fg, push_b);
	}
	
}

void	push_head(t_ps *ps, t_find_gap *fg, size_t *left_size)
{
	size_t i;
	
	i = 0;
	while (i < ps->bucket_sort.bucket_ct && \
		ps->bucket_sort.buckets[i].size == 0)
	{
		// printf("skipping bucket %zu, size %zu\n", i, ps->bucket_sort.buckets[i].size);
		i++;
	}
	// printf("selected bucket: %zu, size: %zu\n", i, ps->bucket_sort.buckets[i].size);
	fg->data = &i; // < ps->bucket_sort.bucket_ct && (ps->bucket_sort.buckets[bucket].size != 0)
	*left_size = ps->bucket_sort.buckets[i].size;
	push_number_of_bucket(ps, fg, push_b_first);
	--(*left_size);
}

void	sort_bucket(t_ps *ps, t_bucket);

// void	sort_buckets_nums(t_ps *ps)
// {
// 	size_t	bucket;
	
// 	bucket = 0;
// 	while (bucket < ps->bucket_sort.bucket_ct)
// 	{
// 		if (ps->bucket_sort.buckets[bucket].size > 0)
// 			sort_bucket(ps, ps->bucket_sort.buckets[bucket]);
// 		bucket++;
// 	}
// }

void	sort_buckets(t_ps *ps)
{
	t_find_gap * const fg = &(t_find_gap){
		.stack = &ps->a, .filter = bucket_selective
	};
	size_t	bucket;
	size_t	left_size;

	bucket = 0;
	push_head(ps, fg, &left_size);
	// printf("after head left_size: %zu\n", left_size);
	while (bucket < ps->bucket_sort.bucket_ct)
	{
		push_bucket(ps, fg, bucket, left_size);
		bucket++;
		if (bucket >= ps->bucket_sort.bucket_ct)
			break;
		left_size = ps->bucket_sort.buckets[bucket].size;
	}
}


void	push_number_of_bucket(t_ps *ps, t_find_gap *fg, void (*pusher)(t_ps *ps))
{
		// printf("ps head: %zu, num: %d\n", ps->a.head->value.index, ps->a.head->value.num);
		// printf("fg head: %zu, num: %d\n", fg->stack->head->value.index, fg->stack->head->value.num);
		get_biggest_gap(fg);
		// printf("ps head: %zu, num: %d\n", ps->a.head->value.index, ps->a.head->value.num);
		// printf("fg head: %zu, num: %d\n", fg->stack->head->value.index, fg->stack->head->value.num);
		// print_stacks(ps);
		// printf("biggest gap: %zu...%zu\n", fg->duo[0]->value.index, fg->duo[1]->value.index);
		// go_best(&ps->a, );
		ssize_t nearest = get_nearest(fg->duo[0]->value.index, fg->duo[1]->value.index, fg->stack);
		// printf("nearest: %zd\n", nearest);
		
		// printf("ps head: %zu, num: %d\n", ps->a.head->value.index, ps->a.head->value.num);
		// printf("fg head: %zu, num: %d\n", fg->stack->head->value.index, fg->stack->head->value.num);
		
		// print_stacks(ps);
		rotator(ps, nearest, 'a');

		cdll_iter(ps->a.head, indexer, NULL);
		// print_stacks(ps);

		// printf("ps head: %zu, num: %d\n", ps->a.head->value.index, ps->a.head->value.num);
		// printf("fg head: %zu, num: %d\n", fg->stack->head->value.index, fg->stack->head->value.num);

		cdll_iter(ps->a.head, clear_gap_attr, NULL);
		// push; index a, b;
		pusher(ps);
		if (ps->a.size > 0)
			cdll_iter(ps->a.head, indexer, NULL);
		cdll_iter(ps->b.head, indexer, NULL);
		// print_stacks(ps);
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
		bucket_sort->bucket_ct * ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) / ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1) \
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
	size_t const bucket_index = bucket_sort->bucket_ct * ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) / ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1);
	t_dll	* const node = v->this;

	v->bucket_index = bucket_index;
	bucket_sort->buckets[bucket_index].size++;
}

static void	set_cheap(int i, t_ps *ps, t_move *m, int target_b)
{
	if (i <= ps->a.size / 2)
	{
		(*m).a_dir = 1;
		(*m).a_count = i;
	}
	else
	{
		(*m).a_dir = -1;
		(*m).a_count = ps->a.size - i;
	}
	if (target_b <= ps->b.size / 2)
	{
		(*m).b_dir = 1;
		(*m).b_count = target_b;
	}
	else
	{
		(*m).b_dir = -1;
		(*m).b_count = ps->b.size - target_b;
	}
}

static void	set_best(t_move *m, t_move **best)
{
	if ((*m).a_dir == (*m).b_dir)
	{
		if ((*m).a_count > (*m).b_count)
			(*m).total = (*m).a_count;
		else
			(*m).total = (*m).b_count;
	}
	else
		(*m).total = (*m).a_count + (*m).b_count;
	if ((*m).total < (*best)->total)
		**best = *m;
}

static void	set_cheapest_move(t_ps *ps, t_move *best)
{
	t_dll	*curr_a;
	t_move	m;
	int		i;
	int		target_b;

	curr_a = ps->a.head;
	best->total = 2147483647;
	i = 0;
	while (i < ps->a.size)
	{
		target_b = find_target_in_b(&ps->b, curr_a->value.num);
		set_cheap(i, ps, &m, target_b);
		set_best(&m, &best);
		curr_a = curr_a->next;
		i++;
	}
}

void    bucket_insertion_sort(t_ps *ps)
{
    t_move  best;
    int     target;

    while (ps->a.size > 0)
    {
        set_cheapest_move(ps, &best);
        execute_move(ps, best);
    }
    while (ps->b.size > 0)
    {
        target = find_target_in_a(&ps->a, ps->b.head->value.num);
        rotate_a_to_top(ps, target);
        push_a(ps);
    }
    rotate_a_to_top(ps, get_min_pos(&ps->a));
}