/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:46:03 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:57:18 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_ray_hit_the_wall(t_cub3d **cub, int hyp)
{
	int	i;
	int	j;
	int	k;

	j = cub[0]->ray_pos[cub[0]->turn][0] / (int) cub[0]->cell_w_h[0];
	i = cub[0]->ray_pos[cub[0]->turn][1] / (int) cub[0]->cell_w_h[1];
	k = 0;
	while (cub[0]->map[i][k] && k < j)
		k++;
	if (cub[0]->map[i][k] == '1'
		|| (cub[0]->map[i][k] == '0' && ft_corner(cub, cub[0]->angle, i, j)))
	{
		cub[0]->ray_height[cub[0]->turn][0] = cub[0]->ray_pos[cub[0]->turn][0];
		cub[0]->ray_height[cub[0]->turn][1] = cub[0]->ray_pos[cub[0]->turn][1];
		ft_previews_cell(cub, hyp - 1, i, j);
		cub[0]->ray_height[cub[0]->turn][2] = HEIGHT - hyp;
		if (cub[0]->ray_height[cub[0]->turn][2] < 1)
			cub[0]->ray_height[cub[0]->turn][2] = 1;
		ft_real_distance(cub, cub[0]->turn, hyp);
		cub[0]->ray_height[cub[0]->turn][4] = hyp;
		return (1);
	}
	return (0);
}

void	ft_virtual_pos_of_ray_two(t_cub3d **cub, int turn, double adj)
{
	if (cub[0]->angle == 0)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] - adj;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0];
	}
	if (cub[0]->angle == 100)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1];
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] + adj;
	}
	if (cub[0]->angle == 200)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] + adj;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0];
	}
	if (cub[0]->angle == 300)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1];
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] - adj;
	}
}

void	ft_virtual_pos_of_ray(t_cub3d **cub, int turn, double adj, double opp)
{
	if (cub[0]->angle == 0 || cub[0]->angle == 100
		|| cub[0]->angle == 200 || cub[0]->angle == 300)
		ft_virtual_pos_of_ray_two(&cub[0], turn, adj);
	else if (cub[0]->angle > 0 && cub[0]->angle < 100)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] - adj;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] + opp;
	}
	else if (cub[0]->angle > 100 && cub[0]->angle < 200)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] + opp;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] + adj;
	}
	else if (cub[0]->angle > 200 && cub[0]->angle < 300)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] + adj;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] - opp;
	}
	else if (cub[0]->angle > 300 && cub[0]->angle < 400)
	{
		cub[0]->ray_pos[turn][1] = cub[0]->p_pos[1] - opp;
		cub[0]->ray_pos[turn][0] = cub[0]->p_pos[0] - adj;
	}
}

void	ft_get_length_of_ray(t_cub3d **cub)
{
	double	adj;
	double	opp;
	int		hyp;

	hyp = 1;
	while (1)
	{
		opp = ft_calc_opposite(cub[0]->angle, (double) hyp);
		adj = ft_calc_adjacent(cub[0]->angle, (double) hyp);
		ft_virtual_pos_of_ray(&cub[0], cub[0]->turn, adj, opp);
		if (ft_is_ray_hit_the_wall(&cub[0], (double) hyp))
			break ;
		hyp += 1;
	}
}

void	ft_ray_casting(t_cub3d **cub)
{
	double	turn_angle;

	turn_angle = ((double)60) / ((double) WIDTH);
	cub[0]->angle = cub[0]->p_ort - 30;
	if (cub[0]->angle < 0)
		cub[0]->angle += 400;
	cub[0]->number_of_rays = 0;
	cub[0]->turn = 0;
	while (cub[0]->turn < WIDTH)
	{
		cub[0]->ray_height[cub[0]->turn][0] = 0;
		cub[0]->angle = cub[0]->angle + turn_angle;
		if (cub[0]->angle >= 400)
			cub[0]->angle -= 400;
		ft_get_length_of_ray(&cub[0]);
		cub[0]->turn++;
	}
}
