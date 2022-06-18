/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_position_calc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-bouh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:58:03 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/05/24 09:02:31 by tel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_simple_pos_calc_backward(t_cub3d **cub, char c)
{
	if (c == 'd')
	{
		if (cub[0]->p_ort == 0)
			cub[0]->p_pos[1] += STEP;
		else if (cub[0]->p_ort == 100)
			cub[0]->p_pos[0] -= STEP;
		else if (cub[0]->p_ort == 200)
			cub[0]->p_pos[1] -= STEP;
		else if (cub[0]->p_ort == 300)
			cub[0]->p_pos[0] += STEP;
		else if (cub[0]->p_ort == 400)
			cub[0]->p_pos[1] += STEP;
	}
}

void	ft_simple_pos_calc(t_cub3d **cub, char c)
{
	if (ft_check_new_pos_forward(cub[0], c))
	{
		if (c == 'u')
		{
			if (cub[0]->p_ort == 0)
				cub[0]->p_pos[1] -= STEP;
			else if (cub[0]->p_ort == 100)
				cub[0]->p_pos[0] += STEP;
			else if (cub[0]->p_ort == 200)
				cub[0]->p_pos[1] += STEP;
			else if (cub[0]->p_ort == 300)
				cub[0]->p_pos[0] -= STEP;
			else if (cub[0]->p_ort == 400)
				cub[0]->p_pos[1] -= STEP;
		}
		else
			ft_simple_pos_calc_backward(cub, c);
	}
}
