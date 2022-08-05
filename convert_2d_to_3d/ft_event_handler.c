/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:13:25 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 16:36:52 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_display_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("map --> %d [%s]\n", i, map[i]);
		i++;
	}
}

int	ft_handle_mouse(int x, int y, void **data)
{
	t_cub3d **cub;


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
	ft_ray_casting(cub);
	mlx_clear_window(cub[0]->mlx, cub[0]->win);
	ft_screan_display(cub[0]);
	ft_mini_map_display(cub);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->map_img, 0, 0);
	//ft_sprite_but(cub);
	return (0);
}

int	ft_handle_keys(int key, t_cub3d **cub)
{
	char	c;

	c = 0;
	if (key == 123 )
		c = '<';
	else if (key == 124)
		c = '>';
	else if (key == 0)
		c = 'l';
	else if (key == 2)
		c = 'r';
	else if (key == 125 || key == 1)
		c = 'd';
	else if (key == 126 || key == 13)
		c = 'u';
	else if (key == 53)
		ft_close_win(cub);
	else
		return (0);
	ft_move_player(&cub[0], c);
	ft_ray_casting(&cub[0]);
	mlx_clear_window(cub[0]->mlx, cub[0]->win);
	ft_screan_display(cub[0]);
	ft_mini_map_display(cub);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->img, 0, 0);
	mlx_put_image_to_window(cub[0]->mlx, cub[0]->win, cub[0]->map_img, 0, 0);
	//ft_sprite_but(cub);
	return (0);
}
