/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 17:57:55 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/24 19:13:22 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		drawdot(t_point pt, t_fdf *params)
{
	if (pt.x >= 0 && pt.x <= params->resolution[0] &&
	pt.y >= 0 && pt.y <= params->resolution[1])
		mlx_pixel_put(params->mlx_ptr, params->win_ptr,
		pt.x, pt.y, params->colour);
}

static void	drawline_high(t_point point1, t_point point2, t_fdf *params)
{
	int		dx;
	int		dy;
	int		p;
	int		xi;

	dx = (point2.x) - (point1.x);
	dy = (point2.y) - (point1.y);
	xi = 1;
	if (dx < 0)
	{
		xi = -1;
		dx = -dx;
	}
	p = 2 * dx - dy;
	while (point1.y != point2.y)
	{
		drawdot(point1, params);
		point1.y++;
		if (p > 0)
		{
			point1.x += xi;
			p = p - (2 * dy);
		}
		p = p + (2 * dx);
	}
}

static void	drawline_low(t_point point1, t_point point2, t_fdf *params)
{
	int yi;
	int dx;
	int dy;
	int	p;

	yi = 1;
	dx = (point2.x) - (point1.x);
	dy = (point2.y) - (point1.y);
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	p = (2 * dy) - dx;
	while (point1.x != point2.x)
	{
		drawdot(point1, params);
		point1.x++;
		if (p > 0)
		{
			point1.y += yi;
			p = p - (2 * dx);
		}
		p = p + (2 * dy);
	}
}

static void	drawline(t_point point1, t_point point2, t_fdf *params)
{
	offset(&point1, params);
	offset(&point2, params);
	rotate(&point1, params);
	rotate(&point2, params);
	offset2(&point1, params);
	offset2(&point2, params);
	if (abs(point2.y - point1.y) < abs(point2.x - point1.x))
	{
		if (point1.x > point2.x)
			drawline_low(point2, point1, params);
		else
			drawline_low(point1, point2, params);
	}
	else
	{
		if (point1.y > point2.y)
			drawline_high(point2, point1, params);
		else
			drawline_high(point1, point2, params);
	}
}

void		put_map(t_fdf *params)
{
	t_point	point1;
	t_point	point2;

	point1.y = 0;
	while (point1.y < (params->y * params->scale))
	{
		point1.x = 0;
		while (point1.x < (params->x * params->scale))
		{
			point2.x = point1.x + params->scale;
			point2.y = point1.y;
			find_z(&point1, &point2, params);
			if (point1.x < ((params->x * params->scale) - params->scale))
				drawline(point1, point2, params);
			if (point1.y < ((params->y * params->scale) - params->scale))
			{
				point2.x = point1.x;
				point2.y = point1.y + params->scale;
				find_z(&point1, &point2, params);
				drawline(point1, point2, params);
			}
			point1.x += params->scale;
		}
		point1.y += params->scale;
	}
}
