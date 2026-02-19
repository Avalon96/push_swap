#include "bucket_sort.h"
#include "stack.h"
#include "utils.h"
#include "dll.h"
#include "push_swap.h"
#include "generics.h"
#include "insertion_sort.h"
#include "libft.h"
#include <limits.h>

void	push_number_of_bucket(t_ps *ps, t_find_gap *fg, void (*pusher)(t_ps *ps));

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
	// nearest = get_nearest(fg->duo[0]->value.index, fg->duo[1]->value.index, fg->stack); // get_nearest is better than find_gap
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

// void	set_occupied_bucket(t_custom *v, int i, void *data)
// {
// 	t_bucket_sort * const bucket_sort = data;
// 	t_bucket * const bucket = &bucket_sort->buckets[ \
// 		bucket_sort->bucket_ct * ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) / ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1) \
// 	];

// 	if (bucket->size > 0 && !bucket->counted)
// 	{
// 		bucket->counted = 1;
// 		bucket_sort->occupied_ct++;
// 	}
// }

void	set_occupied_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort * const bucket_sort = data;
	size_t bucket_index = bucket_sort->bucket_ct * 
        ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) / 
        ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1);

    if (bucket_index >= bucket_sort->bucket_ct)
        bucket_index = bucket_sort->bucket_ct - 1;

	t_bucket * const bucket = &bucket_sort->buckets[bucket_index];
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

// void	set_bucket(t_custom *v, int i, void *data)
// {
// 		t_bucket_sort * const bucket_sort = data;
// 		size_t const bucket_index = bucket_sort->bucket_ct * ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) / ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1);
// 		t_dll	* const node = v->this;
	
// 		v->bucket_index = bucket_index;
// 		bucket_sort->buckets[bucket_index].size++;
// }

void	set_bucket(t_custom *v, int i, void *data)
{
	t_bucket_sort *const bucket_sort = data;
	size_t bucket_index = bucket_sort->bucket_ct *
						  ((ssize_t)v->num - (ssize_t)bucket_sort->minmax[0]) /
						  ((ssize_t)bucket_sort->minmax[1] - (ssize_t)bucket_sort->minmax[0] + 1);
	if (bucket_index >= bucket_sort->bucket_ct)
		bucket_index = bucket_sort->bucket_ct - 1;
	v->bucket_index = bucket_index;
	bucket_sort->buckets[bucket_index].size++;
}

static int  bucket_has_elements_in_a(t_ps *ps, size_t bucket)
{
    t_dll   *curr;
    int     i;

    if (ps->a.size == 0)
        return (0);
    curr = ps->a.head;
    i = 0;
    while (i < ps->a.size)
    {
        if (curr->value.bucket_index == bucket)
            return (1);
        curr = curr->next;
        i++;
    }
    return (0);
}

static void execute_move_bucket(t_ps *ps, t_move m)
{
    while (m.a_count-- > 0)
    {
        if (m.a_dir == 1)
            rotate_a(ps);
        else
            reverse_rotate_a(ps);
    }
    push_b(ps);
    if (ps->a.size > 0)
        cdll_iter(ps->a.head, indexer, NULL);
    if (ps->b.size > 0)
        cdll_iter(ps->b.head, indexer, NULL);
}

static void set_cheapest_a_only(t_ps *ps, t_move *best, size_t bucket)
{
    t_dll   *curr_a;
    t_move  m;
    int     i;

    curr_a = ps->a.head;
    best->total = 2147483647;
    i = 0;
    while (i < ps->a.size)
    {
        if (curr_a->value.bucket_index == bucket)
        {
            if (i <= ps->a.size / 2)
            {
                m.a_dir = 1;
                m.a_count = i;
            }
            else
            {
                m.a_dir = -1;
                m.a_count = ps->a.size - i;
            }
            m.b_count = 0;
            m.b_dir = 1;
            m.total = m.a_count;
            if (m.total < best->total)
                *best = m;
        }
        curr_a = curr_a->next;
        i++;
    }
}

static void insert_into_segment(t_ps *ps, int seg_len)
{
    int i;

    if (seg_len == 0)
        return ;
    i = 0;
    while (i < seg_len)
    {
        if (ps->b.head->value.num > ps->b.head->next->value.num)
            break ;
        rotate_b(ps);
        i++;
    }
    int max_val = ps->b.head->value.num;
    t_dll *curr = ps->b.head->next;
    int max_steps = 0;
    int steps = 0;
    int j = 1;
    while (j <= seg_len)
    {
        steps++;
        if (curr->value.num > max_val)
        {
            max_val = curr->value.num;
            max_steps = steps;
        }
        curr = curr->next;
        j++;
    }
    while (max_steps-- > 0)
        rotate_b(ps);
    if (ps->b.size > 0)
        cdll_iter(ps->b.head, indexer, NULL);
}

static void sort_segment_in_b(t_ps *ps, int len)
{
    int i;
    int j;
    int max_pos;
    t_dll *curr;

    i = 0;
    while (i < len - 1)
    {
        curr = ps->b.head;
        max_pos = 0;
        int max_val = curr->value.num;
        j = 1;
        curr = curr->next;
        while (j < len - i)
        {
            if (curr->value.num > max_val)
            {
                max_val = curr->value.num;
                max_pos = j;
            }
            curr = curr->next;
            j++;
        }
        if (max_pos <= (len - i) / 2)
        {
            while (max_pos-- > 0)
                rotate_b(ps);
        }
        else
        {
            int back = (len - i) - max_pos;
            while (back-- > 0)
                reverse_rotate_b(ps);
        }
        int sink = len - 1 - i;
        while (sink-- > 0)
            rotate_b(ps);
        i++;
    }
    int restore = len - 1;
    while (restore-- > 0)
        reverse_rotate_b(ps);
    cdll_iter(ps->b.head, indexer, NULL);
}

static void set_cheapest_largest_in_bucket(t_ps *ps, t_move *best, size_t bucket)
{
    t_dll   *curr_a;
    t_move  m;
    int     i;
    int     best_score;

    curr_a = ps->a.head;
    best->total = 2147483647;
    best_score = INT_MIN;
    i = 0;
    while (i < ps->a.size)
    {
        if (curr_a->value.bucket_index == bucket)
        {
            int cost;
            if (i <= ps->a.size / 2)
                cost = i;
            else
                cost = ps->a.size - i;
            int score = curr_a->value.num - cost * 10;
            if (score > best_score)
            {
                best_score = score;
                if (i <= ps->a.size / 2)
                {
                    best->a_dir = 1;
                    best->a_count = i;
                }
                else
                {
                    best->a_dir = -1;
                    best->a_count = ps->a.size - i;
                }
                best->b_count = 0;
                best->b_dir = 1;
                best->total = best->a_count;
            }
        }
        curr_a = curr_a->next;
        i++;
    }
}

static void insertion_sort_bucket(t_ps *ps, size_t bucket)
{
    t_move  best;
    int     bucket_size;
    int     pushed;

    bucket_size = (int)ps->bucket_sort.buckets[bucket].size;
    if (bucket_size == 0)
        return ;
    if (!bucket_has_elements_in_a(ps, bucket))
        return ;

    pushed = 0;
    while (pushed < bucket_size)
    {
        set_cheapest_largest_in_bucket(ps, &best, bucket);
        if (best.total == 2147483647)
            break ;
        execute_move_bucket(ps, best);
        pushed++;
    }
}

static void	find_cheapest_b_to_a(t_ps *ps, t_move *best)
{
	t_dll	*curr_b;
	t_move	m;
	int		i;
	int		target_a;

	curr_b = ps->b.head;
	best->total = 2147483647;
	i = 0;
	while (i < ps->b.size)
	{
		target_a = find_target_in_a(&ps->a, curr_b->value.num);
		if (i <= ps->b.size / 2)
		{
			m.b_dir = 1;
			m.b_count = i;
		}
		else
		{
			m.b_dir = -1;
			m.b_count = ps->b.size - i;
		}
		if (target_a <= ps->a.size / 2)
		{
			m.a_dir = 1;
			m.a_count = target_a;
		}
		else
		{
			m.a_dir = -1;
			m.a_count = ps->a.size - target_a;
		}
		if (m.a_dir == m.b_dir)
		{
			if (m.a_count > m.b_count)
				m.total = m.a_count;
			else
				m.total = m.b_count;
		}
		else
			m.total = m.a_count + m.b_count;
		if (m.total < best->total)
			*best = m;
		curr_b = curr_b->next;
		i++;
	}
}

static void	execute_move_to_a(t_ps *ps, t_move m)
{
	while (m.a_dir == m.b_dir && m.a_count > 0 && m.b_count > 0)
	{
		if (m.a_dir == 1)
			rotate_both(ps);
		else
			reverse_rotate_both(ps);
		m.a_count--;
		m.b_count--;
	}
	while (m.a_count-- > 0)
	{
		if (m.a_dir == 1)
			rotate_a(ps);
		else
			reverse_rotate_a(ps);
	}
	while (m.b_count-- > 0)
	{
		if (m.b_dir == 1)
			rotate_b(ps);
		else
			reverse_rotate_b(ps);
	}
	push_a(ps);
}

static void	push_b_to_a(t_ps *ps)
{
	t_move	best;

	while (ps->b.size > 0)
	{
		if (ps->a.size == 0)
		{
			push_a(ps);
			continue ;
		}
		find_cheapest_b_to_a(ps, &best);
		execute_move_to_a(ps, best);
	}
	cdll_iter(ps->a.head, indexer, NULL);
	rotate_a_to_top(ps, get_min_pos(&ps->a));
	cdll_iter(ps->a.head, indexer, NULL);
}

void    sort_buckets_insertion(t_ps *ps)
{
    size_t  bucket;

    // printf("sort_buckets_insertion start: a.size=%d, b.size=%d\n", ps->a.size, ps->b.size);
    bucket = ps->bucket_sort.bucket_ct;
    // while (bucket > 0)
    // {
    //     bucket--;
    //     // printf("processing bucket %zu\n", bucket);
    //     insertion_sort_bucket(ps, bucket);
	// 	// print_stacks(ps);
	// 	// getchar();
    // }
	// push_b_last(ps);

	sort_buckets(ps);
	
	print_stacks(ps);
	dprintf(2, "==[DEBUG]== %zu\n", ps->ops_count);
	// getchar();

    // printf("pushing back to a\n");
    push_b_to_a(ps);
}
