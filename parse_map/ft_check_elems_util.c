/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elems_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:05 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 19:05:51 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_all_numbers(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] >= '0' && tab[i][j] <= '9')
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_copy_str(char *line, char **name, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		name[0][i] = line[i];
		i++;
	}
	name[0][i] = 0;
}

int	ft_is_one_or_three_digit(char *nbr)
{
	int		i;
	int		rslt;
	char	**tab;

	tab = ft_split(nbr, ' ');
	i = ft_strlen_tab(tab);
	if (i != 3 || ft_is_all_numbers(tab))
	{
		ft_free_tab(tab, NULL, NULL);
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		rslt = ft_atoi(tab[i]);
		if (rslt >= 0 && rslt <= 255)
			i++;
		else
		{
			ft_free_tab(tab, NULL, NULL);
			return (1);
		}		
	}
	ft_free_tab(tab, NULL, NULL);
	return (0);
}

int	ft_count_comma(char *line)
{
	int	i;
	int	sum;

	sum = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
			sum++;
		i++;
	}
	if (sum == 2)
		return (0);
	return (1);
}

int	ft_is_color(char *line)
{
	char	**nbr;
	int		i;

	nbr = ft_split(line, ',');
	if (nbr == NULL)
		return (0);
	i = ft_strlen_tab(nbr);
	if (i != 3 || ft_count_comma(line))
	{
		nbr = ft_free_tab(nbr, NULL, NULL);
		return (1);
	}
	if (ft_check_is_digit(nbr))
	{
		nbr = ft_free_tab(nbr, NULL, NULL);
		return (1);
	}
	nbr = ft_free_tab(nbr, NULL, NULL);
	return (0);
}
