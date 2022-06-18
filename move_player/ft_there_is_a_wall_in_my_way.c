/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_there_is_a_wall_in_my_way.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 21:50:54 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/04 13:00:58 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_cell_content(t_cub3d **cub)
{
	int	i;
	int	j;
	int	k;

	j = cub[0]->vir_pos[0] / (int) cub[0]->cell_w_h[0];
	i = cub[0]->vir_pos[1] / (int) cub[0]->cell_w_h[1];
	k = 0;
	while (cub[0]->map[i][k] && k < j)
		k++;
	if (cub[0]->map[i][k] == '1')
		return (1);
	return (0);
}

void    ft_for_vir_pos(t_cub3d **cub, double adj, double opp, int sides_angle)
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

void    ft_back_vir_pos(t_cub3d **cub, double adj, double opp, int sides_angle)
{
	if (sides_angle > 0 && sides_angle < 100)
    {
        cub[0]->vir_pos[1] = cub[0]->p_pos[1] + adj;
        cub[0]->vir_pos[0] = cub[0]->p_pos[0] - opp;
    }
    else if (sides_angle > 100 && sides_angle < 200)
    {
        cub[0]->vir_pos[1] = cub[0]->p_pos[1] - opp;
        cub[0]->vir_pos[0] = cub[0]->p_pos[0] - adj;
    }
    else if (sides_angle > 200 && sides_angle < 300)
    {
        cub[0]->vir_pos[1] = cub[0]->p_pos[1] - adj;
        cub[0]->vir_pos[0] = cub[0]->p_pos[0] + opp;
    }
    else if (sides_angle > 300 && sides_angle < 400)
    {
        cub[0]->vir_pos[1] = cub[0]->p_pos[1] + opp;
        cub[0]->vir_pos[0] = cub[0]->p_pos[0] + adj;
    }
}

int	ft_there_is_a_wall_in_my_way(t_cub3d **cub, int sides_angle, char c)
{
	double	adj;
	double	opp;
	int		hyp;

	hyp = 1;
	while (hyp <= STEP)
	{
		opp = ft_calc_opposite(sides_angle, (double) hyp);
		adj = ft_calc_adjacent(sides_angle, (double) hyp);
		if (c == 'r')
			ft_vir_pos_sides(cub, adj, opp, sides_angle);
		if (c == 'd')
			ft_back_vir_pos(&cub[0], adj, opp, sides_angle);
		else
			ft_for_vir_pos(&cub[0], adj, opp, sides_angle);
		if (ft_check_cell_content(&cub[0]))
			return (1);
		hyp += 1;
	}
	return (0);
}
