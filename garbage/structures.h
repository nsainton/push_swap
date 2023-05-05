/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 02:43:50 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/09 13:23:22 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H
# include "libraries.h"
# include "typedefs.h"

typedef struct s_moves
{
	int	ra;
	int	rb;
	int	rr;
	int	pa;
	int	pb;
	int	rra;
	int	rrb;
	int	rrr;
	int	direction;
}				t_moves;

typedef struct s_cost
{
	int	a_size;
	int	a_moves;
	int	b_size;
	int	b_moves;
}				t_cost;

typedef struct s_stack
{
	t_list		*top;
	t_list		*bottom;
	size_t		size;
	char		*name;
	t_compfunc	cmp;
}				t_stack;

typedef struct s_infos
{
	size_t		disorder;
	size_t		ops;
}				t_infos;

typedef const t_stack	t_cstack;

#endif
