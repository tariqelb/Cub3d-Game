/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_util.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:03:45 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:54:19 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_valide_char(char c, int flag)
{
	if (flag == 1)
	{
		if (c == '1' || c == '0' || c == 'S'
			|| c == 'N' || c == 'E' || c == 'W' || c == ' ')
			return (1);
	}
	else if (flag == 0)
	{
		if (c == '1' || c == '0' || c == 'S'
			|| c == 'N' || c == 'E' || c == 'W')
			return (1);
	}
	else
	{
		if (c == 'S' || c == 'N' || c == 'E'
			|| c == 'W')
			return (1);
	}
	return (0);
}

int	ft_skip_and_check(char *line, int *i)
{
	while (line[i[0]] && line[i[0]] == ' ')
		i[0]++;
	if (line[i[0]] != '1')
		return (1);
	return (0);
}

int	ft_skip_space(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}
