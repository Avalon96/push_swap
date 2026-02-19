
#ifndef PUSH_SWAP_DEFS_H
# define PUSH_SWAP_DEFS_H

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

typedef struct s_ps	t_ps;


#endif // PUSH_SWAP_DEFS_H
