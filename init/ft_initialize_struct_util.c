/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_struct_util.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:48:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 18:01:32 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_numbers(char *elem)
{
	int			*color;
	char		**tmp;
	long int	i;
	int			index;

	color = NULL;
	index = ft_skip_space(elem, 0);
	if (elem[index] == 'F' || elem[index] == 'C')
		index++;
	index = ft_skip_space(elem, index);
	tmp = ft_split(&elem[index], ',');
	i = ft_strlen_tab(tmp);
	if (ft_check_is_digit(tmp))
		return (-1);
	i = 0;
	color = (int *) malloc(sizeof(int) * 3);
	while (i < 3)
	{
		color[i] = ft_atoi(tmp[i]);
		i++;
	}
	ft_free_tab(tmp, NULL, NULL);
	i = (color[0] * 65536) + (color[1] * 256) + color[2];
	free(color);
	return (i);
}

void	*ft_get_texture(t_cub3d **cub, void *texture, char *elem)
{
	char	**tmp;
	int		h;
	int		w;

	tmp = NULL;
	tmp = ft_split(elem, ' ');
	h = 50;
	w = 50;
	texture = NULL;
	if (ft_strlen_tab(tmp) >= 1)
		texture = mlx_xpm_file_to_image(cub[0]->mlx, tmp[1], &h, &w);
	if (tmp != NULL)
		ft_free_tab(tmp, NULL, NULL);
	return (texture);
}

int	ft_check_texture(t_cub3d **cub)
{	
	if (cub[0]->n_txtr.txt == NULL || cub[0]->s_txtr.txt == NULL
		|| cub[0]->e_txtr.txt == NULL || cub[0]->w_txtr.txt == NULL)
		return (1);
	if (cub[0]->f == -1 || cub[0]->c == -1)
		return (1);
	cub[0]->img.img = mlx_new_image(cub[0]->mlx, WIDTH, HEIGHT);
	cub[0]->img.addr = mlx_get_data_addr(cub[0]->img.img,
			&cub[0]->img.bpp, &cub[0]->img.line_len, &cub[0]->img.endien);
	cub[0]->n_txtr.addr = mlx_get_data_addr(cub[0]->n_txtr.txt,
			&cub[0]->n_txtr.bpp, &cub[0]->n_txtr.line_len,
			&cub[0]->n_txtr.endien);
	cub[0]->s_txtr.addr = mlx_get_data_addr(cub[0]->s_txtr.txt,
			&cub[0]->s_txtr.bpp, &cub[0]->s_txtr.line_len,
			&cub[0]->s_txtr.endien);
	cub[0]->e_txtr.addr = mlx_get_data_addr(cub[0]->e_txtr.txt,
			&cub[0]->e_txtr.bpp, &cub[0]->e_txtr.line_len,
			&cub[0]->e_txtr.endien);
	cub[0]->w_txtr.addr = mlx_get_data_addr(cub[0]->w_txtr.txt,
			&cub[0]->w_txtr.bpp, &cub[0]->w_txtr.line_len,
			&cub[0]->w_txtr.endien);
	return (0);
}

int	ft_fill_cub(t_cub3d **cub, char **elems)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (ft_strncmp_skip(elems[i], "NO ", 3) == 0)
			cub[0]->n_txtr.txt = ft_get_texture(&cub[0],
					cub[0]->n_txtr.txt, elems[i]);
		else if (ft_strncmp_skip(elems[i], "SO ", 3) == 0)
			cub[0]->s_txtr.txt = ft_get_texture(&cub[0],
					cub[0]->s_txtr.txt, elems[i]);
		else if (ft_strncmp_skip(elems[i], "WE ", 3) == 0)
			cub[0]->w_txtr.txt = ft_get_texture(&cub[0],
					cub[0]->w_txtr.txt, elems[i]);
		else if (ft_strncmp_skip(elems[i], "EA ", 3) == 0)
			cub[0]->e_txtr.txt = ft_get_texture(&cub[0],
					cub[0]->e_txtr.txt, elems[i]);
		else if (ft_strncmp_skip(elems[i], "F ", 2) == 0)
			cub[0]->f = ft_get_numbers(elems[i]);
		else if (ft_strncmp_skip(elems[i], "C ", 2) == 0)
			cub[0]->c = ft_get_numbers(elems[i]);
	}
	if (ft_check_texture(&cub[0]))
		return (1);
	return (0);
}

int	ft_fill_cub_elems(t_cub3d **cub, char *av)
{
	char	**elems;
	int		n;
	int		i;
	int		j;

	n = ft_number_of_lines_in_file(av);
	elems = (char **) malloc(sizeof(char *) * (n + 1));
	elems = ft_fill_elem(av, &elems);
	ft_remove_newline(&elems[0], ft_strlen_tab(elems));
	if (ft_fill_cub(&cub[0], elems))
	{
		ft_free_tab(elems, NULL, NULL);
		return (1);
	}
	i = 6;
	j = 0;
	cub[0]->map = (char **) malloc(sizeof(char *) * (n - 5));
	while (i < n)
		cub[0]->map[j++] = ft_strdup_case(elems[i++]);
	cub[0]->map[j] = NULL;
	ft_get_p_position(&cub[0]);
	ft_free_tab(elems, NULL, NULL);
	return (0);
}
