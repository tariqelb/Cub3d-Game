/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:34:42 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:20:45 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_position_in_pixel(t_cub3d **cub, int xyz[3], int x, int max_y)
{
	cub[0]->p_pos[0] = (50) * xyz[1] + ((50) / 2);
	cub[0]->p_pos[1] = (50) * xyz[0] + ((50) / 2);
	if (xyz[2] == 'N')
		cub[0]->p_ort = 0;
	if (xyz[2] == 'W')
		cub[0]->p_ort = 100;
	if (xyz[2] == 'S')
		cub[0]->p_ort = 200;
	if (xyz[2] == 'E')
		cub[0]->p_ort = 300;
	cub[0]->p_i = xyz[0];
	cub[0]->p_j = xyz[1];
	cub[0]->xyz[0] = x;
	cub[0]->xyz[1] = max_y - 1;
	cub[0]->xyz[2] = xyz[2];
	cub[0]->cell_w_h[0] = 50;
	cub[0]->cell_w_h[1] = 50;
}

void	ft_get_p_position(t_cub3d **cub)
{
	int	x;
	int	y;
	int	max_y;
	int	xyz[3];

	x = 0;
	max_y = 0;
	while (cub[0]->map[x])
	{
		y = 0;
		while (cub[0]->map[x][y++])
		{
			if (cub[0]->map[x][y] == 'N' || cub[0]->map[x][y] == 'S'
					|| cub[0]->map[x][y] == 'W' || cub[0]->map[x][y] == 'E')
			{
				xyz[0] = x;
				xyz[1] = y;
				xyz[2] = cub[0]->map[x][y];
			}
		}
		if (y > max_y)
			max_y = y;
		x++;
	}
	ft_position_in_pixel(&cub[0], xyz, x, max_y);
}

int	ft_mlx_error(int number)
{
	write(2, "Error\n", 6);
	if (number == 1)
		write(2, "Fail to allocate memory\n", 24);
	else if (number == 2)
		write(2, "Fail to initialize mlx\n", 24);
	else if (number == 3)
		write(2, "Fail to initialize window\n", 27);
	return (1);
}

t_cub3d	*ft_initialize_struct(char *av, t_cub3d **cub)
{
	cub[0]->mlx = mlx_init();
	if (cub[0]->mlx == NULL)
	{
		free(cub[0]);
		ft_mlx_error(2);
		return (NULL);
	}
	cub[0]->win = NULL;
	cub[0]->win = mlx_new_window(cub[0]->mlx, WIDTH, HEIGHT, "CUB3D");
	if (cub[0]->win == NULL)
	{
		free(cub[0]);
		ft_mlx_error(3);
		return (NULL);
	}
	if (ft_fill_cub_elems(&cub[0], av))
	{
		free(cub[0]);
		return (NULL);
	}
	return (cub[0]);
}
