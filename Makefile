NAME = fdf

SRCS_PATH = ./src/
SRCS_FILES = fdf.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJECTS_PATH = ./obj/
OBJECTS_FILES = $(SRCS_FILES:.c = .o)
OBJECTS = $(addprefix $(OBJECTS_PATH), $(OBJECTS_FILES))

CC = gcc

INCLUDES = -I./includes/ -I$(LIBFTDIR)
HEADER = ./includes/fdf.h

LIBFTDIR = ./libft/
LIBFTNAME = libft.a
LIB = $(LIBFTDIR)$(LIBFTNAME)

MLX = -L/usr/local/lib -I/usr/local/include -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJECTS) $(HEADER)
	if [[ ! -e /libft/libft.a ]];
		@make -C $(LIBFTDIR) &> /dev/null
	fi
	@$(CC) $(OBJECTS) $(MLX) $(LIB) -o $(NAME) &> /dev/null

$(OBJECTS_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir $(OBJECTS_PATH) &> /dev/null
	@$(CC) $(INCLUDES) -c $< -o $@ &> /dev/null

clean:
	@make -C $(LIB_PATH) clean &> /dev/null
	@rm -rfv $(OBJECTS) &> /dev/null

fclean: clean
	@make -C $(LIB_PATH) fclean &> /dev/null
	@rm -rfv $(NAME) &> /dev/null

re: fclean all
