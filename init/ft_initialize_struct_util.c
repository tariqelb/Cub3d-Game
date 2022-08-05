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

void	*ft_get_texture(t_cub3d **cub, void *texture, char *elem)
{
	char	**tmp;
	int		h;
	int		w;

	elem[ft_strlen(elem) - 1] = 0;
	h = 50;
	w = 50;
	tmp = NULL;
	tmp = ft_split(elem, ' ');
	//printf("%s\n", tmp[1]);
	texture = mlx_xpm_file_to_image(cub[0]->mlx, tmp[1], &h, &w);
	ft_free_tab(tmp, NULL, NULL);
	return (texture);
}

int	ft_check_texture(t_cub3d **cub)
{	
	if (cub[0]->n_txtr.txt == NULL || cub[0]->s_txtr.txt == NULL
			|| cub[0]->e_txtr.txt == NULL || cub[0]->w_txtr.txt == NULL)
		return (1);
	cub[0]->img = mlx_new_image(cub[0]->mlx, WIDTH, HEIGHT);
	cub[0]->addr = mlx_get_data_addr(cub[0]->img, &cub[0]->bpp ,&cub[0]->line_len, &cub[0]->endien);
	cub[0]->n_txtr.addr = mlx_get_data_addr(cub[0]->n_txtr.txt, &cub[0]->n_txtr.bpp, &cub[0]->n_txtr.line_len, &cub[0]->n_txtr.endien);
	cub[0]->s_txtr.addr = mlx_get_data_addr(cub[0]->s_txtr.txt, &cub[0]->s_txtr.bpp, &cub[0]->s_txtr.line_len, &cub[0]->s_txtr.endien);
	cub[0]->e_txtr.addr = mlx_get_data_addr(cub[0]->e_txtr.txt, &cub[0]->e_txtr.bpp, &cub[0]->e_txtr.line_len, &cub[0]->e_txtr.endien);
	cub[0]->w_txtr.addr = mlx_get_data_addr(cub[0]->w_txtr.txt, &cub[0]->w_txtr.bpp, &cub[0]->w_txtr.line_len, &cub[0]->w_txtr.endien);
	return (0);
}

int	ft_fill_cub(t_cub3d **cub, char **elems)
{
	int 	i;

	i = 0;
	while (i < 6)
	{
		if (ft_strncmp(elems[i] , "NO ", 3) == 0)
			cub[0]->n_txtr.txt = ft_get_texture(&cub[0], cub[0]->n_txtr.txt, elems[i]);
		else if (ft_strncmp(elems[i] , "SO ", 3) == 0)
			cub[0]->s_txtr.txt = ft_get_texture(&cub[0], cub[0]->s_txtr.txt, elems[i]);
		else if (ft_strncmp(elems[i] , "WE ", 3) == 0)
			cub[0]->w_txtr.txt = ft_get_texture(&cub[0], cub[0]->w_txtr.txt, elems[i]);
		else if (ft_strncmp(elems[i] , "EA ", 3) == 0)
			cub[0]->e_txtr.txt = ft_get_texture(&cub[0], cub[0]->e_txtr.txt, elems[i]);
		else if (ft_strncmp(elems[i] , "F ", 2) == 0)
			cub[0]->f = ft_get_numbers(elems[i]);
		else if (ft_strncmp(elems[i] , "C ", 2) == 0)
			cub[0]->c = ft_get_numbers(elems[i]);
		i++;
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
