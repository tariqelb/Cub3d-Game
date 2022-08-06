/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_there_is_a_wall.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 15:16:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:33:16 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_forward_vir_pos(t_cub3d **cub, double adj, double opp)
{
	if (cub[0]->p_ort > 0 && cub[0]->p_ort < 100)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + opp;
	}
	if (cub[0]->p_ort > 100 && cub[0]->p_ort < 200)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + adj;
	}
	if (cub[0]->p_ort > 200 && cub[0]->p_ort < 300)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - opp;
	}
	if (cub[0]->p_ort > 300 && cub[0]->p_ort < 400)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - adj;
	}
}

void	ft_virtual_positoin(t_cub3d **cub, double adj, double opp, char c)
{
	if (c == 'u')
		ft_forward_vir_pos(cub, adj, opp);
	else if (cub[0]->p_ort > 0 && cub[0]->p_ort < 100)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - opp;
	}
	else if (cub[0]->p_ort > 100 && cub[0]->p_ort < 200)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] - adj;
	}
	else if (cub[0]->p_ort > 200 && cub[0]->p_ort < 300)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] - adj;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + opp;
	}
	else if (cub[0]->p_ort > 300 && cub[0]->p_ort < 400)
	{
		cub[0]->vir_pos[1] = cub[0]->p_pos[1] + opp;
		cub[0]->vir_pos[0] = cub[0]->p_pos[0] + adj;
	}
}

void	ft_move_player_pos(t_cub3d **cub, int i, int j)
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

int	ft_there_is_a_wall(t_cub3d **cub, double adj, double opp, char c)
{
	int	i;
	int	j;
	int	k;

	ft_virtual_positoin(cub, adj, opp, c);
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
		else if (ft_there_is_a_wall_in_my_way(cub, cub[0]->p_ort, c))
			return (0);
		else
		{
			if (cub[0]->map[i][k] == '0')
				ft_move_player_pos(&cub[0], i, j);
			return (1);
		}
	}
	return (0);
}
