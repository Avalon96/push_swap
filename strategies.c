#include "push_swap.h"
#include "bucket_sort.h"
#include "utils.h"
#include "libft.h"
#include "generics.h"
#include <stdio.h>
#include "bucket_sort.h"


int	medium_sort(t_ps *ps)
{
	t_bucket_sort * const bucket_sort = &ps->bucket_sort;
	
	bucket_sort->bucket_ct = safe_sqrt(ps->a.size);
	cdll_iter(ps->a.head, minmax, &bucket_sort->minmax);
	cdll_iter(ps->a.head, indexer, NULL);
	printf("bucket ct: %zu, min: %d, max: %d\n", bucket_sort->bucket_ct, bucket_sort->minmax[0], bucket_sort->minmax[1]);
	bucket_sort->buckets = ft_calloc( bucket_sort->bucket_ct, sizeof(t_bucket));
	if (!bucket_sort->buckets)
		return (-1);
	count_buckets(&ps->a, bucket_sort);
	for (size_t i = 0; i < bucket_sort->bucket_ct; i++)
		printf("	[%zu]: size %zu\n", i, bucket_sort->buckets[i].size);
	count_occupied_buckets(&ps->a, bucket_sort);
	printf("occupied ct: %zu\n", bucket_sort->occupied_ct);
	fflush(stdout);
	getchar();
	// sort_buckets(ps);
	// print_stacks(ps);
	// sort_bucket(ps);
	// printf("calling sort_buckets_insertion\n");
	sort_buckets_insertion(ps);
	// printf("sort_buckets_insertion done\n");
	return (0);
}

int complex_sort(t_ps *ps){
	radix_sort(ps);
	return (0);
}

int adaptive_sort(t_ps *ps){
	(void)ps;
	return (0);
}

int simple_sort(t_ps *ps){
	insertion_sort(ps);
	return (0);
}
