/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:13:25 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/05 20:04:01 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_display_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("map --> %d [%s]\n", i, map[i]);
		i++;
	}
}

void	ft_help_handling(t_cub3d **cub)
{
	ft_ray_casting(&cub[0]);
	mlx_clear_window(cub[0]->mlx, cub[0]->win);
	ft_screan_display(cub[0], -1, -1);
	ft_mini_map_display(cub);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img.img, 0, 0);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->map_img, 0, 0);
}

int	ft_handle_mouse(int x, int y, void **data)
{
	t_cub3d	**cub;

	(void) y;
	cub = (t_cub3d **) data;
	if (cub[0]->mouse == 0)
		cub[0]->mouse = x;
	else if (cub[0]->mouse <= x)
			cub[0]->p_ort += 5;
	else if (cub[0]->mouse > x)
		cub[0]->p_ort -= 5;
	cub[0]->mouse = x;
	if (cub[0]->p_ort > 400)
		cub[0]->p_ort -= 400;
	else if (cub[0]->p_ort < 0)
		cub[0]->p_ort += 400;
	ft_help_handling(cub);
	return (0);
}

int	ft_vertical_move(t_cub3d **cub, int key)
{
	if (key == 126)
	{
		if (cub[0]->vertical < 150)
			cub[0]->vertical += 10;
		else
			return (0);
	}
	else if (key == 125)
	{
		if (cub[0]->vertical > -150)
			cub[0]->vertical -= 10;
		else
			return (0);
	}
	return (0);
}

int	ft_handle_keys(int key, t_cub3d **cub)
{
	char	c;

	c = 0;
	if (key == 123)
		c = 'l';
	else if (key == 124)
		c = 'r';
	else if (key == 0)
		c = '<';
	else if (key == 2)
		c = '>';
	else if (key == 1)
		c = 'd';
	else if (key == 13)
		c = 'u';
	else if (key == 53)
		ft_close_win(cub);
	else if (key == 126 || key == 125)
		ft_vertical_move(&cub[0], key);
	else
		return (0);
	ft_move_player(&cub[0], c);
	ft_help_handling(&cub[0]);
	return (0);
}
