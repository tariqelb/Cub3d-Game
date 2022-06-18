/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnt_a_wall.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:19:50 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/03 00:14:46 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_up_side_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int 	line_i;
	int		i;
	char	ch;

	line_i = cub->p_i - 1;
	if (c == 'd')
		line_i = cub->p_i + 1;
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
	if (c == 'd')
		cub->p_i++;
	else
		cub->p_i--;
	return (1);
}

int	ft_check_down_side_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int 	line_i;
	int		i;
	char	ch;

	line_i = cub->p_i + 1;
	if (c == 'd')
		line_i = cub->p_i - 1;
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
	if (c == 'd')
		cub->p_i--;
	else
		cub->p_i++;
	return (1);
}

int	ft_check_left_side_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int 	line_i;
	int		i;
	int		j;
	char	ch;

	line_i = cub->p_i;
	map_line = cub->map[line_i];
	j = cub->p_j - 1;
	if (c == 'd')
		j = cub->p_j + 1;
	i = 0;
	while (map_line[i] && i < j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	if (c == 'd')
		cub->p_j++;
	else
		cub->p_j--;
	return (1);
}

int	ft_check_right_side_and_update(t_cub3d *cub, char c)
{
	char	*map_line;
	int 	line_i;
	int		i;
	int		j;
	char	ch;

	line_i = cub->p_i;
	map_line = cub->map[line_i];
	j = cub->p_j + 1;
	if (c == 'd')
		j = cub->p_j - 1;
	i = 0;
	while (map_line[i] && i < j)
		i++;
	if (map_line[i] == '1' || map_line[i] == 0)
		return (0);
	ch = cub->map[cub->p_i][cub->p_j];
	cub->map[cub->p_i][cub->p_j] = '0';
	cub->map[line_i][i] = ch;
	if (c == 'd')
		cub->p_j--;
	else
		cub->p_j++;
	return (1);
}
