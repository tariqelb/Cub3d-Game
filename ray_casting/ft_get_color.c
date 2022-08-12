/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:58:51 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:37:03 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_chose_color_number(double closest[])
{
	if (closest[0] <= closest[1]
		&& closest[0] <= closest[2] && closest[0] <= closest[3])
		return (1);
	else if (closest[1] <= closest[0]
		&& closest[1] <= closest[2] && closest[1] <= closest[3])
		return (2);
	else if (closest[2] <= closest[0]
		&& closest[2] <= closest[1] && closest[2] <= closest[3])
		return (3);
	else if (closest[3] <= closest[0]
		&& closest[3] <= closest[1] && closest[3] <= closest[2])
		return (4);
	return (0);
}

int	ft_chose_color(t_cub3d **cub, int turn)
{
	double	closest[4];
	int		ranges[4];

	ranges[0] = cub[0]->cell_w_h[0] * cub[0]->y;
	ranges[1] = cub[0]->cell_w_h[0] * (cub[0]->y + 1);
	ranges[2] = cub[0]->cell_w_h[1] * cub[0]->x;
	ranges[3] = cub[0]->cell_w_h[1] * (cub[0]->x + 1);
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

int	ft_previews_cell_norm_cases_two(t_cub3d **cub, int hyp, int i, int j)
{
	(void)hyp;
	if (j == cub[0]->y && i < cub[0]->x)
	{
		cub[0]->ray_height[cub[0]->turn][3] = 3;
		cub[0]->text_x[cub[0]->turn]
			= ((int)(cub[0]->ray_pos[cub[0]->turn][0]) % 50);
	}
	else if (j == cub[0]->y && i > cub[0]->x)
	{
		cub[0]->ray_height[cub[0]->turn][3] = 4;
		cub[0]->text_x[cub[0]->turn]
			= ((int)(cub[0]->ray_pos[cub[0]->turn][0]) % 50);
	}
	else
		return (0);
	return (1);
}

int	ft_previews_cell_norm_cases(t_cub3d **cub, int hyp, int i, int j)
{
	if (i == cub[0]->x && j < cub[0]->y)
	{
		cub[0]->ray_height[cub[0]->turn][3] = 1;
		cub[0]->text_x[cub[0]->turn]
			= ((int)(cub[0]->ray_pos[cub[0]->turn][1]) % 50);
	}
	else if (i == cub[0]->x && j > cub[0]->y)
	{
		cub[0]->ray_height[cub[0]->turn][3] = 2;
		cub[0]->text_x[cub[0]->turn]
			= ((int)(cub[0]->ray_pos[cub[0]->turn][1]) % 50);
	}
	else
		return (ft_previews_cell_norm_cases_two(cub, hyp, i, j));
	return (1);
}

int	ft_previews_cell(t_cub3d **cub, int hyp, int i, int j)
{
	cub[0]->opp = ft_calc_opposite(cub[0]->angle, hyp);
	cub[0]->adj = ft_calc_adjacent(cub[0]->angle, hyp);
	ft_virtual_pos_of_ray(&cub[0], cub[0]->turn, cub[0]->adj, cub[0]->opp);
	cub[0]->y = cub[0]->ray_pos[cub[0]->turn][0] / (int) cub[0]->cell_w_h[0];
	cub[0]->x = cub[0]->ray_pos[cub[0]->turn][1] / (int) cub[0]->cell_w_h[1];
	if (ft_previews_cell_norm_cases(cub, hyp, i, j))
		return (0);
	else if (cub[0]->turn > 0)
	{
		cub[0]->text_x[cub[0]->turn]
			= ((int)cub[0]->ray_height[cub[0]->turn - 1][1] % 50);
		cub[0]->ray_height[cub[0]->turn][3]
			= cub[0]->ray_height[cub[0]->turn - 1][3];
	}
	else
	{
		cub[0]->text_x[cub[0]->turn]
			= (cub[0]->ray_height[cub[0]->turn][1] % 50);
		cub[0]->ray_height[cub[0]->turn][3] = ft_chose_color(cub, cub[0]->turn);
	}
	if (cub[0]->turn == 1)
		cub[0]->ray_height[cub[0]->turn - 1][3]
			= cub[0]->ray_height[cub[0]->turn][3];
	return (0);
}
