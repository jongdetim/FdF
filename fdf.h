/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fdf.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/13 21:06:49 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/22 17:53:34 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				x;
	int				y;
	int				x1;
	int				y1;
	int				scale;
	int				**map;
	double			aspect;
	double			x_angle;
	double			y_angle;
	double			z_angle;
	int				height;
}					t_fdf;

typedef struct 		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

// function prototypes //

#endif