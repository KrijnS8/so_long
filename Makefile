# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kschelvi <kschelvi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/01 13:23:25 by kschelvi      #+#    #+#                  #
#    Updated: 2023/11/14 16:13:36 by kschelvi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

MLX_PATH = ./minilibx-linux

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRC	=	src/collectible.c \
		src/error.c \
		src/linked_list.c \
		src/main.c \
		src/map_utils.c \
		src/map.c \
		src/render_utils.c \
		src/render.c \
		src/system_utils.c \
		src/system.c \
		src/texture_utils.c \
		src/texture.c

SRC_BONUS	=	src_bonus/collectible_bonus.c \
				src_bonus/error_bonus.c \
				src_bonus/linked_list_bonus.c \
				src_bonus/main_bonus.c \
				src_bonus/map_utils_bonus.c \
				src_bonus/map_bonus.c \
				src_bonus/render_utils_bonus.c \
				src_bonus/render_bonus.c \
				src_bonus/system_utils_bonus.c \
				src_bonus/system_bonus.c \
				src_bonus/texture_utils_bonus.c \
				src_bonus/texture_bonus.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) minilibx $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)
	@echo "\n$(GREEN)--------------- COMPILATION COMPLETE ---------------\n$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) minilibx $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "\n$(GREEN)--------------- COMPILATION COMPLETE ---------------\n$(RESET)"

minilibx:
	@if [ -d "minilibx-linux" ]; then \
		echo "\n$(RED)minilibx-linux already exists$(RESET)"; \
	else \
		echo "\n$(GREEN)--------------- CLONING MINILIBX-LINUX ---------------$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	@echo "\n$(GREEN)--------------- COMPILING MINILIBX-LINUX ---------------$(RESET)"
	@cd $(MLX_PATH) && $(MAKE)

$(LIBFT):
	@if [ -d "libft" ]; then \
		echo "\n$(RED)libft already exists$(RESET)"; \
	else \
		echo "\n$(GREEN)--------------- CLONING LIBFT ---------------$(RESET)"; \
		git clone https://github.com/KrijnS8/libft.git; \
	fi
	@echo "\n$(GREEN)--------------- COMPILING LIBFT ---------------$(RESET)"
	@cd $(LIBFT_PATH) && $(MAKE)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS);
	@if [ -d "libft" ]; then \
		cd $(LIBFT_PATH) && $(MAKE) clean; \
	fi

cleanlib:
	@$(RM) -r $(LIBFT_PATH) $(MLX_PATH)

fclean:
	@$(RM) $(NAME) $(OBJ) $(NAME_BONUS) $(OBJ_BONUS)
	@if [ -d "libft" ]; then \
		cd $(LIBFT_PATH) && $(MAKE) fclean; \
	fi
	@if [ -d "minilibx-linux" ]; then \
		cd $(MLX_PATH) && $(MAKE) clean; \
	fi

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus minilibx clean cleanlib fclean re rebonus