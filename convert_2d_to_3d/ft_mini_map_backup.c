/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 13:37:19 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/04 15:10:31 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_img_pix_put(t_img *img, int x, int y, int color)
{
	char    *pixel;

    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

int ft_wall_space_player(t_cub3d **cub, int i, int j)
{
    char    *map;
    int     index;

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
    else if (map[index] == 'S' || map[index] == 'E' || map[index] == 'N' || map[index] == 'A')
        return (3);
    return (0);
}

void	ft_mini_map_display(t_cub3d **cub)
{
	int	i;
	int	j;
	int	index_i;
	int	index_j;
	int	color;

	img.map_w = (cub[0]->xyz[1] * 6) + (cub[0]->xyz[1] + 1);
	img.map_h = (cub[0]->xyz[0] * 6) + (cub[0]->xyz[0] + 1);
	img.mlx_map = mlx_new_image(img.mlx_ptr, img.map_w, img.map_h);
	img.addr_map = mlx_get_data_addr(img.mlx_img, &img.bpp ,&img.line_len, &img.endien);
	i = 0;
	index_i = 0;
	while (i < img.map_h)
	{
		j = 0;
		index_j = 0;
		while (j < img.map_w)
		{
			//if (i % 7 == 0 || j % 7 == 0)
			//	my_img_pix_put(&img, j, i, 16711680);
			//else
			//{
				color = ft_wall_space_player(cub, index_i, index_j);
				if (color == 1)
					my_img_pix_put(&img, j, i, 1616800);
				if (color == 2)
					my_img_pix_put(&img, j, i, 12799680);
				if (color == 3)
					my_img_pix_put(&img, j, i, 1927699);
			//}
			j++;
			if (j % 7 == 0)
				index_j++;
		}
		i++;
		if (i % 7 == 0)
			index_i++;
	}
}
