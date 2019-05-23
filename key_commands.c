/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_commands.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 17:52:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/23 21:28:01 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	deal_key4(int key, t_fdf *params)
{
	if (key == 34)
	{
		params->x_angle = 3.66519143;
		params->y_angle = 3.66519143;
		params->z_angle = 3.75919143;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 6)
	{
		params->y_angle += 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
}

static void	deal_key2(int key, t_fdf *params)
{
	if (key == 124)
	{
		params->z_angle += 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 123)
	{
		params->z_angle -= 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 126)
	{
		params->x_angle += 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 125)
	{
		params->x_angle -= 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
}

static void	deal_key3(int key, t_fdf *params)
{
	if (key == 27)
	{
		params->height -= 1;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 24)
	{
		params->height += 1;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 49)
	{
		params->x_angle = 0;
		params->y_angle = 0;
		params->z_angle = 0;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
}

int			deal_key(int key, t_fdf *params)
{
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		params->scale += 1;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 78 && params->scale > 1)
	{
		params->scale -= 1;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 7)
	{
		params->y_angle -= 2 * 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	deal_key2(key, params);
	deal_key3(key, params);
	deal_key4(key, params);
	return (0);
}
