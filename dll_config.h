#ifndef DLL_CONFIG_H
# define DLL_CONFIG_H

# include <stddef.h>
# include <stdint.h>

typedef struct s_dll t_dll;

typedef int16_t t_attrs_ps; 

typedef enum	e_attr_ps
{
	GAP_A = (1 << 0),
	GAP_B = (1 << 1)
}	t_attr_ps;

typedef struct	s_custom
{
	int			num;
	size_t		index; // dont forget to update
	size_t		bucket_index; // dont forget to update
	t_dll		*this;
	t_attrs_ps	attr;
}	t_custom;


#endif // DLL_CONFIG_H
