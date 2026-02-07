#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MSG_ERROR "Error\n"

# include <unistd.h>

typedef struct s_lld t_lld;
typedef struct s_lld
{
	int		value;
	t_lld	*next;
	t_lld	*prev;
}				t_lld;

typedef struct s_stack t_stack;
typedef struct s_stack
{
	t_lld	*top;
	// t_lld	*bottom;
	int		size;
}				t_stack;

typedef enum e_cmd
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_cmd;

typedef enum e_flags
{
	STRATEGY_SIMPLE,
	STRATEGY_MEDIUM,
	STRATEGY_COMPLEX,
	STRATEGY_ADAPTIVE,
	UNDEFINED
}			t_flags;

typedef struct s_ps
{
	t_stack	a;
	t_stack b;

	int		bench;
	t_flags	strategy;
	int 	err;
	float	disorder;
}				t_ps;

ssize_t ft_atol(const char *str);

t_lld	*ft_lldnew(int value);
void	ft_lldadd_front(t_lld **lst, t_lld *new);
int	ft_lldsize(t_lld *lst);
void	ft_lldclear(t_lld **lst);
void	ft_llditer(t_lld *lst, void (*f)(int *v, int i));

int compute_disorder(t_stack *a, float *disorder);

#endif // PUSH_SWAP_H
