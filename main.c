/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 17:51:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/24 19:06:36 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	remove_colour(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			while (str[i] != '\0')
			{
				str[i] = '\0';
				i++;
			}
			i--;
		}
		i++;
	}
}

static void	convert_map(t_fdf *params, char **temp)
{
	int x;
	int y;

	y = 0;
	while (y < params->y)
	{
		x = 0;
		params->map[y] = (int*)malloc(sizeof(int) * params->x);
		while (x < params->x)
		{
			remove_colour(temp[(y * params->x) - y + x]);
			params->map[y][x] = ft_atoi((temp)[(y * params->x) - y + x]);
			x++;
		}
		y++;
	}
}

static void	create_map(int fd, t_fdf *params)
{
	char	str[3000000];
	int		chars_read;
	char	**temp;

	chars_read = read(fd, str, 3000000);
	str[chars_read] = '\0';
	params->y = count_lines(str);
	params->x = ft_strcount(str, ' ') / params->y;
	temp = ft_strsplit((const char*)str, ' ');
	params->map = (int**)malloc(sizeof(int*) * params->y);
	convert_map(params, temp);
	free_all(temp);
}

static void	set_params(t_fdf *params)
{
	float	aspect;

	params->x_angle = 3.66519143;
	params->y_angle = 3.66519143;
	params->z_angle = 3.75919143;
	params->scale = 100000 / (params->x * 90);
	params->height = 3;
	aspect = (float)params->x / (float)params->y;
	params->resolution[0] = 1000 * aspect;
	params->resolution[1] = 1000;
	params->offset_x = 0;
	params->offset_y = 0;
	params->colour = 0xDD55DD;
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr,
		params->resolution[0], params->resolution[1], "fdf");
}

int			main(int argc, char **argv)
{
	t_fdf	*params;
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		params = (t_fdf*)malloc(sizeof(t_fdf));
		create_map(fd, params);
		set_params(params);
		put_map(params);
		put_legend(params);
		mlx_hook(params->win_ptr, 2, 0, deal_key, params);
		mlx_hook(params->win_ptr, 4, 0, deal_mouse, params);
		mlx_loop(params->mlx_ptr);
	}
	return (0);
}
