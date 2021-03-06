NAME = fdf

SRC_DIR = ./src/
SRC_FILES = draw_line.c draw_map.c hooks.c main.c map.c mlx.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

INC_DIR = ./includes/
INCLUDES = -I$(INC_DIR) $(FT_INC) $(MLX_INC)

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc
CFLAGS = -g -O0 -Wall -Wextra -Werror

LIBS = $(MLX_LNK) $(FT_LNK) -lm

MLX		= ./minilibx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I $(MLX)
MLX_LNK	= -L minilibx -l mlx -framework OpenGL -framework AppKit

FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft/includes/
FT_LNK	= -L libft -l ft

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(FT_LIB):
	@if [[ ! -e $(FT_LIB) ]]; then make -C $(FT); fi

$(MLX_LIB):
	@if [[ ! -e $(MLX_LIB) ]]; then make -C $(MLX) &> /dev/null; fi

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean:
	@make -C $(FT) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(FT) fclean
	@make -C $(MLX) clean &> /dev/null
	@rm -rf $(NAME)

re: fclean all

req: clean
	@rm -rf $(NAME)
	@make all
	@make clean

.PHONY: all obj $(NAME) clean fclean re req
