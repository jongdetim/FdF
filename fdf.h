/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 21:06:49 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/23 20:45:07 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	int				scale;
	int				**map;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				height;
	int				resolution[2];
}					t_fdf;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

void				put_map(t_fdf *params);
int					deal_key(int key, t_fdf *params);
void				rotate(t_point *point, t_fdf *params);
void				offset(t_point *pt, t_fdf *params);
void				offset2(t_point *pt, t_fdf *params);
void				find_z(t_point *pt1, t_point *pt2, t_fdf *params);

#endif
