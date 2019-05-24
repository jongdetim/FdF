/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_commands.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 17:52:37 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/24 19:12:14 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	deal_key2(int key, t_fdf *params)
{
	if (key == 124)
		params->z_angle += 2 * 0.0174532925;
	if (key == 123)
		params->z_angle -= 2 * 0.0174532925;
	if (key == 126)
		params->x_angle += 2 * 0.0174532925;
	if (key == 125)
		params->x_angle -= 2 * 0.0174532925;
	if (key == 34)
	{
		params->x_angle = 3.66519143;
		params->y_angle = 3.66519143;
		params->z_angle = 3.75919143;
	}
	if (key == 6)
		params->y_angle += 2 * 0.0174532925;
}

static void	deal_key3(int key, t_fdf *params)
{
	if (key == 27)
		params->height -= 1;
	if (key == 24)
		params->height += 1;
	if (key == 49)
	{
		params->x_angle = 0;
		params->y_angle = 0;
		params->z_angle = 0;
	}
	if (key == 13)
		params->offset_y -= 10;
	if (key == 1)
		params->offset_y += 10;
	if (key == 0)
		params->offset_x -= 10;
	if (key == 2)
		params->offset_x += 10;
}

int			deal_key(int key, t_fdf *params)
{
	if (key == 53)
		exit(0);
	if (key == 69)
		params->scale += 1;
	if (key == 78 && params->scale > 1)
		params->scale -= 1;
	if (key == 7)
		params->y_angle -= 2 * 0.0174532925;
	deal_key2(key, params);
	deal_key3(key, params);
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	put_map(params);
	put_legend(params);
	return (0);
}

int			deal_mouse(int button, int x, int y, t_fdf *params)
{
	(void)x;
	(void)y;
	printf("%i\n", params->colour);
	if (button == 4 && params->colour < 0xFFFFFF - 123456)
		params->colour += 123456;
	if (button == 5 && params->colour > 123456)
		params->colour -= 123456;
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	put_map(params);
	put_legend(params);
	return (0);
}
