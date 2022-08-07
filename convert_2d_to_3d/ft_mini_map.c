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
	char    *pixel;

    pixel = cub[0]->map_addr + (y * cub[0]->m_line_len + x * (cub[0]->m_bpp / 8));
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

void	ft_help_micro_map(t_cub3d **cub, int i, int index_i, int index_j)
{
	int	j;
	int	color;

	j = 0;
	while (j < cub[0]->map_w)
	{
		if (i % 21 == 0 || j % 21 == 0)
			img_pix_put(cub[0], j, i, 16711680);
		else
		{
			color = ft_wall_space_player(cub, index_i, index_j);
			if (color == 1)
				my_img_pix_put(&cub[0], j, i, 1616800);
			if (color == 2)
				my_img_pix_put(&cub[0], j, i, 12799680);
			if (color == 3)
				my_img_pix_put(&cub[0], j, i, 1927699);
		}
		j++;
		if (j % 21 == 0)
			index_j++;
	}
}

void	ft_micro_map_display(t_cub3d **cub)
{
	int	i;
	int	index_i;
	int	index_j;

	cub[0]->map_w = (20 * 3) + 4;
	cub[0]->map_h = (20 * 4) + 5;
	cub[0]->map_img = mlx_new_image(cub[0]->mlx, cub[0]->map_w, cub[0]->map_h);
	cub[0]->map_addr = mlx_get_data_addr(cub[0]->map_img,
			&cub[0]->m_bpp, &cub[0]->m_line_len, &cub[0]->m_endien);
	i = 0;
	index_i = cub[0]->p_i - 2;
	if (index_i < 0)
		index_i = 0;
	while (i < cub[0]->map_h)
	{
		index_j = cub[0]->p_j - 1;
		ft_help_micro_map(cub, i, index_i, index_j);
		i++;
		if (i % 21 == 0)
			index_i++;
	}
}

void	ft_mini_map_display(t_cub3d **cub)
{
	int	i;
	int	j;
	int	index_i;
	int	index_j;
	int	color;

	if (cub[0]->xyz[0] > 40 || cub[0]->xyz[1] > 60)
		ft_micro_map_display(cub);
	else
	{
		cub[0]->map_w = (cub[0]->xyz[1] * 6) + (cub[0]->xyz[1] + 1);
		cub[0]->map_h = (cub[0]->xyz[0] * 6) + (cub[0]->xyz[0] + 1);
		cub[0]->map_img = mlx_new_image(cub[0]->mlx, cub[0]->map_w, cub[0]->map_h);
		cub[0]->map_addr = mlx_get_data_addr(cub[0]->map_img, &cub[0]->m_bpp, &cub[0]->m_line_len, &cub[0]->m_endien);
		i = 0;
		index_i = 0;
		while (i < cub[0]->map_h)
		{
			j = 0;
			index_j = 0;
			while (j < cub[0]->map_w)
			{
				color = ft_wall_space_player(cub, index_i, index_j);
				if (color == 1)
					my_img_pix_put(&cub[0], j, i, 1616800);
				if (color == 2)
					my_img_pix_put(&cub[0], j, i, 12799680);
				if (color == 3)
					my_img_pix_put(&cub[0], j, i, 1927699);
				j++;
				if (j % 7 == 0)
					index_j++;
			}
			i++;
			if (i % 7 == 0)
				index_i++;
		}
	}
}
