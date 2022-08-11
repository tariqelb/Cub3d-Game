/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:03:15 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 19:05:01 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			elem[0][i++] = ft_strdup(line);
		else if (i > 6 && ft_strlen(line) == 1)
		{
			elem[0][i] = NULL;
			ft_free_tab(elem[0], line, NULL);
			close(fd);
			ft_error(7);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	elem[0][i] = NULL;
	return (elem[0]);
}

char	**ft_fill_elem_parse(char *av, char ***elem)
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
			elem[0][i++] = ft_strdup(line);
		else if (i > 6)// && ft_strlen(line) == 1)
		{
			elem[0][i] = NULL;
			ft_free_tab(elem[0], line, NULL);
			close(fd);
			ft_error(7);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	elem[0][i] = NULL;
	return (elem[0]);
}

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

int	ft_parse_map_file_lines(char *av, int v_elem)
{
	int		len;
	char	**elem_tab;

	len = ft_number_of_lines_in_file(av);
	if (len == 0)
		return (ft_error(3));
	elem_tab = (char **) malloc(sizeof(char *) * len + 1);
	elem_tab[len] = NULL;
	if (ft_fill_elem_parse(av, &elem_tab) == NULL)
		return (0);
	int i ;
	i = 0;
	v_elem = ft_check_elems(elem_tab);
	printf(" ellelel %d\n", v_elem);
	if (v_elem != 6 || len < 9)
	{
		elem_tab = ft_free_tab(elem_tab, NULL, NULL);
		return (ft_error(4) - 1);
	}
	i = 0;
	v_elem += ft_check_map(&elem_tab[6], len - 6);
	if (v_elem != 6)
	{
		elem_tab = ft_free_tab(elem_tab, NULL, NULL);
		return (0);
	}
	v_elem += ft_check_map_again(&elem_tab[6], 0, 0);
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
	if (n_valide_elems == 6)
		return (0);
	return (1);
}
