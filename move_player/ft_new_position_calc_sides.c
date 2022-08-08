/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_position_calc_sides.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:58:09 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:23:07 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_n_pos_f_side(t_cub3d **cub, double adj, double opp, int sides_angle)
{
	if (sides_angle > 0 && sides_angle < 100)
	{
		cub[0]->p_pos[1] -= adj;
		cub[0]->p_pos[0] += opp;
	}
	if (sides_angle > 100 && sides_angle < 200)
	{
		cub[0]->p_pos[1] += opp;
		cub[0]->p_pos[0] += adj;
	}
	if (sides_angle > 200 && sides_angle < 300)
	{
		cub[0]->p_pos[1] += adj;
		cub[0]->p_pos[0] -= opp;
	}
	if (sides_angle > 300 && sides_angle < 400)
	{
		cub[0]->p_pos[1] -= opp;
		cub[0]->p_pos[0] -= adj;
	}
}

void	ft_n_pos_b_side(t_cub3d **cub, double adj, double opp, int sides_angle)
{
	if (sides_angle > 0 && cub[0]->p_ort < 100)
	{
		cub[0]->p_pos[1] += adj;
		cub[0]->p_pos[0] -= opp;
	}
	if (sides_angle > 100 && cub[0]->p_ort < 200)
	{
		cub[0]->p_pos[1] -= opp;
		cub[0]->p_pos[0] -= adj;
	}
	if (sides_angle > 200 && cub[0]->p_ort < 300)
	{
		cub[0]->p_pos[1] -= adj;
		cub[0]->p_pos[0] += opp;
	}
	if (sides_angle > 300 && cub[0]->p_ort < 400)
	{
		cub[0]->p_pos[1] += opp;
		cub[0]->p_pos[0] += adj;
	}
}
