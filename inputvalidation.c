/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   inputvalidation.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tide-jon <tide-jon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/27 16:17:08 by tide-jon       #+#    #+#                */
/*   Updated: 2019/05/27 17:21:33 by tide-jon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	checkrows(char str[], int width)
{
	int	check;
	int i;

	check = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\n' && str[i] != '\0')
		{
			if (str[i] != ' ')
			{
				while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
					i++;
				check++;
				i--;
			}
			i++;
		}
		if (check != width)
			return (0);
		check = 0;
		if (str[i] != '\0')
			i++;
	}
	return (1);
}

static int	checkwidth(char str[])
{
	int	width;
	int	i;

	width = 0;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			while (str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
				i++;
			width++;
			i--;
		}
		i++;
	}
	if (checkrows(str, width) == 1)
		return (1);
	else
		return (0);
}

int			inputvalidation(char str[])
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else if (str[i] == ' ' || str[i] == '\n')
			i++;
		else if (str[i] == ',' && str[i - 1] >= '0' && str[i - 1] <= '9')
		{
			while (str[i] != '\n' && str[i] != ' ' && str[i] != '\0')
				i++;
		}
		else
			return (0);
	}
	if (checkwidth(str) == 1)
		return (1);
	else
		return (0);
}
