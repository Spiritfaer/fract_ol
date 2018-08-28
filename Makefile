# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: istalevs <istalevs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/08 16:11:41 by istalevs          #+#    #+#              #
#    Updated: 2018/05/07 23:07:58 by istalevs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

# src / obj files
SRC		= main.c \
		new.c \
		render.c \
		set.c \
		color.c \
		drawing.c \
		event.c \
		fractal.c \
		interface.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

# mlx library
MLX_LNK	= -l mlx -framework OpenGL -framework AppKit

# ft library
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# directories
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) -lm -o $(NAME)
	@say -v Karen "You're the best! All is done!"
	@echo "You're the best! All is done!"

clean:
	@rm -rf $(OBJDIR)
	@make -C $(FT) clean
	@say -v Karen "Objects files was deleted"
	@echo "Objects files was deleted"

fclean: clean
	@rm -fr .DS*
	@rm -rf $(NAME)
	@make -C $(FT) fclean
	@say -v Karen "All is clear!"
	@echo "All is clear!"

re: fclean all
