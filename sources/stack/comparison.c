/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:01:16 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 14:18:20 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	descending(t_clist *p, t_clist *q)
{
	return (*(int *)getcontent(p) > *(int *)getcontent(q));
}

int	ascending(t_clist *p, t_clist *q)
{
	return (*(int *)getcontent(p) < *(int *)getcontent(q));
}

t_clist	*findextreme(t_clist *stk, t_compfunc cmp)
{
	t_clist	*ext;

	ext = stk;
	while (stk)
	{
		if (cmp(stk, ext))
			ext = stk;
		stk = getnext(stk);
	}
	return (ext);
}

t_clist	*findmin(t_clist *stk)
{
	return (findextreme(stk, ascending));
}

t_clist	*findmax(t_clist *stk)
{
	return (findextreme(stk, descending));
}
