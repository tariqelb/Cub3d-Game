/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 14:09:08 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 16:38:27 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_sprite(int key, t_cub3d **cub)
{
	if (key == 49)
	{
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt2, (WIDTH / 2) - 125, HEIGHT - 250);
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt3, (WIDTH / 2) - 125, HEIGHT - 250);
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt1, (WIDTH / 2) - 125, HEIGHT - 250);
	}
   return (0);	
}

int	ft_sprite_but(t_cub3d **cub)
{
	mlx_clear_window(cub[0]->mlx, cub[0]->win);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt1, (WIDTH / 2) - 125, HEIGHT - 250);
	return (0);	
}

/*
int	ft_sprite_t(int key, t_cub3d **cub)
{
	//printf("Hello from mlx_loop_hook [1000] %d\n", cub[0]->shot);
	
	if (cub[0]->shot == 1)
	{
		printf("Hello from mlx_loop_hook [2] %d\n", cub[0]->shot);
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt2, (WIDTH / 2) - 125, HEIGHT - 250);
		cub[0]->shot = 2;
	}
	if (cub[0]->shot == 2)
	{
		printf("Hello from mlx_loop_hook [3] %d\n", cub[0]->shot);
		mlx_clear_window(cub[0]->mlx, cub[0]->win);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
		mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->spt3, (WIDTH / 2) - 125, HEIGHT - 250);
		cub[0]->shot = 0;
		printf("Hello from mlx_loop_hook [4] %d\n", cub[0]->shot);
	}
	
   return (0);	
}*/

