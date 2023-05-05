/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:30:51 by nsainton          #+#    #+#             */
/*   Updated: 2023/01/31 05:14:05 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_sign(const char **s, int *minus, t_ll *res)
{
	*minus = 1;
	*res = 0;
	if (**s == '+' || **s == '-')
	{
		*minus = (**s == '+') * 2 - 1;
		*s += 1;
		*res = 1;
	}
}

static int	fillnum(const char **s, t_ll *res, const char *base, int minus)
{
	char	*index;
	size_t	baselen;

	baselen = ft_strlen(base);
	index = ft_strchr(base, **s);
	if (*res && (! index || (size_t)(index - base) == baselen))
		return (1);
	*res = 0;
	while (**s && **s != ' ')
	{
		index = ft_strchr(base, **s);
		if (! index)
			return (1);
		*res = *res * baselen + index - base;
		if (*res * (minus == 1) > INT_MAX || *res * (minus == -1) < INT_MIN)
			return (1);
		(*s)++;
	}
	return (0);
}

int	ft_atoi_errors(const char **s, const char *base, int *err)
{
	t_ll	res;
	int		minus;

	*err = 0;
	if (**s == ' ' || ! **s)
	{
		if (**s)
			*s += 1;
		return (0);
	}
	set_sign(s, &minus, &res);
	if (fillnum(s, &res, base, minus))
	{
		*err = 1;
		return (0);
	}
	return ((int)(minus * res));
}
