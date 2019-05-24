/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   offset.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/24 18:29:12 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/24 18:29:35 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		offset(t_point *pt, t_fdf *params)
{
	pt->x -= (((params->x - 1) * params->scale + 1) / 2);
	pt->y -= (((params->y - 1) * params->scale + 1) / 2);
}

void		offset2(t_point *pt, t_fdf *params)
{
	pt->x += (params->resolution[0] / 2) + params->offset_x;
	pt->y += (params->resolution[1] / 2) + params->offset_y;
}
