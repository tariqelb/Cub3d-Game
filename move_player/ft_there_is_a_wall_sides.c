/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_there_is_a_wall_sides.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:06:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/08 16:34:37 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_vir_pos_sides(t_cub3d **cub, double adj, double opp, int sides_angle)
{
	if (sides_angle > 0 && sides_angle < 100)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + opp;
	}
	if (sides_angle > 100 && sides_angle < 200)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + adj;
	}
	if (sides_angle > 200 && sides_angle < 300)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - opp;
	}
	if (sides_angle > 300 && sides_angle < 400)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - adj;
	}
}

void	ft_move_player_pos_sides(t_cub3d **cub, int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (cub[0]->map[x])
	{
		y = 0;
		while (cub[0]->map[x][y])
		{
			if (cub[0]->map[x][y] == cub[0]->xyz[2])
			{
				cub[0]->map[x][y] = '0';
				break ;
			}
			y++;
		}
		x++;
	}
	cub[0]->map[i][j] = cub[0]->xyz[2];
	cub[0]->p_i = i;
	cub[0]->p_j = j;
}

int	ft_there_is_a_wall_sides(t_cub3d **cub, double adj, double opp, int s)
{
	int	i;
	int	j;
	int	k;

	ft_vir_pos_sides(cub, adj, opp, s);
	j = cub[0]->vir_pos[0] / cub[0]->cell_w_h[0];
	i = cub[0]->vir_pos[1] / cub[0]->cell_w_h[1];
	k = 0;
	while (cub[0]->map[i][k] && k < j)
		k++;
	if (cub[0]->map[i][k] == '0' || cub[0]->map[i][k] == cub[0]->xyz[2])
	{
		if (ft_corner(&cub[0], cub[0]->p_ort, i, j) == 1
			&& cub[0]->map[i][k] == '0')
			return (0);
		else if (ft_there_is_a_wall_in_my_way(cub, s, 'r'))
			return (0);
		else
		{
			if (cub[0]->map[i][k] == '0')
				ft_move_player_pos_sides(&cub[0], i, j);
			return (1);
		}
	}
	return (0);
}

//s = side_angle.
