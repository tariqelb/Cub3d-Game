/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 08:15:01 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/04 13:00:40 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_isnt_a_wall(t_cub3d *cub, char c)
{
	if (cub->p_ort == 0)
	{
		if (ft_check_up_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 100)
	{
		if (ft_check_right_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 200)
	{
		if (ft_check_down_side_and_update(&cub[0], c))
			return (1);
	}
	else if (cub->p_ort == 300)
	{
		if (ft_check_left_side_and_update(&cub[0], c))
			return (1);
	}
	return (0);
}

void	ft_calculate_and_move_to_pos_two(t_cub3d **cub, char c)
{
	int		sides_angle;
	double	opp;
	double	adj;

	adj = 0;
	opp = 0;
	if (c == 'l')
		sides_angle = cub[0]->p_ort - 100;
	else
		sides_angle = cub[0]->p_ort + 100;
	if (sides_angle >= 400 )
		sides_angle -= 400;
	else if (sides_angle < 0)
		sides_angle += 400;
	if ((sides_angle == 0) || (sides_angle == 100)
			|| (sides_angle == 200) || (sides_angle == 300)) 
		ft_simple_pos_calc_sides(cub, c, sides_angle);
	else
	{
		adj = ft_calc_opp0_or_adj1(sides_angle, 1);
		opp = ft_calc_opp0_or_adj1(sides_angle, 0);
		if (ft_there_is_a_wall_sides(cub, adj, opp, sides_angle))
				ft_new_position_forward_sides(cub, adj, opp, sides_angle);
	}
}

void	ft_calculate_and_move_to_pos(t_cub3d **cub, char c)
{
	double	opp;
	double	adj;

	adj = 0;
	opp = 0;
	if (c == 'l' || c == 'r')
		ft_calculate_and_move_to_pos_two(cub, c);
	else if ((cub[0]->p_ort == 0) || (cub[0]->p_ort == 100)
			|| (cub[0]->p_ort == 200) || (cub[0]->p_ort == 300))
		ft_simple_pos_calc(cub, c);
	else
	{
		adj = ft_calc_opp0_or_adj1(cub[0]->p_ort, 1);
		opp = ft_calc_opp0_or_adj1(cub[0]->p_ort, 0);
		if (ft_there_is_a_wall(cub, adj, opp, c))
		{
			if (c == 'u')
				ft_new_position_forward(cub, adj, opp);
			else
				ft_new_position_backward(cub, adj, opp);
		}
	}
}

void	ft_move_player(t_cub3d **cub, char c)
{
	if (c == '<')
	{
		cub[0]->p_ort -= 10;
		if (cub[0]->p_ort < 0)
			cub[0]->p_ort += 400;
	}
	if (c == '>')
	{
		cub[0]->p_ort += 10;
		if (cub[0]->p_ort >= 400)
			cub[0]->p_ort -= 400;
	}
	if (c == 'd')
		ft_calculate_and_move_to_pos(cub, c);
	if (c == 'u')
		ft_calculate_and_move_to_pos(cub, c);
	if (c == 'l')
		ft_calculate_and_move_to_pos(cub, c);
	if (c == 'r')
		ft_calculate_and_move_to_pos(cub, c);
}
