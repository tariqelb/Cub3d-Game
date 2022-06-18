/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_struct_util.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 22:48:21 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/29 20:33:01 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_numbers(char *elem)
{
	int			*color;
	char		**tmp1;
	char		**tmp2;
	long int	i;

	tmp1 = NULL;
	tmp2 = NULL;
	color = NULL;
	tmp1 = ft_split(elem, ' ');
	if (tmp1 && tmp1[1] != NULL)
	{
		tmp2 = ft_split(tmp1[1], ',');
		i = 0;
		color = (int *) malloc(sizeof(int) * 3);
		while (i < 3)
		{
			color[i] = ft_atoi(tmp2[i]);
			i++;
		}
		ft_free_tab(tmp1, NULL, NULL);
		ft_free_tab(tmp2, NULL, NULL);
	}
	i = (color[0] * 65536) + (color[1] * 256) + color[2];
	free(color);
	return (i);
}

void	*ft_get_texture(t_cub3d *cub, void *texture, char *elem)
{
	char	**tmp;
	int		h;
	int		w;

	elem[ft_strlen(elem) - 1] = 0;
	h = 10;
	w = 10;
	tmp = NULL;
	tmp = ft_split(elem, ' ');
	texture = mlx_xpm_file_to_image(cub->mlx, tmp[1], &h, &w);
	ft_free_tab(tmp, NULL, NULL);
	return (texture);
}

int	ft_check_texture(t_cub3d *cub)
{	
	int endian;
	int	size_line;
	int	bits_per_pixel;

	if (cub->txt_n == NULL || cub->txt_s == NULL
			|| cub->txt_w == NULL || cub->txt_e == NULL)
		return (1);
	endian = 0;
	bits_per_pixel = 2;
	size_line = 96;
	cub->add_n = mlx_get_data_addr(cub->txt_n, &bits_per_pixel, &size_line, &endian);
	cub->add_s = mlx_get_data_addr(cub->txt_s, &bits_per_pixel, &size_line, &endian);
	cub->add_e = mlx_get_data_addr(cub->txt_e, &bits_per_pixel, &size_line, &endian);
	cub->add_w = mlx_get_data_addr(cub->txt_w, &bits_per_pixel, &size_line, &endian);
	return (0);
}

int	ft_fill_cub(t_cub3d *cub, char **elems)
{
	int 	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(elems[i] , "NO ", 3) == 0)
			cub->txt_n = ft_get_texture(cub, cub->txt_n, elems[i]);
		else if (ft_strncmp(elems[i] , "SO ", 3) == 0)
			cub->txt_s = ft_get_texture(&cub[0], cub->txt_s, elems[i]);
		else if (ft_strncmp(elems[i] , "WE ", 3) == 0)
			cub->txt_w = ft_get_texture(&cub[0], cub->txt_w, elems[i]);
		else if (ft_strncmp(elems[i] , "EA ", 3) == 0)
			cub->txt_e = ft_get_texture(&cub[0], cub->txt_e, elems[i]);
		else if (ft_strncmp(elems[i] , "F ", 2) == 0)
			cub->f = ft_get_numbers(elems[i]);
		else if (ft_strncmp(elems[i] , "C ", 2) == 0)
			cub->c = ft_get_numbers(elems[i]);
		i++;
	}
	if (ft_check_texture(cub))
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
	if (ft_fill_cub(cub[0], elems))
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
