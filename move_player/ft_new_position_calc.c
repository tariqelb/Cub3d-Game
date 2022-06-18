/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_position_calc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:01:25 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/17 18:04:44 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_calc_opp0_or_adj1(int angle, int flag)
{
	double	adj;
	double	opp;

	if (flag == 1)
	{
		if (angle > 300)
			angle -= 300;
		if (angle > 200)
			angle -= 200;
		else if (angle > 100)
			angle -= 100;
		adj = (double) STEP * cos((angle * (3.14159 / 200)));
		return (adj);
	}
	else
	{
		if (angle > 300)
			angle -= 300;
		if (angle > 200)
			angle -= 200;
		else if (angle > 100)
			angle -= 100;
		opp = (double) STEP * sin((angle * (3.14159 / 200)));
		return (opp);
	}
}

void	ft_new_position_forward(t_cub3d **cub, double adj, double opp)
{
	if (cub[0]->p_ort > 0 && cub[0]->p_ort < 100)
	{
		cub[0]->p_pos[1] -= adj;
		cub[0]->p_pos[0] += opp;
	}
	if (cub[0]->p_ort > 100 && cub[0]->p_ort < 200)
	{
		cub[0]->p_pos[1] += opp;
		cub[0]->p_pos[0] += adj;
	}
	if (cub[0]->p_ort > 200 && cub[0]->p_ort < 300)
	{
		cub[0]->p_pos[1] += adj;
		cub[0]->p_pos[0] -= opp;
	}
	if (cub[0]->p_ort > 300 && cub[0]->p_ort < 400)
	{
		cub[0]->p_pos[1] -= opp;
		cub[0]->p_pos[0] -= adj;
	}
}

void	ft_new_position_backward(t_cub3d **cub, double adj, double opp)
{
	if (cub[0]->p_ort > 0 && cub[0]->p_ort < 100)
	{
		cub[0]->p_pos[1] += adj;
		cub[0]->p_pos[0] -= opp;
	}
	if (cub[0]->p_ort > 100 && cub[0]->p_ort < 200)
	{
		cub[0]->p_pos[1] -= opp;
		cub[0]->p_pos[0] -= adj;
	}
	if (cub[0]->p_ort > 200 && cub[0]->p_ort < 300)
	{
		cub[0]->p_pos[1] -= adj;
		cub[0]->p_pos[0] += opp;
	}
	if (cub[0]->p_ort > 300 && cub[0]->p_ort < 400)
	{
		cub[0]->p_pos[1] += opp;
		cub[0]->p_pos[0] += adj;
	}
}
