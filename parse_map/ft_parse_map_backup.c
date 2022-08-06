/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map_backup.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:03:15 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/06 09:34:26 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_error(int number)
{
	write(2, "error\n", 6);
	if (number == 1)
		write(2, "Invalide Number of arguments\n", 28);
	if (number == 2)
		write(2, "can't open map file\n", 20);
	if (number == 3)
		write(2, "Empty file .cub\n", 16);
	if (number == 4)
		write(2, "messing element\n", 16);
	if (number == 5)
		write(2, "Empty map\n", 10);
	if (number == 6)
		write(2, "Not a valide extension\n", 23);
	if (number == 7)
		write(2, "Not a valide Map\n", 17);
	return (1);
}

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

int	ft_number_of_lines_in_file(char	*av)
{
	char	*line;
	int		fd;
	int		i;
	int		len;

	fd = open(av, O_RDONLY);
	if (fd < 3)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 1)
			i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

char	**ft_fill_elem(char *av, char ***elem)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(av, O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strlen(line) > 1)
		{
			elem[0][i] = ft_strdup(line);
			i++;
		}
		free(line);
		line = get_next_line(fd);
	}
	elem[0][i] = NULL;
	return (elem[0]);
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

int	ft_is_a_file(char *line)
{
	int		fd;

	fd = open(line, O_RDONLY);
	if (fd > 2)
	{
		close(fd);
		return (1);
	}
	if (fd != -1)
		close (fd);
	return (0);
}

int	ft_is_one_or_three_digit(char *nbr)
{
	int	i;

	i = ft_strlen(nbr);
	if (i == 0 || i > 3)
		return (0);
	i = 0;
	while (nbr[i])
	{
		if (nbr[i] < '0' || nbr[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	i = ft_atoi(nbr);
	if (i >= 0 && i <= 255)
		return (1);
	return (0);
}

int	ft_is_color(char *line)
{
	char	**nbr;
	int		i;

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
			return (0);
		}
		i++;
	}
	nbr = ft_free_tab(nbr, NULL, NULL);
	return (1);
}

int	ft_check_line(char *line, char *elem, int len)
{
	char	**tab;
	int		i;

	tab = ft_split(line, ' ');
	if (ft_strcmp(tab[0], elem) == 0)
	{
		i = ft_strlen(tab[1]);
		if (tab[1][i -1] == '\n')
			tab[1][i -1] = 0;
		if (len == 2 && ft_is_a_file(tab[1]))
		{
			ft_free_tab(tab, NULL, NULL);
			return (1);
		}
		else if (len == 1 && ft_is_color(tab[1]))
		{
			ft_free_tab(tab, NULL, NULL);
			return (1);
		}
	}
	ft_free_tab(tab, NULL, NULL);
	return (0);
}

void	ft_check_elem_identifers(int **elem, char **elem_tab, int i)
{
	if (elem[0][0] == 0)
		elem[0][0] = ft_check_line(elem_tab[i], "NO", 2);
	if (elem[0][1] == 0)
		elem[0][1] = ft_check_line(elem_tab[i], "SO", 2);
	if (elem[0][2] == 0)
		elem[0][2] = ft_check_line(elem_tab[i], "WE", 2);
	if (elem[0][3] == 0)
		elem[0][3] = ft_check_line(elem_tab[i], "EA", 2);
	if (elem[0][4] == 0)
		elem[0][4] = ft_check_line(elem_tab[i], "F", 1);
	if (elem[0][5] == 0)
		elem[0][5] = ft_check_line(elem_tab[i], "C", 1);
}

int	ft_check_elems(char	**elem_tab)
{
	int	i;
	int	*elem;
	int	sum;

	elem = (int *) malloc(sizeof(int) * 6);
	i = 0;
	while (i < 6)
		elem[i++] = 0;
	i = 0;
	while (elem_tab[i] && i < 6)
	{
		ft_check_elem_identifers(&elem, elem_tab, i);
		i++;
	}
	i = 0;
	sum = 0;
	while (i < 6)
	{
		sum += elem[i];
		i++;
	}
	free(elem);
	return (sum);
}

int	ft_skip_space(char *line, int i)
{
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
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

int	ft_valide_char(char c, int flag)
{
	if (flag == 1)
	{
		if (c == '1' || c == '0' || c == 'S'
				|| c == 'N' || c == 'E' ||
				c == 'W' || c == ' ')
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
		else if (line[i] == ' ' && i != 0 && (line[i - 1] != '1' || line[i + 1] != '1'))
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

	len = ft_strlen(line);
	if (len < 2)
		return (1);
	if (line[len - 1] != '1')
		return (1);
	i = 0;
	if (ft_check_middle_line_util(line, &spc[0], &ort[0], i))
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

int	ft_check_above(char **tab, int i, int j)
{
	int	len;

	len = ft_strlen(tab[i]);
	if (len > j)
	{
		if (tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
		if (tab[i - 1][j] != ' ' && tab[i - 1][j] != '1')
			return (1);
		if (tab[i - 1][j + 1] != ' ' && tab[i - 1][j + 1] != '1')
			return (1);
	}
	else if (len == j)
	{
		if (tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
		if (tab[i - 1][j] != ' ' && tab[i - 1][j] != '1')
			return (1);
	}
	else if (len == j - 1)
	{
		if (tab[i - 1][j - 1] != ' ' && tab[i - 1][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_check_under(char **tab, int i, int j)
{
	int	len;

	len = ft_strlen(tab[i]);
	if (len > j)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
		if (tab[i + 1][j] != ' ' && tab[i + 1][j] != '1')
			return (1);
		if (tab[i + 1][j + 1] != ' ' && tab[i + 1][j + 1] != '1')
			return (1);
	}	
	if (len == j)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
		if (tab[i + 1][j] != ' ' && tab[i + 1][j] != '1')
			return (1);
	}
	if (len == j - 1)
	{
		if (tab[i + 1][j - 1] != ' ' && tab[i + 1][j - 1] != '1')
			return (1);
	}
	return (0);
}

int	ft_go_check_if_one_surronded_space(char **tab, int i, int j, int ver)
{
	int	k;

	k = j;
	while (k > 0 && tab[i][k] == ' ')
		k--;
	if (tab[i][k] != '1')
		return (1);
	k = j;
	while (tab[i][j] && tab[i][k] == ' ')
		k++;
	if (tab[i][k] != '1')
		return (1);
	k = 0;
	if (i == 0)
		k = ft_check_under(tab, i, j);
	else if (i == ver - 1)
		k = ft_check_above(tab, i, j);
	else
	{
		k = ft_check_under(tab, i, j);
		k += ft_check_above(tab, i, j);
	}
	if (k)
		return (1);
	return (0);
}

int	ft_range_to_check(int s1)
{
	if (s1 == 0)
		return (s1);
	return (s1 - 1);
}

int	ft_check_left_side(char **tab, int i, int s1, int s2)
{
	int	j;

	if (s1 > s2)
	{
		j = ft_range_to_check(s2);
		while (j < s1)
		{
			if (tab[i + 1][j] != '1')
				return (1);
			j++;
		}
	}
	else if (s1 < s2)
	{
		j = ft_range_to_check(s1);
		while (j < s2)
		{
			if (tab[i][j] != '1')
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_check_right_side(char **tab, int i, int s1, int s2)
{
	int	j;

	if (s1 > s2)
	{
		j = ft_range_to_check(s2);
		while (j < s1)
		{
			if (tab[i][j] != '1')
				return (1);
			j++;
		}
	}
	else if (s1 < s2)
	{
		j = ft_range_to_check(s1);
		while (j < s2)
		{
			if (tab[i + 1][j] != '1')
				return (1);
			j++;
		}
	}
	return (0);
}

int	ft_check_if_sides_suronded_by_one(char **tab, int i, int ver)
{
	int	strt;
	int	end;
	int	nxt_s;
	int	nxt_e;

	while (i < ver - 1)
	{
		strt = ft_skip_space(tab[i], 0);
		end = ft_strlen(tab[i]);
		nxt_s = ft_skip_space(tab[i + 1], 0);
		nxt_e = ft_strlen(tab[i + 1]);
		if (strt != nxt_s)
		{
			if (ft_check_left_side(tab, i, strt, nxt_s))
				return (1);
		}
		if (end != nxt_e)
		{
			if (ft_check_right_side(tab, i, end, nxt_e))
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_map_again(char **tab, int i, int j)
{
	int	ver;

	ver = ft_strlen_tab(tab);
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j] && tab[i][j] == ' ')
			j++;
		while (tab[i][j])
		{
			if (tab[i][j] == ' ')
			{
				if (ft_go_check_if_one_surronded_space(tab, i, j, ver))
					return (ft_error(7));
			}
			j++;
		}
		i++;
	}
	if (ft_check_if_sides_suronded_by_one(tab, 0, ver))
		return (ft_error(7));
	return (0);
}

int	ft_parse_map_file_lines(char *av, int v_elem)
{
	int		len;
	char	**elem_tab;

	len = ft_number_of_lines_in_file(av);
	if (len == 0)
		return (ft_error(3));
	elem_tab = (char **) malloc(sizeof(char *) * len + 1);
	elem_tab[len] = NULL;
	ft_fill_elem(av, &elem_tab);
	v_elem = ft_check_elems(elem_tab);
	if (v_elem != 6)
	{
		elem_tab = ft_free_tab(elem_tab, NULL, NULL);
		ft_error(4);
		return (0);
	}
	if (len < 9)
		return (ft_error(7));
	v_elem += ft_check_map(&elem_tab[6], len - 6);
	if (v_elem != 6)
		return (0);
	v_elem += ft_check_map_again(&elem_tab[6], 0, 0);
	elem_tab = ft_free_tab(elem_tab, NULL, NULL);
	return (v_elem);
}

int	ft_parse_map_file(int ac, char **av)
{
	int		n_valide_elems;
	char	*line;
	int		fd;

	if (ac != 2)
		return (ft_error(1));
	if (ft_valide_extension(av[1]) == 0)
		return (ft_error(6));
	fd = open(av[1], O_RDONLY);
	if (fd < 3)
		return (ft_error(2));
	n_valide_elems = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		close(fd);
		return (ft_error(3));
	}
	free(line);
	close(fd);
	n_valide_elems = ft_parse_map_file_lines(av[1], n_valide_elems);
	if (n_valide_elems == 7)
		return (0);
	return (1);
}
