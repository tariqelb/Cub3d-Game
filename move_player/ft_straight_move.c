/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straight_move.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:11:44 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:27:05 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_forward_position_calc(t_cub3d *cub, char c)
{
	if (c == 'u' && cub->p_ort == 0)
		return (cub->p_pos[1] - STEP);
	else if (c == 'u' && cub->p_ort == 100)
		return (cub->p_pos[0] + STEP);
	else if (c == 'u' && cub->p_ort == 200)
		return (cub->p_pos[1] + STEP);
	else if (c == 'u' && cub->p_ort == 300)
		return (cub->p_pos[0] - STEP);
	else if (c == 'u' && cub->p_ort == 400)
		return (cub->p_pos[1] - STEP);
	else if (c == 'd' && cub->p_ort == 0)
		return (cub->p_pos[1] + STEP);
	else if (c == 'd' && cub->p_ort == 100)
		return (cub->p_pos[0] - STEP);
	else if (c == 'd' && cub->p_ort == 200)
		return (cub->p_pos[1] - STEP);
	else if (c == 'd' && cub->p_ort == 300)
		return (cub->p_pos[0] + STEP);
	else if (c == 'd' && cub->p_ort == 400)
		return (cub->p_pos[1] + STEP);
	return (0);
}

int	ft_check_new_pos_backward(t_cub3d *cub, char c)
{
	double	w_range_min;
	double	w_range_max;
	double	h_range_min;
	double	h_range_max;
	double	next_pos;

	next_pos = ft_forward_position_calc(cub, c);
	w_range_max = cub->cell_w_h[0] * (cub->p_j + 1);
	w_range_min = cub->cell_w_h[0] * (cub->p_j);
	h_range_max = cub->cell_w_h[1] * (cub->p_i + 1);
	h_range_min = cub->cell_w_h[1] * (cub->p_i);
	if (cub->p_ort == 100 && next_pos > w_range_min)
		return (1);
	else if (cub->p_ort == 300 && next_pos < w_range_max)
		return (1);
	else if (cub->p_ort == 0 && next_pos < h_range_max)
		return (1);
	else if (cub->p_ort == 200 && next_pos > h_range_min)
		return (1);
	else if (ft_isnt_a_wall(cub, c))
		return (1);
	return (0);
}

int	ft_check_new_pos_forward(t_cub3d *cub, char c)
{
	double	w_range_min;
	double	w_range_max;
	double	h_range_min;
	double	h_range_max;
	double	next_pos;

	if (c == 'd')
		return (ft_check_new_pos_backward(&cub[0], c));
	next_pos = ft_forward_position_calc(cub, c);
	w_range_max = cub->cell_w_h[0] * (cub->p_j + 1);
	w_range_min = cub->cell_w_h[0] * (cub->p_j);
	h_range_max = cub->cell_w_h[1] * (cub->p_i + 1);
	h_range_min = cub->cell_w_h[1] * (cub->p_i);
	if (cub->p_ort == 100 && next_pos < w_range_max)
		return (1);
	else if (cub->p_ort == 300 && next_pos > w_range_min)
		return (1);
	else if (cub->p_ort == 0 && next_pos > h_range_min)
		return (1);
	else if (cub->p_ort == 200 && next_pos < h_range_max)
		return (1);
	else if (ft_isnt_a_wall(cub, c))
		return (1);
	return (0);
}
