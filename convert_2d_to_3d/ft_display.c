/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:41:22 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:58:23 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	img_pix_put(t_cub3d *cub, int x, int y, int color)
{
	char	*pixel;

	pixel = cub->img.addr + (y * cub->img.line_len + x * (cub->img.bpp / 8));
	*(unsigned int *)pixel = color;
}

int	get_color(t_cub3d *cub, int x, int y, int index)
{
	if (cub->ray_height[index][3] == 3)
		return (*(int *)(cub->n_txtr.addr
			+ (y * cub->n_txtr.line_len + x * (cub->n_txtr.bpp / 8))));
	else if (cub->ray_height[index][3] == 4)
		return (*(int *)(cub->s_txtr.addr
			+ (y * cub->s_txtr.line_len + x * (cub->s_txtr.bpp / 8))));
	else if (cub->ray_height[index][3] == 2)
		return (*(int *)(cub->w_txtr.addr
			+ (y * cub->w_txtr.line_len + x * (cub->w_txtr.bpp / 8))));
	else if (cub->ray_height[index][3] == 1)
		return (*(int *)(cub->e_txtr.addr
			+ (y * cub->e_txtr.line_len + x * (cub->e_txtr.bpp / 8))));
	return (0);
}

void	ft_help_display(int i, int j, t_cub3d *cub, int mid)
{
	int		color;
	double	middle;

	middle = (double)((i - cub->vertical) - ((HEIGHT / 2) - mid));
	color = get_color(cub, cub->text_x[j],
			(int)((double)(50.0 * middle / cub->ray_height[j][2])) % 50, j);
	if (cub->ray_height[j][3] == 1)
		img_pix_put(&cub[0], j, i, color);
	else if (cub->ray_height[j][3] == 2)
		img_pix_put(&cub[0], j, i, color);
	else if (cub->ray_height[j][3] == 3)
		img_pix_put(&cub[0], j, i, color);
	else if (cub->ray_height[j][3] == 4)
		img_pix_put(&cub[0], j, i, color);
}

void	ft_screan_display(t_cub3d *cub, int i, int j)
{
	int	mid;
	int	v;

	v = cub->vertical;
	while (++j < WIDTH - 1)
	{
		i = 0;
		mid = (cub->ray_height[j][2] / 2);
		while (++i < HEIGHT)
		{
			if (i - v < (((HEIGHT / 2) - mid)))
				img_pix_put(&cub[0], j, i, 0);
			else if (i - v > (((HEIGHT / 2) + mid)))
				img_pix_put(&cub[0], j, i, 16777215);
			else if ((i - v >= (((HEIGHT / 2) - mid)))
				&& (i - v <= (((HEIGHT / 2)))))
				ft_help_display(i, j, cub, mid);
			else if ((i - v >= (((HEIGHT / 2))))
				&& (i - v <= (((HEIGHT / 2) + mid))))
				ft_help_display(i, j, cub, mid);
		}
	}
}
