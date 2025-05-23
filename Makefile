FLAGS = -Wall -Wextra -Werror -g

NAME = cub3D

FLAGS_LINK = -ldl -lglfw -pthread -lm

PARSER_FILES = srcs_parser/help_functions/get_next_line.c \
				srcs_parser/main.c \
				srcs_parser/pre_creating_structure/check_program_params.c \
				srcs_parser/help_functions/auxiliary1.c \
				srcs_parser/help_functions/auxiliary2.c \
				srcs_parser/help_functions/auxiliary3.c \
				srcs_parser/pre_creating_structure/storing_lines_type.c \
				srcs_parser/pre_creating_structure/line_type_decider.c \
				srcs_parser/pre_creating_structure/check_info_isvalid.c \
				srcs_parser/help_functions/ft_split.c \
				srcs_parser/creating_structure/store_final_structure.c \
				srcs_parser/creating_structure/validate_map.c

MLX = MLX42/build/libmlx42.a

EXEC_FILES = src_exec/main_exec.c \
				src_exec/player.c \
				src_exec/ray.c \
				src_exec/draw.c \
				src_exec/rotate.c \

OBJ = $(PARSER_FILES:%.c=%.o)

EXEC_OBJ = $(EXEC_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) $(EXEC_OBJ) $(MLX)
	cc $(FLAGS) $(OBJ) $(EXEC_OBJ) $(MLX) $(FLAGS_LINK) -o $(NAME)

$(MLX):
	cmake -S MLX42 -B MLX42/build
	cmake --build MLX42/build -j4

%.o: %.c
	clang -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJ) $(EXEC_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf MLX42/build
	rm -f $(MLX)

re: fclean all

.PHONY: all clean fclean re

