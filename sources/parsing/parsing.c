/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 22:14:26 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/14 12:02:31 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	multiple_spaces(const char **s)
{
	int	multiple;

	multiple = 0;
	if (**s && **s == ' ')
	{
		multiple = 1;
		*s += 1;
	}
	if (multiple && (! **s || **s == ' '))
		return (1);
	return (0);
}

int	parse_arg(t_cchar *arg)
{
	t_cchar	*cpy;
	int		err;

	cpy = arg;
	if (*cpy == ' ')
		return (1);
	while (*cpy)
	{
		atoi_errors(&cpy, DEC, &err);
		if (err)
		{
			print_color("Error\n", 's', RED, PRINT_OUT);
			return (1);
		}
		if (multiple_spaces(&cpy))
			return (1);
	}
	return (0);
}

int	parse_args(t_cchar **args, t_cint nb)
{
	int		index;

	index = 0;
	while (index < nb)
	{
		if (parse_arg(*(args + index)))
			return (1);
		index ++;
	}
	return (0);
}
