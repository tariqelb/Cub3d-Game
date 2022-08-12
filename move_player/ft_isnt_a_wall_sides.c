/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnt_a_wall_sides.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 15:49:24 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:21:58 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_up_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int		line_i;
	int		i;
	char	ch;

	(void)c;
	line_i = cub->p_i - 1;
	if (line_i == 0 || line_i == cub->xyz[0])
		return (0);
	map_line = cub->map[line_i];
	i = 0;
	while (map_line[i] && i < cub->p_j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	cub->p_i--;
	return (1);
}

int	ft_check_down_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int		line_i;
	int		i;
	char	ch;

	(void)c;
	line_i = cub->p_i + 1;
	if (line_i == cub->xyz[0] || line_i == 0)
		return (0);
	map_line = cub->map[line_i];
	i = 0;
	while (map_line[i] && i < cub->p_j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	cub->p_i++;
	return (1);
}

int	ft_check_left_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int		line_i;
	int		i;
	int		j;
	char	ch;

	(void)c;
	line_i = cub->p_i;
	map_line = cub->map[line_i];
	j = cub->p_j - 1;
	i = 0;
	while (map_line[i] && i < j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	cub->p_j--;
	return (1);
}

int	ft_check_right_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int		line_i;
	int		i;
	int		j;
	char	ch;

	(void)c;
	line_i = cub->p_i;
	map_line = cub->map[line_i];
	j = cub->p_j + 1;
	i = 0;
	while (map_line[i] && i < j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	cub->p_j++;
	return (1);
}
