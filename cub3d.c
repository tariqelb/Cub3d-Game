/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:00:48 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 19:03:52 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close_win(t_cub3d **cub)
{
	ft_free_tab(cub[0]->map, NULL, NULL);
	free(cub[0]);
	free(cub);
	mlx_clear_window(cub[0]->mlx, cub[0]->win);
	mlx_destroy_window(cub[0]->mlx, cub[0]->win);
	exit(0);
	return (0);
}

void	ft_cub3d(t_cub3d **cub)
{
	ft_help_handling(cub);
	mlx_hook(cub[0]->win, 17, 0, ft_close_win, &cub[0]);
	mlx_hook(cub[0]->win, 2, 0, ft_handle_keys, &cub[0]);
	mlx_hook(cub[0]->win, 6, 0, ft_handle_mouse, &cub[0]);
	mlx_loop(cub[0]->mlx);
}

int	main(int ac, char **av)
{
	t_cub3d	**cub;

	cub = NULL;
	if (ft_parse_map_file(ac, av))
		return (1);
	cub = (t_cub3d **) malloc(sizeof(t_cub3d *) * 2);
	if (cub == NULL)
		return (write(2, "Error\nFail to allocate memory\n", 30));
	cub[0] = (t_cub3d *) malloc(sizeof(t_cub3d));
	cub[1] = NULL;
	cub[0] = ft_initialize_struct(av[1], &cub[0]);
	if (cub[0] == NULL)
	{
		free(cub);
		write(2, "Error\nFail to allocate memory\n", 30);
		return (1);
	}
	cub[0]->mouse = 0;
	ft_cub3d(cub);
	return (0);
}
