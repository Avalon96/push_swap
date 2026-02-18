#include "push_swap.h"
#include "bucket_sort.h"
#include "utils.h"
#include "libft.h"
#include "generics.h"

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
	sort_buckets(ps);
	// sort_bucket(ps);
	return (0);
}

int complex_sort(t_ps *ps)
{
	return (0);
}

int adaptive_sort(t_ps *ps)
{
	return (0);
}

int simple_sort(t_ps *ps)
{
	return (0);
}
