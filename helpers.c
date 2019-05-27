/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/23 20:28:45 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/27 14:53:56 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_legend(t_fdf *params)
{
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 50, 0xFFFFFF, "Zoom              +  -");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 70, 0xFFFFFF, "Height            =  -");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 90, 0xFFFFFF, "Rotate            <  >  ^  v  Z  X");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 110, 0xFFFFFF, "Panning           W A S D");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 130, 0xFFFFFF, "Topview           space");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 150, 0xFFFFFF, "Isometric view    i");
	mlx_string_put(params->mlx_ptr, params->win_ptr,
	50, 170, 0xFFFFFF, "Change colour     scroll wheel");
}

void		find_z(t_point *pt1, t_point *pt2, t_fdf *params)
{
	pt1->z = params->map[(pt1->y / params->scale)][(pt1->x / params->scale)]
		* (params->height * params->scale) / 20;
	pt2->z = params->map[(pt2->y / params->scale)][(pt2->x / params->scale)]
		* (params->height * params->scale) / 20;
}

int			count_lines(char *str)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	return (y);
}

void		free_all(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
