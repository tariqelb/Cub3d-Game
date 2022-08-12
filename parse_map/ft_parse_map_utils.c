/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:05:48 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 22:06:09 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_valide_extension(char *av)
{
	int	i;

	i = ft_strlen(av);
	if (i < 5)
		return (0);
	if (av[i] == 0 && av[i - 1] == 'b' && av[i - 2] == 'u'
		&& av[i - 3] == 'c' && av[i - 4] == '.')
		return (1);
	return (0);
}

void	ft_remove_newline(char **tab, int number_of_line)
{
	int	i;
	int	len;

	i = 0;
	while (i < number_of_line)
	{
		len = 0;
		len = ft_strlen(tab[i]);
		if (tab[i][len - 1] == '\n')
		{
			tab[i][len - 1] = 0;
		}
		i++;
	}
}

int	ft_last_space_in_line(char *tab, int i, int j)
{
	int	x;

	(void) i;
	x = j;
	while (tab[x])
	{
		if (tab[x] == ' ')
			x++;
		else
			return (0);
	}
	return (1);
}
