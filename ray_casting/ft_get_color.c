/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:58:51 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 11:55:06 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_chose_color_number(double closest[])
{
	if (closest[0] <= closest[1] && closest[0] <= closest[2] && closest[0] <= closest[3])
		return (1);
	else if (closest[1] <= closest[0] && closest[1] <= closest[2] && closest[1] <= closest[3])
		return (2);
	else if (closest[2] <= closest[0] && closest[2] <= closest[1] && closest[2] <= closest[3])
		return (3);
	else if (closest[3] <= closest[0] && closest[3] <= closest[1] && closest[3] <= closest[2])
		return (4);
	return (0);
}

int	ft_chose_color(t_cub3d **cub, int turn, int x, int y)
{
	double	closest[4];
	int	ranges[4];

	ranges[0] = cub[0]->cell_w_h[0] * y;
	ranges[1] = cub[0]->cell_w_h[0] * (y + 1);
	ranges[2] = cub[0]->cell_w_h[1] * x;
	ranges[3] = cub[0]->cell_w_h[1] * (x + 1);
	closest[0] = cub[0]->ray_pos[turn][0] - ranges[0];
	closest[1] = cub[0]->ray_pos[turn][0] - ranges[1];
	closest[2] = cub[0]->ray_pos[turn][1] - ranges[2];
	closest[3] = cub[0]->ray_pos[turn][1] - ranges[3];
	if (closest[0] < 0)
		closest[0] *= -1;
	if (closest[1] < 0)
		closest[1] *= -1;
	if (closest[2] < 0)
		closest[2] *= -1;
	if (closest[3] < 0)
		closest[3] *= -1;
	return (ft_chose_color_number(closest));
}


int	ft_previews_cell(t_cub3d **cub, int hyp, int i, int j, int turn)
{
	double	adj;
	double	opp;
	int	x;
	int	y;

	opp = ft_calc_opposite(cub[0]->angle, hyp);
	adj = ft_calc_adjacent(cub[0]->angle, hyp);
	ft_virtual_pos_of_ray(&cub[0], turn, adj, opp);
	y = cub[0]->ray_pos[turn][0] / (int) cub[0]->cell_w_h[0];
	x = cub[0]->ray_pos[turn][1] / (int) cub[0]->cell_w_h[1];
	if (i == x && j < y)
	{
		cub[0]->ray_height[turn][3] = 1;
		cub[0]->text_x[turn] = ((int)(cub[0]->ray_pos[turn][1]) % 50);
	}
	else if (i == x && j > y)
	{

		cub[0]->ray_height[turn][3] = 2;
		cub[0]->text_x[turn] = ((int)(cub[0]->ray_pos[turn][1]) % 50);

	}
	else if (j == y && i < x)
	{
		cub[0]->ray_height[turn][3] = 3;
		cub[0]->text_x[turn] = ((int)(cub[0]->ray_pos[turn][0]) % 50);
	}
	else if (j == y && i > x)
	{
		cub[0]->ray_height[turn][3] = 4,
		cub[0]->text_x[turn] = ((int)(cub[0]->ray_pos[turn][0]) % 50);
	}
	else if (turn > 0)
	{
		cub[0]->text_x[turn] = 	((int)cub[0]->ray_height[turn - 1][1] % 50),
		cub[0]->ray_height[turn][3] = 	cub[0]->ray_height[turn - 1][3];
	}
	else
		cub[0]->text_x[turn] = (cub[0]->ray_height[turn][1] % 50),
		cub[0]->ray_height[turn][3] = ft_chose_color(cub, turn, x, y);
	if (turn == 1)	
		cub[0]->ray_height[turn - 1][3] = cub[0]->ray_height[turn][3];
	return (0);
}

/*
int	ft_previews_cell(t_cub3d **cub, int hyp, int i, int j, int turn)
{
	double	adj;
	double	opp;
	int	x;
	int	y;

	opp = ft_calc_opposite(cub[0]->angle, hyp);
	adj = ft_calc_adjacent(cub[0]->angle, hyp);
	ft_virtual_pos_of_ray(&cub[0], turn, adj, opp);
	y = cub[0]->ray_pos[turn][0] / (int) cub[0]->cell_w_h[0];
	x = cub[0]->ray_pos[turn][1] / (int) cub[0]->cell_w_h[1];
	if (i == x && j < y)
		cub[0]->ray_height[turn][3] = 1;
	else if (i == x && j > y)
		cub[0]->ray_height[turn][3] = 2;
	else if (j == y && i < x)
		cub[0]->ray_height[turn][3] = 3;
	else if (j == y && i > x)
		cub[0]->ray_height[turn][3] = 4;
	else if (turn > 0)
		cub[0]->ray_height[turn][3] = 	cub[0]->ray_height[turn - 1][3];
	else
		cub[0]->ray_height[turn][3] = ft_chose_color(cub, turn, x, y);
	if (turn == 1)	
		cub[0]->ray_height[turn - 1][3] = cub[0]->ray_height[turn][3];
	return (0);
}*/
