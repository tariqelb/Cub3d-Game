/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle_calculation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:38:09 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:38:15 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_calc_hypotenus(double angle, double adj)
{
	double	hyp;

	if (angle >= 300)
		angle -= 300;
	else if (angle >= 200)
		angle -= 200;
	else if (angle >= 100)
		angle -= 100;
	hyp = adj / cos(angle * (3.14159 / 200));
	return (hyp);
}

double	ft_calc_opposite(double angle, double hyp)
{
	double	opp;

	if (angle >= 300)
		angle -= 300;
	else if (angle >= 200)
		angle -= 200;
	else if (angle >= 100)
		angle -= 100;
	opp = hyp * sin(angle * (3.14159 / 200));
	return (opp);
}

double	ft_calc_adjacent(double angle, double hyp)
{
	double	adj;

	if (angle >= 300)
		angle -= 300;
	else if (angle >= 200)
		angle -= 200;
	else if (angle >= 100)
		angle -= 100;
	adj = hyp * cos(angle * (3.14159 / 200));
	return (adj);
}

void	ft_real_distance(t_cub3d **cub, int turn, double hyp)
{
	double	angle;
	double	real_dis;

	if ((double) cub[0]->p_ort > cub[0]->angle)
		angle = (double) cub[0]->p_ort - cub[0]->angle;
	else if ((double) cub[0]->p_ort < cub[0]->angle)
		angle = cub[0]->angle - (double) cub[0]->p_ort;
	else
		angle = 0;
	real_dis = hyp * cos(angle * (3.14 / 200));
	cub[0]->ray_height[turn][2] = (50 * HEIGHT) / real_dis;
}
