NAME = fdf

SRC_DIR = ./src/
SRC_FILES = main.c drawline.c intcolor.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

INC_DIR = ./includes/
INCLUDES = -I$(INC_DIR) $(FT_INC) $(MLX_INC)

OBJ_DIR = ./obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

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
	mkdir -p $(OBJ_DIR) &> /dev/null

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ #&> /dev/null

$(FT_LIB):
	if [[ ! -e $(FT_LIB) ]]; then make -C $(FT); fi #&> /dev/null

$(MLX_LIB):
	if [[ ! -e $(MLX_LIB) ]]; then make -C $(MLX); fi #&> /dev/null

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME) #&> /dev/null

clean:
	make -C $(FT) clean #&> /dev/null
	rm -rfv $(OBJS) #&> /dev/null

fclean: clean
	make -C $(FT) fclean #&> /dev/null
	make -C $(MLX) clean #&> /dev/null
	rm -rf $(NAME) #&> /dev/null

re: fclean all

req: clean
	rm -rf $(NAME) #&> /dev/null
	make all #&> /dev/null
	make clean

.PHONY: all obj $(NAME) clean fclean re req
