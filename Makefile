# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zezzine <zezzine@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/12 10:26:35 by tel-bouh          #+#    #+#              #
#    Updated: 2022/08/10 19:10:37 by tel-bouh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRCS = ./cub3d.c ./parse_map/ft_parse_map.c ./parse_map/ft_check_elems.c ./parse_map/ft_check_elems_util.c \
	   ./parse_map/ft_check_map.c ./parse_map/ft_check_map_again.c ./parse_map/ft_check_map_again_util.c \
	   ./parse_map/ft_check_map_util.c ./parse_map/ft_split.c ./parse_map/ft_strdup.c ./parse_map/ft_strcmp.c \
	   ./parse_map/ft_strlen_tab.c ./parse_map/ft_free.c ./parse_map/ft_atoi.c ./parse_map/ft_split_quote.c \
	   ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	   ./init/ft_initialize_struct.c ./init/ft_initialize_struct_util.c ./init/ft_strncmp.c \
	   ./convert_2d_to_3d/ft_display.c ./convert_2d_to_3d/ft_event_handler.c ./convert_2d_to_3d/ft_mini_map.c  ./convert_2d_to_3d/ft_micro_map.c\
	   ./move_player/ft_isnt_a_wall.c ./move_player/ft_there_is_a_wall.c ./move_player/ft_new_position_calc.c \
	   ./move_player/ft_straight_move.c  ./move_player/ft_move_player.c ./move_player/ft_simple_position_calc.c \
	   ./move_player/ft_corner.c ./move_player/ft_new_position_calc_sides.c ./move_player/ft_there_is_a_wall_sides.c \
	   ./move_player/ft_isnt_a_wall_sides.c ./move_player/ft_simple_position_calc_sides.c \
	   ./move_player/ft_there_is_a_wall_in_my_way.c \
	   ./ray_casting/ft_ray_casting.c ./ray_casting/ft_triangle_calculation.c ./ray_casting/ft_get_color.c \


OBJS = $(SRCS:.c=.o)

FLAGS = #-Wall -Wextra -Werror

MLX_FLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL  -framework AppKit #if you get error if mlx.h chagne X11 with local

MLX_HEADER = /usr/local/include #if you get error if mlx.h chagne X11 with local

CC = cc

all : $(NAME)
	
$(NAME) :
	$(CC) $(FLAGS) -I $(MLX_HEADER) $(MLX_FLAGS) $(SRCS) -o $(NAME)

#.c:.o :
#	$(CC) -c $(FLAGS) $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
