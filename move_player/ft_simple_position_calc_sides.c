/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_position_calc_sides.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 23:21:57 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:24:48 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isnt_a_wall_sides(t_cub3d *cub, int sides_angle)
{
	if (sides_angle == 0)
	{
		if (ft_check_up_and_update(&cub[0]))
			return (1);
	}
	else if (sides_angle == 100)
	{
		if (ft_check_right_and_update(&cub[0]))
			return (1);
	}
	else if (sides_angle == 200)
	{
		if (ft_check_down_and_update(&cub[0]))
			return (1);
	}
	else if (sides_angle == 300)
	{
		if (ft_check_left_and_update(&cub[0]))
			return (1);
	}
	return (0);
}

int	ft_sides_position_calc(t_cub3d *cub, char c, int sides_angle)
{
	(void)c;
	if (sides_angle == 0)
		return (cub->p_pos[1] - STEP);
	else if (sides_angle == 100)
		return (cub->p_pos[0] + STEP);
	else if (sides_angle == 200)
		return (cub->p_pos[1] + STEP);
	else if (sides_angle == 300)
		return (cub->p_pos[0] - STEP);
	else if (sides_angle == 400)
		return (cub->p_pos[1] - STEP);
	return (0);
}

int	ft_check_new_pos_sides(t_cub3d *cub, char c, int sides_angle)
{
	double	w_range_min;
	double	w_range_max;
	double	h_range_min;
	double	h_range_max;
	double	next_pos;

	next_pos = ft_sides_position_calc(cub, c, sides_angle);
	w_range_max = cub->cell_w_h[0] * (cub->p_j + 1);
	w_range_min = cub->cell_w_h[0] * (cub->p_j);
	h_range_max = cub->cell_w_h[1] * (cub->p_i + 1);
	h_range_min = cub->cell_w_h[1] * (cub->p_i);
	if (sides_angle == 100 && next_pos < w_range_max)
		return (1);
	else if (sides_angle == 300 && next_pos > w_range_min)
		return (1);
	else if (sides_angle == 0 && next_pos > h_range_min)
		return (1);
	else if (sides_angle == 200 && next_pos < h_range_max)
		return (1);
	else if (ft_isnt_a_wall_sides(cub, sides_angle))
		return (1);
	return (0);
}

void	ft_simple_pos_calc_sides(t_cub3d **cub, char c, int sides_angle)
{
	(void)c;
	if (ft_check_new_pos_sides(cub[0], c, sides_angle))
	{
		if (sides_angle == 0)
			cub[0]->p_pos[1] -= STEP;
		else if (sides_angle == 100)
			cub[0]->p_pos[0] += STEP;
		else if (sides_angle == 200)
			cub[0]->p_pos[1] += STEP;
		else if (sides_angle == 300)
			cub[0]->p_pos[0] -= STEP;
		else if (sides_angle == 400)
			cub[0]->p_pos[1] -= STEP;
	}
}
