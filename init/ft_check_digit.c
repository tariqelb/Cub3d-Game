/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:25:59 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 21:26:05 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_digit(char c)
{
	if ((c >= '0' && c <= '9') || c == ' ')
		return (0);
	return (1);
}

int	ft_check_is_digit(char **tmp)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 3)
	{
		k = 0;
		k = ft_strlen(tmp[i]);
		if (tmp[i][k - 1] == '\n')
			tmp[i][k - 1] = 0;
		j = 0;
		while (tmp[i][j])
		{
			if (ft_is_digit(tmp[i][j]))
				return (1);
			j++;
		}
		if (ft_at_least_one_digit(tmp[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_at_least_one_digit(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		if (tmp[i] >= '0' && tmp[i] <= '9')
			return (0);
		i++;
	}
	return (1);
}
