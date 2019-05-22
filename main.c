/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/15 17:51:03 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/22 18:14:31 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	x_rot(t_point *point, t_fdf *params)
{
	int z_new;
	int y_new;

	z_new = -point->x * sin(params->x_angle) + point->z * cos(params->x_angle);
	y_new = point->y * cos(params->x_angle) + point->z * sin(params->x_angle);
	point->z = z_new;
	point->y = y_new;
}

void	y_rot(t_point *point, t_fdf *params)
{
	int x_new;
	int z_new;

	x_new = point->x * cos(params->y_angle) + point->z * sin(params->y_angle);
	z_new = -point->x * sin(params->y_angle) + point->z * cos(params->y_angle);
	point->x = x_new;
	point->z = z_new;
}

void	z_rot(t_point *point, t_fdf *params)
{
	int x_new;
	int y_new;

	x_new = point->x * cos(params->z_angle) - point->y * sin(params->z_angle);
	y_new = point->x * sin(params->z_angle) + point->y * cos(params->z_angle);
	point->x = x_new;
	point->y = y_new;
}

void	rotate(t_point *point, t_fdf *params)
{
	x_rot(point, params);
	y_rot(point, params);
	z_rot(point, params);
}

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
			params->map[y][x] = ft_atoi((const char*)(temp)[(y * params->x) - y + x]);
			printf("%i ", params->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	free_all(temp);
}

// deze functie kan alleen dealen met lijnen met een helling van > 1 en < -1
void	drawline_high(t_point point1, t_point point2, t_fdf *params)
{
	int 	dx;
	int 	dy;
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
		mlx_pixel_put(params->mlx_ptr, params->win_ptr, point1.x, point1.y, 0xFFFFFF);
		point1.y++;
		if (p > 0)
		{
			point1.x += xi;
			p = p - (2 * dy);
		}
		p = p + (2 * dx);
	}
}

// deze functie kan alleen dealen met lijnen met een helling tussen 1 en -1;
void	drawline_low(t_point point1, t_point point2, t_fdf *params)
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
		mlx_pixel_put(params->mlx_ptr, params->win_ptr, point1.x, point1.y, 0xFFFFFF);
		point1.x++;
		if (p > 0)
		{
			point1.y += yi;
			p = p - (2 * dx);
		}
		p = p + (2 * dy);
	}
}

void	drawline(t_point point1, t_point point2, t_fdf *params)
{
	rotate(&point1, params);
	rotate(&point2, params);
	if (abs(point2.y - point1.y) < abs(point2.x - point1.x))
	{
		if (point1.x > point2.x)
		{
			drawline_low(point2, point1, params); 
//			printf("1");
		}
		else
		{
			drawline_low(point1, point2, params);
//			printf("2");
		}
	}
	else
	{
		if (point1.y > point2.y)
		{
			drawline_high(point2, point1, params);
//			printf("3");
		}
		else
		{
			drawline_high(point1, point2, params);
//			printf("4");
		}
	}
}

void	put_map(t_fdf *params)
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
//			printf("%i\n%i\n\n", params->map[(point1.y / params->scale)][(point1.x / params->scale)], params->map[(point2.y / params->scale)][(point2.x / params->scale)]);
			point1.z = params->map[(point1.y / params->scale)][(point1.x / params->scale)] * params->height;
			point2.z = params->map[(point2.y / params->scale)][(point2.x / params->scale)] * params->height;
			if (point1.x < ((params->x * params->scale) - params->scale))
				drawline(point1, point2, params);
			if (point1.y < ((params->y * params->scale) - params->scale))
			{
				point2.x = point1.x;
				point2.y = point1.y + params->scale;
				point1.z = params->map[(point1.y / params->scale)][(point1.x / params->scale)] * params->height;
				point2.z = params->map[(point2.y / params->scale)][(point2.x / params->scale)] * params->height;
				drawline(point1, point2, params);
			}
//			printf("%i\n%i\n%i\n%i\n\n", point1.x, point1.y, point2.x, point2.y);
			point1.x += params->scale;
		}
		point1.y += params->scale;
	}
}

int		deal_key(int key, t_fdf *params)
{
	if (key == 53)
	{
		exit(0);
	}
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
	if (key == 124)
	{
		params->z_angle += 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 123)
	{
		params->z_angle -= 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 126)
	{
		params->x_angle += 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 125)
	{
		params->x_angle -= 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 6)
	{
		params->y_angle += 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
	if (key == 7)
	{
		params->y_angle -= 0.0174532925;
		mlx_clear_window(params->mlx_ptr, params->win_ptr);
		put_map(params);
	}
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
	return (0);
}

int		main(int argc, char **argv)
{
	t_fdf	*params;
	int		fd;
//	t_point	point1;
//	t_point	point2;

//	point1.x = 50;
//	point1.y = 100;
//	point1.z = 0;
//	point2.x = 100;
//	point2.y = 110;
//	point2.z = 0;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		params = (t_fdf*)malloc(sizeof(t_fdf));
		create_map(fd, params);
		params->height = 1;
		params->scale = (10000 / (params->x * params->y));
		params->x_angle = 0;
		params->y_angle = 0;
		params->z_angle = 0;
		params->aspect = params->x / params->y;
		params->mlx_ptr = mlx_init();
		params->win_ptr = mlx_new_window(params->mlx_ptr, 2000, 1000, "fdf");
		put_map(params);
		mlx_hook(params->win_ptr, 2, 0, deal_key, params);
//		drawline(point1, point2, params);
		mlx_loop(params->mlx_ptr);
	}
	return (0);
}
