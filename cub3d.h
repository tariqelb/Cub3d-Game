/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 10:36:39 by tel-bouh          #+#    #+#             */
/*   Updated: 2022/08/11 19:01:29 by zezzine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# include "./get_next_line/get_next_line.h"

# define HEIGHT	900
# define WIDTH	1700
# define STEP	25

typedef struct s_txt
{
	char	*txt;
	char	*addr;
	int		line_len;
	int		bpp;
	void	*img;
	int		endien;
}	t_txt;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	t_txt	n_txtr;	
	t_txt	s_txtr;	
	t_txt	e_txtr;	
	t_txt	w_txtr;
	t_txt	img;
	void	*map_img;
	char	*map_addr;
	int		m_endien;
	int		m_line_len;
	int		m_bpp;
	char	**map;
	int		map_w;
	int		map_h;
	int		f;
	int		c;
	double	p_pos[2];
	int		xyz[3];
	double	vir_pos[2];
	int		p_ort;
	int		p_i;
	int		p_j;
	double	cell_w_h[2];
	double	ray_pos[WIDTH + 1][2];
	int		ray_height[WIDTH + 1][6];
	double	angle;
	int		mouse;
	int		number_of_rays;
	int		cmr;
	int		x;
	int		y;
	int		vertical;
	int		turn;
	int		adj;
	int		opp;
	int		text_x[2001];
}	t_cub3d;

typedef struct s_img
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*mlx_img;
	void	*mlx_map;
	char	*addr;
	char	*addr_map;
	int		map_w;
	int		map_h;
	t_cub3d	*cub;
}			t_img;

//PARSE MAP
// ft_check_map_again_util.c
int		ft_range_to_check(int s1);
int		ft_check_left_side(char **tab, int i, int s1, int s2);
int		ft_check_right_side(char **tab, int i, int s1, int s2);
int		ft_check_if_sides_suronded_by_one(char **tab, int i, int ver);

// ft_check_map_again.c
int		ft_check_above(char **tab, int i, int j);
int		ft_check_under(char **tab, int i, int j);
int		ft_go_check_if_one_surronded_space(char **tab, int i, int j, int ver);
int		ft_check_map_again(char **tab, int i, int j);

// ft_check_map_util.c
int		ft_valide_char(char c, int flag);
int		ft_skip_and_check(char *line, int *i);
int		ft_skip_space(char *line, int i);

// ft_check_map.c
int		ft_check_middle_line_util(char *line, int *spc, int *ort, int i);
int		ft_check_middle_lines(char *line, int *spc, int *ort);
int		ft_check_first_and_last_line_util(char *line, int i, int *w);
int		ft_check_first_and_last_line(char *line);
int		ft_check_map(char **elem_tab, int len);

// ft_check_elems_util.c
int		ft_is_two_elems(char *elem);
void	ft_copy_str(char *line, char **name, int len);
int		ft_is_one_or_three_digit(char *nbr);
int		ft_is_color(char *line);

// ft_check_elems.c
int		ft_is_a_file(char *line);
int		ft_check_line(char *line, char *elem, int len);
int		ft_number_of_lines_in_file(char	*av);
void	ft_check_elem_identifers(int **elem, char **elem_tab, int i);
int		ft_check_elems(char	**elem_tab);

// ft_parse_map.c
char	**ft_fill_elem(char *av, char ***elem);
int		ft_error(int number);
int		ft_valide_extension(char *av);
int		ft_parse_map_file_lines(char *av, int v_elem);
int		ft_parse_map_file(int ac, char **av);

// ft_parse_map_utils.c
int		ft_last_space_in_line(char *tab, int i, int j);
void	ft_remove_newline(char **tab, int number_of_line);
int		ft_valide_extension(char *av);

// libft functions
int		ft_strlen_tab(char **str);
int		ft_strcmp_case(char *line, char *elem, int i);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_strdup_case(const char *src);
char	**ft_free_tab(char **str, char *arg1, char *arg2);
char	**ft_split(char const *str, char c);
int		ft_atoi(const char *ndr);
int		ft_odd_quote(const char *s, int index);
char	**ft_split_case(char const *s, char c);
//init dir
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strncmp_skip(char *s1, char *s2, size_t n);

// INIT
// ft_initialize_struct_util.c
int		ft_get_numbers(char *elem);
void	*ft_get_texture(t_cub3d **cub, void *texture, char *elem);
int		ft_check_texture(t_cub3d **cub);
int		ft_fill_cub_texture(t_cub3d **cub, char **elems);
int		ft_fill_cub_elems(t_cub3d **cub, char *av);

// ft_initialize_struct.c
void	ft_position_in_pixel(t_cub3d **cub, int xyz[], int x, int max_y);
void	ft_get_p_position(t_cub3d **cub);
int		ft_mlx_error(int number);
int		ft_at_least_one_digit(char *tmp);
//int		ft_initialize_window(t_cub3d ***cub);
t_cub3d	*ft_initialize_struct(char *av, t_cub3d **cub);

// ft_check_digit.c
int		ft_is_digit(char c);
int		ft_check_is_digit(char **tmp);
int		ft_at_least_one_digit(char *tmp);

// MOVE PLAYER
// ft_there_is_a_wall.c
void	ft_backward_vir_pos(t_cub3d **cub, double adj, double opp);
void	ft_virtual_positoin(t_cub3d **cub, double adj, double opp, char c);
int		ft_there_is_a_wall(t_cub3d **cub, double adj, double opp, char c);

// ft_isnt_a_wall.c
int		ft_check_up_side_and_update(t_cub3d *cub, char c);
int		ft_check_down_side_and_update(t_cub3d *cub, char c);
int		ft_check_left_side_and_update(t_cub3d *cub, char c);
int		ft_check_right_side_and_update(t_cub3d *cub, char c);

// ft_new_position_calc.c
double	ft_calc_opp0_or_adj1(int angle, int flag);
void	ft_new_position_forward(t_cub3d **cub, double adj, double opp);
void	ft_new_position_backward(t_cub3d **cub, double adj, double opp);

// ft_straight_move.c
void	ft_move_to_borders(t_cub3d *cub, char c);
int		ft_forward_position_calc(t_cub3d *cub, char c);
int		ft_check_new_pos_backward(t_cub3d *cub, char c);
int		ft_check_new_pos_forward(t_cub3d *cub, char c);

// ft_move_player.c
int		ft_isnt_a_wall(t_cub3d *cub, char c);
void	ft_calculate_and_move_to_pos(t_cub3d **cub, char c);
void	ft_move_player(t_cub3d **cub, char c);
void	ft_calculate_and_move_to_pos_two(t_cub3d **cub, char c);

// ft_sipmle_position_calc.c
void	ft_simple_pos_calc(t_cub3d **cub, char c);
void	ft_simple_pos_calc_backward(t_cub3d **cub, char c);

// ft_isnt_a_wall_sides.c
int		ft_check_up_and_update(t_cub3d *cub, char c);
int		ft_check_down_and_update(t_cub3d *cub, char c);
int		ft_check_left_and_update(t_cub3d *cub, char c);
int		ft_check_right_and_update(t_cub3d *cub, char c);

// ft_simple_position_calc_sides.c
int		ft_isnt_a_wall_sides(t_cub3d *cub, char c, int sides_angle);
int		ft_sides_position_calc(t_cub3d *cub, char c, int sides_angle);
int		ft_check_new_pos_right(t_cub3d *cub, char c, int sides_angle);
int		ft_check_new_pos_sides(t_cub3d *cub, char c, int sides_angle);
void	ft_simple_pos_calc_sides_left(t_cub3d **cub, char c, int sides_angle);
void	ft_simple_pos_calc_sides(t_cub3d **cub, char c, int sides_angle);

// ft_new_position_calc_sides.c
void	ft_n_pos_f_side(t_cub3d **cub, double adj, double opp, int sides_angle);
void	ft_n_pos_b_side(t_cub3d **cub, double adj, double opp, int sides_angle);

// ft_there_is_a_wall_sides.c
void	ft_vir_pos_sides(t_cub3d **cub, double adj, double opp, int s);
void	ft_virtual_position_sides(t_cub3d **cub, double adj, double opp, int s);
void	ft_move_player_pos_sides(t_cub3d **cub, int i, int j);
int		ft_there_is_a_wall_sides(t_cub3d **cub, double adj, double opp, int s);

// ft_there_is_a_wall_in_my_way.c
int		ft_check_cell_content(t_cub3d **cub);
void	ft_for_vir_pos(t_cub3d **cub, double adj, double opp, int sides_angle);
void	ft_back_vir_pos(t_cub3d **cub, double adj, double opp, int sides_angle);
int		ft_there_is_a_wall_in_my_way(t_cub3d **cub, int sides_angle, char c);

// ft_corner.c
int		ft_left_under(t_cub3d **cub, int i, int j);
int		ft_left_above(t_cub3d **cub, int i, int j);
int		ft_right_above(t_cub3d **cub, int i, int j);
int		ft_left_above(t_cub3d **cub, int i, int j);
int		ft_corner(t_cub3d **cub, int angle, int i, int j);

// CONVERT 2D TO 3D
// ft_mini_map.c
void	my_img_pix_put(t_cub3d **cub, int x, int y, int color);
int		ft_wall_space_player(t_cub3d **cub, int i, int j);
void	ft_mini_map_display(t_cub3d **cub);
void	ft_display_mini_map_util(t_cub3d **cub, int index_i, int index_j);

// ft_micro_map.c
void	ft_micro_map_display(t_cub3d **cub);
void	ft_help_micro_map(t_cub3d **cub, int i, int index_i, int index_j);

// ft_event_handler.c
void	ft_display_map(char **map);
void	ft_help_handling(t_cub3d **cub);
int		ft_handle_mouse(int x, int y, void **cub);
int		ft_handle_keys(int key, t_cub3d **cub);

// ft_display.c
void	ft_screan_display(t_cub3d *cub, int i, int j);
int		get_color(t_cub3d *cub, int x, int y, int index);
void	ft_help_display(int i, int j, t_cub3d *cub, int mid);
void	img_pix_put(t_cub3d *cub, int x, int y, int color);

// RAY CASTING
// ft_triangle_calculation.c
double	ft_calc_hypotenus(double angle, double adj);
double	ft_calc_opposite(double angle, double hyp);
double	ft_calc_adjacent(double angle, double hyp);
void	ft_real_distance(t_cub3d **cub, int turn, double hyp);

// ft_get_color.c
int		ft_chose_color_number(double closest[]);
int		ft_chose_color(t_cub3d **cub, int turn);
int		ft_previews_cell(t_cub3d **cub, int hyp, int i, int j);
void	ft_adjust_clr(t_cub3d **cub, int turn, int i, int j);
int		ft_clc_hyp(t_cub3d **cub, double opp, double adj, int flag);

// ft_ray_casting.c
int		ft_is_ray_hit_the_wall(t_cub3d **cub, int hyp);
void	ft_virtual_pos_of_ray_two(t_cub3d **cub, int turn, double adj);
void	ft_virtual_pos_of_ray(t_cub3d **cub, int turn, double adj, double opp);
void	ft_get_length_of_ray(t_cub3d **cub);
void	ft_ray_casting(t_cub3d **cub);

// cub3d.c
void	ft_cub3d(t_cub3d **cub);
int		ft_close_win(t_cub3d **cub);

#endif
