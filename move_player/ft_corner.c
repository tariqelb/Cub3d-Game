/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corner.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:27:28 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 11:51:28 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_left_under(t_cub3d **cub, int i, int j)
{
	int l;
	int w;

	w = 0;
	l = 0;
	while (cub[0]->map[i][l] && l < j - 1)
		l++;
	if (cub[0]->map[i][l] == '1')
		w++;
	l = 0;
	while (cub[0]->map[i + 1][l] && l < j)
		l++;
	if (cub[0]->map[i + 1][l] == '1')
		w++;
	if (w == 2)
		return (1);
	return (0);
}

int	ft_left_above(t_cub3d **cub, int i, int j)
{
	int l;
	int w;

	w = 0;
	l = 0;
	while (cub[0]->map[i][l] && l < j - 1)
		l++;
	if (cub[0]->map[i][l] == '1')
		w++;
	l = 0;
	while (cub[0]->map[i - 1][l] && l < j)
		l++;
	if (cub[0]->map[i - 1][l] == '1')
		w++;
	if (w == 2)
		return (1);
	return (0);
}

int	ft_right_above(t_cub3d **cub, int i, int j)
{
	int l;
	int w;

	w = 0;
	l = 0;
	while (cub[0]->map[i][l] && l < j + 1)
		l++;
	if (cub[0]->map[i][l] == '1')
		w++;
	l = 0;
	while (cub[0]->map[i - 1][l] && l < j)
		l++;
	if (cub[0]->map[i - 1][l] == '1')
		w++;
	if (w == 2)
		return (1);
	return (0);
}

int	ft_right_under(t_cub3d **cub, int i, int j)
{
	int l;
	int w;

	w = 0;
	l = 0;
	while (cub[0]->map[i][l] && l < j + 1)
		l++;
	if (cub[0]->map[i][l] == '1')
		w++;
	l = 0;
	while (cub[0]->map[i + 1][l] && l < j)
		l++;
	if (cub[0]->map[i + 1][l] == '1')
		w++;
	if (w == 2)
		return (1);
	return (0);
}

int	ft_corner(t_cub3d **cub, int angle, int i, int j)
{
	int	u;
	int	d;
	int	l;
	int	r;

	if (angle > 0 && angle < 100)
	{
		return (ft_left_under(cub, i, j));
	}
	else if (angle > 100 && angle < 200)
	{
		return (ft_left_above(cub, i, j));
	}
	else if (angle > 200 && angle < 300)
	{
		return (ft_right_above(cub, i, j));
	}
	else if (angle > 300 && angle < 400)
	{
		return (ft_right_under(cub, i, j));
	}
	return (0);
}
