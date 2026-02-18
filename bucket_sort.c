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

static void push_b_to_a(t_ps *ps)
{
    int target;

	dprintf(2, "==[DEBUG]== %zu\n", ps->ops_count);
    while (ps->b.size > 0)
    {
        if (ps->a.size == 0)
        {
            push_a(ps);
            cdll_iter(ps->a.head, indexer, NULL);
            continue ;
        }
        cdll_iter(ps->a.head, indexer, NULL);
        target = find_target_in_a(&ps->a, ps->b.head->value.num);
        rotate_a_to_top(ps, target);
        push_a(ps);

		// print_stacks(ps);
		// getchar();
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
	// 	print_stacks(ps);
	// 	getchar();
    // }

	sort_buckets(ps);
	
    // printf("pushing back to a\n");
    push_b_to_a(ps);
}
