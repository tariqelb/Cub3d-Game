/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:37:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:01:59 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_img_pix_put(t_cub3d **cub, int x, int y, int color)
{
	char	*pixel;

	pixel = cub[0]->map_addr
		+ (y * cub[0]->m_line_len + x * (cub[0]->m_bpp / 8));
	*(unsigned int *)pixel = color;
}

int	ft_wall_space_player(t_cub3d **cub, int i, int j)
{
	char	*map;
	int		index;

	map = cub[0]->map[i];
	if (map == NULL)
		return (0);
	index = 0;
	while (map[index] && index < j)
		index++;
	if (map[index] == '1')
		return (1);
	else if (map[index] == '0')
		return (2);
	else if (map[index] == 'S' || map[index] == 'E'
		|| map[index] == 'N' || map[index] == 'W')
		return (3);
	return (0);
}

void	ft_display_mini_map_util(t_cub3d **cub, int index_i, int index_j)
{
	int	color;

	while (cub[0]->x < cub[0]->map_h)
	{
		cub[0]->y = 0;
		index_j = 0;
		while (cub[0]->y < cub[0]->map_w)
		{
			color = ft_wall_space_player(cub, index_i, index_j);
			if (color == 1)
				my_img_pix_put(&cub[0], cub[0]->y, cub[0]->x, 1616800);
			if (color == 2)
				my_img_pix_put(&cub[0], cub[0]->y, cub[0]->x, 12799680);
			if (color == 3)
				my_img_pix_put(&cub[0], cub[0]->y, cub[0]->x, 1927699);
			if (color == 4)
				my_img_pix_put(&cub[0], cub[0]->y, cub[0]->x, 0000000);
			cub[0]->y++;
			if (cub[0]->y % 7 == 0)
				index_j++;
		}
		cub[0]->x++;
		if (cub[0]->x % 7 == 0)
			index_i++;
	}
}

void	ft_mini_map_display(t_cub3d **cub)
{
	int	index_i;
	int	index_j;

	if (cub[0]->xyz[0] > 40 || cub[0]->xyz[1] > 60)
		ft_micro_map_display(cub);
	else
	{
		cub[0]->map_w = (cub[0]->xyz[1] * 6) + (cub[0]->xyz[1] + 1);
		cub[0]->map_h = (cub[0]->xyz[0] * 6) + (cub[0]->xyz[0] + 1);
		cub[0]->map_img = mlx_new_image(cub[0]->mlx,
				cub[0]->map_w, cub[0]->map_h);
		cub[0]->map_addr = mlx_get_data_addr(cub[0]->map_img,
				&cub[0]->m_bpp, &cub[0]->m_line_len, &cub[0]->m_endien);
		cub[0]->x = 0;
		index_i = 0;
		ft_display_mini_map_util(cub, index_i, index_j);
	}
}
