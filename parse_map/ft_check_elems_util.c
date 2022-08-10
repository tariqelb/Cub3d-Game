/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_elems_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 21:25:05 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/16 22:24:27 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_is_two_elems(char *elem)
{
	int		i;
	int		j;
	char	**tab;

	tab = ft_split_case(elem, ' ');
	i = 0;
	if (tab == NULL)
		return (1);
	while (tab[i] != NULL)
		i++;
	j = 0;
	if (i != 2)
	{
		ft_free_tab(tab, NULL, NULL);
		return (1);
	}
	ft_free_tab(tab, NULL, NULL);
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
	int	i;

	i = 0;
	while (nbr[i] == ' ')
		i++;
	while (nbr[i] && (nbr[i] >= '0' && nbr[i] <= '9'))
		i++;
	while (nbr[i] == ' ')
		i++;
	if (nbr[i] != '\0')
		return (0);
	i = ft_atoi(nbr);
	if (i >= 0 && i <= 255)
		return (1);
	return (0);
}

int	ft_is_color(char *line)
{
	char	**nbr;
	int		i;

	line[ft_strlen(line) - 1] = 0;
	nbr = ft_split(line, ',');
	if (nbr == NULL)
		return (0);
	i = ft_strlen_tab(nbr);
	if (i != 3)
	{
		nbr = ft_free_tab(nbr, NULL, NULL);
		return (0);
	}
	i = 0;
	while (i < 3)
	{
		if (ft_is_one_or_three_digit(nbr[i]) == 0)
		{
			nbr = ft_free_tab(nbr, NULL, NULL);
			return (1);
		}
		i++;
	}
	nbr = ft_free_tab(nbr, NULL, NULL);
	return (0);
}
