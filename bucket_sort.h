#ifndef BUCKET_SORT_H
# define BUCKET_SORT_H

#include <stddef.h>
#include <unistd.h>
# include "dll.h"
# include "stack.h"
typedef struct s_ps t_ps;
typedef struct	s_bucket
{
	size_t	size;
	t_dll	*head; // necessary?
	int		counted;
}	t_bucket;

typedef struct	s_bucket_sort
{
	size_t		bucket_ct;
	int			minmax[2]; // [0] = min, [1] = max
	size_t		occupied_ct;
	// occupied buckets indexes variable
	t_bucket	*buckets;
}	t_bucket_sort;

void	set_bucket(t_custom *v, int i, void *data);
void	count_buckets(t_stack *a, t_bucket_sort *bucket_sort);
int		bucket_selective(t_custom *v, int i, void *data);
void	count_occupied_buckets(t_stack *a, t_bucket_sort *bucket_sort);
void	sort_buckets(t_ps *ps);
void	rotator(t_ps *ps, ssize_t idx, char c);
void	sort_buckets_insertion(t_ps *ps);

#endif // BUCKET_SORT_H
