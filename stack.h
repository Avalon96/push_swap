#ifndef STACK_H
# define STACK_H

# include "dll.h"

typedef struct s_stack t_stack;
typedef struct s_stack
{
	t_dll	*head;
	int		size;
}				t_stack;

#endif // STACK_H

