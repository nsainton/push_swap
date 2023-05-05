/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enums.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsainton <nsainton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 03:52:54 by nsainton          #+#    #+#             */
/*   Updated: 2023/03/09 11:27:40 by nsainton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUMS_H
# define ENUMS_H

typedef enum e_operation
{
	PUSH = 1 << 0,
	SWAP = 1 << 1,
	ROTATE = 1 << 2,
	RROTATE = 1 << 3,
	SORTED = 1 << 4,
}			t_operation;

typedef enum e_direction
{
	UU = 1,
	UD,
	DU,
	DD,
}			t_direction;

#endif
