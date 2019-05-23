/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 17:51:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/23 18:41:56 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		count_lines(char *str)
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

void	free_all(char **ptr)
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

void	create_map(int fd, t_fdf *params)
{
	char	str[3000000];
	int		y;
	int		x;
	int		chars_read;
	char	**temp;

	y = 0;
	chars_read = read(fd, str, 3000000);
	str[chars_read] = '\0';
	params->y = count_lines(str);
	params->x = ft_strcount(str, ' ') / params->y;
	temp = ft_strsplit((const char*)str, ' ');
	params->map = (int**)malloc(sizeof(int*) * params->y);
	while (y < params->y)
	{
		x = 0;
		params->map[y] = (int*)malloc(sizeof(int) * params->x);
		while (x < params->x)
		{
			params->map[y][x] = ft_atoi((temp)[(y * params->x) - y + x]);
			x++;
		}
		y++;
	}
	free_all(temp);
}

void	set_params(t_fdf *params)
{
	float	aspect;
	
	params->height = 2;
	params->x_angle = 3.66519143;
	params->y_angle = 3.66519143;
	params->z_angle = 3.75919143;
	params->scale = 100000 / (params->x * 90);
	aspect = (float)params->x / (float)params->y;
	params->resolution[0] = 1000 * aspect;
	params->resolution[1] = 1000;
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr,
		params->resolution[0], params->resolution[1], "fdf");
}

int		main(int argc, char **argv)
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
		mlx_hook(params->win_ptr, 2, 0, deal_key, params);
		mlx_loop(params->mlx_ptr);
	}
	return (0);
}
