/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:41:22 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 15:25:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	img_pix_put(t_cub3d *cub, int x, int y, int color)
{
	char    *pixel;

    pixel = cub->addr + (y * cub->line_len + x * (cub->bpp / 8));
	*(unsigned int *)pixel = color;
}

int	get_color(t_cub3d *cub, int x, int y, int index)
{
	if (cub->ray_height[index][3] == 3)
	{
		//printf ("%d\n", *(int *)cub->n_txtr.addr + (y * cub->n_txtr.line_len + x * (cub->n_txtr.bpp / 8)));
		return (*(int *)(cub->n_txtr.addr + (y * cub->n_txtr.line_len + x * (cub->n_txtr.bpp / 8))));
	}
	else if (cub->ray_height[index][3] == 4)
	{
		//printf ("%d\n", *(int *)cub->s_txtr.addr + (y * cub->s_txtr.line_len + x * (cub->s_txtr.bpp / 8)));
		return (*(int *)(cub->s_txtr.addr + (y * cub->s_txtr.line_len + x * (cub->s_txtr.bpp / 8))));
	}
	else if (cub->ray_height[index][3] == 2)
	{
		//printf("%d\n", *(int *)cub->w_txtr.addr + (y * cub->w_txtr.line_len + x  * (cub->w_txtr.bpp / 8)));
		return (*(int *)(cub->w_txtr.addr + (y * cub->w_txtr.line_len + x  * (cub->w_txtr.bpp / 8))));
	}
	else if (cub->ray_height[index][3] == 1)
	{
		//printf("%d\n", *(int *)cub->e_txtr.addr + (y * cub->e_txtr.line_len + x  * (cub->e_txtr.bpp / 8)));
		return (*(int *)(cub->e_txtr.addr + (y * cub->e_txtr.line_len + x  * (cub->e_txtr.bpp / 8))));
	}
	return (0);
}

void	ft_screan_display(t_cub3d *cub)
{
	int i;
	int	j;
	int	mid;
	int	index;
	int	color;
	int v_x;
	int flep;

	v_x = 0;
	flep = 0;
	ft_camera(&cub);
	index = 0;
	i = 0;
	j = 0;
	while (index < WIDTH && j < WIDTH - 1)
	{
		if (flep == 0)
				flep = cub->ray_height[index][3];
		if (flep != cub->ray_height[index][3])
		{
			flep = cub->ray_height[index][3];
			v_x = 0;
		}
		if (v_x == 0)
			v_x = cub->text_x[index];
		if (v_x == 50)
			v_x = 0;
		//printf("===> x = %d\n", v_x);
		i = 0;
		mid = cub->ray_height[index][2] / 2;
		while (i < HEIGHT)
		{
			if (i < ((HEIGHT / 2) - mid))
				img_pix_put(&cub[0], j, i, 0);
			else if (i > ((HEIGHT / 2) + mid))
				img_pix_put(&cub[0], j, i, 16777215);
			else if ((i >= ((HEIGHT / 2) - mid)) && (i <= ((HEIGHT / 2) + mid)))
			{
				if (cub->ray_height[index][3] == 1)
					img_pix_put(&cub[0], j, i, get_color(cub, cub->text_x[index] , (int)((double)(50.0 * (double)(i - ((HEIGHT / 2) - mid)) / cub->ray_height[index][2]) ) % 50, index));
				else if (cub->ray_height[index][3] == 2)
					img_pix_put(&cub[0], j, i, get_color(cub, cub->text_x[index] , (int)((double)(50.0 * (double)(i - ((HEIGHT / 2) - mid)) / cub->ray_height[index][2])) % 50, index));
				else if (cub->ray_height[index][3] == 3)
					img_pix_put(&cub[0], j, i, get_color(cub, cub->text_x[index] , (int)((double)(50.0 * (double)(i - ((HEIGHT / 2) - mid)) / cub->ray_height[index][2])) % 50, index));
				else if (cub->ray_height[index][3] == 4)
					img_pix_put(&cub[0], j, i, get_color(cub, cub->text_x[index] , (int)((double)(50.0 * (double)(i - ((HEIGHT / 2) - mid)) / cub->ray_height[index][2])) % 50, index));
			}
			i++;
		}
		index++;
		j++;
		v_x++;
	}
}
/*

void	ft_screan_display(t_cub3d *cub)
{
	int i;
	int	j;
	int	mid;
	int	index;
	int	color;
	int v_x;
	int flep;

	v_x = 0;
	flep = 0;
	ft_camera(&cub);
	index = 0;
	i = 0;
	j = 0;
	while (index < WIDTH && j < WIDTH - 1)
	{
		if (flep == 0)
				flep = cub->ray_height[index][3];
		if (flep != cub->ray_height[index][3])
		{
			flep = cub->ray_height[index][3];
			v_x = 0;
		}
		if (v_x == 0)
			v_x = cub->text_x[index];
		if (v_x == 50)
			v_x = 0;
		//printf("===> x = %d\n", v_x);
		i = 0;
		mid = cub->ray_height[index][2] / 2;
		while (i < HEIGHT)
		{
			if (i < ((HEIGHT / 2) - mid))
				img_pix_put(&cub[0], j, i, 0);
			else if (i > ((HEIGHT / 2) + mid))
				img_pix_put(&cub[0], j, i, 16777215);
			else if ((i >= ((HEIGHT / 2) - mid)) && (i <= ((HEIGHT / 2) + mid)))
			{
				if (cub->ray_height[index][3] == 1)
					img_pix_put(&cub[0], j, i,  get_color(cub,  (int)cub->text_x[index] , (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 2)
					img_pix_put(&cub[0], j, i, get_color(cub, (int)cub->text_x[index] , (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 3)
					img_pix_put(&cub[0], j, i, get_color(cub, (int)cub->text_x[index]  , (i - ((HEIGHT / 2) - mid)) % 50, index));
				else if (cub->ray_height[index][3] == 4)
					img_pix_put(&cub[0], j, i, get_color(cub, (int)cub->text_x[index] , (i - ((HEIGHT / 2) - mid)) % 50, index));
			}
			i++;
		}
		index++;
		j++;
		v_x++;
	}
}
*/
// last and correct version of display

void	ft_camera(t_cub3d **cub)
{
	double	dev;
	int		dec;

	dev = (double) WIDTH / 1700;
	dec = (int) WIDTH / 1700;
	if ((double) dec < dev)
		cub[0]->cmr = dec + 1;
	else
		cub[0]->cmr = dec;
}
/*
// display texture of the wall instead of the colors.
void	ft_screan_display(t_cub3d *cub)
{
	int i;
	int	j;
	int	mid;
	int	index;

	ft_camera(&cub);
	index = 0;
	j = 0;
	while (index < (WIDTH - 1) && j < WIDTH - 1)
	{
		i = 0;
		mid = cub->ray_height[index][2] / 2;
		while (i < HEIGHT)
		{
			if (i < ((HEIGHT / 2) - mid))
				img_pix_put(&cub[0], j, i, 0);
			else if ((i >= ((HEIGHT / 2) - mid)) && (i <= ((HEIGHT / 2) + mid)))
			{
				if (cub->ray_height[index][3] == 1)
					img_pix_put(&cub[0], j, i, 16711680);//red
				else if (cub->ray_height[index][3] == 2)
					img_pix_put(&cub[0], j, i, 65280);//green
				else if (cub->ray_height[index][3] == 3)
					img_pix_put(&cub[0], j, i, 255);//blue
				else if (cub->ray_height[index][3] == 4)
					img_pix_put(&cub[0], j, i, 16777116);//yellow
			}
			else if (i > ((HEIGHT / 2) + mid))
				img_pix_put(&cub[0], j, i, 16777215);
			i++;
		}
		//if (j % cub->cmr == 0)
			index++;
		j++;
	}
}
*/