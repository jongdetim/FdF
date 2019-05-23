/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 20:28:45 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/23 21:29:56 by tide-jon      ########   odam.nl         */
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
	pt->x += params->resolution[0] / 2;
	pt->y += params->resolution[1] / 2;
}

void		find_z(t_point *pt1, t_point *pt2, t_fdf *params)
{
	pt1->z = params->map[(pt1->y / params->scale)][(pt1->x / params->scale)]
		* (params->height * params->scale) / 20;
	pt2->z = params->map[(pt2->y / params->scale)][(pt2->x / params->scale)]
		* (params->height * params->scale) / 20;
}
