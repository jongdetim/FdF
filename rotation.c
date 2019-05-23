/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotation.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 17:51:04 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/23 17:51:40 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	x_rot(t_point *point, t_fdf *params)
{
	int z_new;
	int y_new;

	z_new = point->y * sin(params->x_angle) + point->z * cos(params->x_angle);
	y_new = point->y * cos(params->x_angle) - point->z * sin(params->x_angle);
	point->z = z_new;
	point->y = y_new;
}

static void	y_rot(t_point *point, t_fdf *params)
{
	int x_new;
	int z_new;

	x_new = point->x * cos(params->y_angle) + point->z * sin(params->y_angle);
	z_new = -point->x * sin(params->y_angle) + point->z * cos(params->y_angle);
	point->x = x_new;
	point->z = z_new;
}

static void	z_rot(t_point *point, t_fdf *params)
{
	int x_new;
	int y_new;

	x_new = point->x * cos(params->z_angle) - point->y * sin(params->z_angle);
	y_new = point->x * sin(params->z_angle) + point->y * cos(params->z_angle);
	point->x = x_new;
	point->y = y_new;
}

void		rotate(t_point *point, t_fdf *params)
{
	x_rot(point, params);
	y_rot(point, params);
	z_rot(point, params);
}
