/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 20:52:23 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/06/18 11:54:23 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_check_middle_line_util(char *line, int *spc, int *ort, int i)
{
	while (line[i])
	{
		if (ft_valide_char(line[i], 1) == 0)
			return (1);
		if (i == 0 && line[i] == ' ')
			ft_skip_and_check(line, &i);
		else if (i == 0 && line[0] != ' ' && line[0] != '1')
			return (1);
		else if (line[i] == ' ' && line[i - 1] == '1')
			ft_skip_and_check(line, &i);
		else if (ft_valide_char(line[i], 0))
		{
			if (line[i] == '0')
				spc[0]++;
			else if (ft_valide_char(line[i], 2))
				ort[0]++;
			i++;
		}
		else if (line[i] == ' ' && i != 0
				&& (line[i - 1] != '1' || line[i + 1] != '1'))
			return (1);
		else
			i++;
	}
	return (0);
}

int	ft_check_middle_lines(char *line, int *spc, int *ort)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(line);
	if (len < 2)
		return (1);
	i = ft_skip_space(line, i);
	if (line[i] != '1')
		return (1);
	if (line[len - 1] != '1')
		return (1);
	i = 0;
	if (ft_check_middle_line_util(line, &spc[0], &ort[0], i))
		return (1);
	return (0);
}

int	ft_check_first_and_last_line_util(char *line, int i, int *w)
{
	while (line[i])
	{
		if (line[i] != '1' && line[i] != 32)
			return (1);
		if (line[i] == '1')
			w[0]++;
		if (line[i] == ' ')
		{
			i = ft_skip_space(line, i);
			if (line[i] != '1')
				return (1);
		}
		else
			i++;
	}
	return (0);
}

int	ft_check_first_and_last_line(char *line)
{
	int len;
	int	i;
	int	w;

	len = ft_strlen(line);
	if (len < 2)
		return (1);
	i = 0;
	w = 0;
	if (line[i] == ' ')
	{
		i = ft_skip_space(line, i);
		if (line[i] != '1')
			return (1);
	}
	if (ft_check_first_and_last_line_util(line, i, &w))
		return (1);
	if (w < 2)
		return (1);
	return (0);
}

int	ft_check_map(char **elem_tab, int len)
{
	int	i;
	int	n;
	int	spc;
	int	ort;

	spc = 0;
	ort = 0;
	i = 0;
	while (elem_tab[i])
	{
		n = ft_strlen(elem_tab[i]);
		elem_tab[i][n - 1] = 0;
		if (i == 0 || i == len - 1)
		{
			if (ft_check_first_and_last_line(elem_tab[i]))
				return (ft_error(7));
		}
		else if (ft_check_middle_lines(elem_tab[i], &spc, &ort))
			return (ft_error(7));
		i++;
	}
	if (spc < 1 || ort != 1)
		return (ft_error(7));
	return (0);
}
