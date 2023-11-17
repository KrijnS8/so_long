# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kschelvi <kschelvi@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/01 13:23:25 by kschelvi      #+#    #+#                  #
#    Updated: 2023/11/17 12:36:13 by kschelvi      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

CFLAGS=-I./src_bonus/include
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -lXext -lX11
VALGRIND_FLAGS = --leak-check=full

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
				src_bonus/texture_utils_2_bonus.c \
				src_bonus/texture_utils_bonus.c \
				src_bonus/texture_bonus.c \
				src_bonus/animation_bonus.c \
				src_bonus/player_bonus.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(LIBFT) minilibx $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)";
	@echo " _____                                                                  _____ ";
	@echo "( ___ )                                                                ( ___ )";
	@echo " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
	@echo " |   |$(RESET)                              ████                                $(GREEN)|   | ";
	@echo " |   |$(RESET)                             ░░███                                $(GREEN)|   | ";
	@echo " |   |$(RESET)    █████   ██████            ░███   ██████  ████████    ███████  $(GREEN)|   | ";
	@echo " |   |$(RESET)   ███░░   ███░░███           ░███  ███░░███░░███░░███  ███░░███  $(GREEN)|   | ";
	@echo " |   |$(RESET)  ░░█████ ░███ ░███           ░███ ░███ ░███ ░███ ░███ ░███ ░███  $(GREEN)|   | ";
	@echo " |   |$(RESET)   ░░░░███░███ ░███           ░███ ░███ ░███ ░███ ░███ ░███ ░███  $(GREEN)|   | ";
	@echo " |   |$(RESET)   ██████ ░░██████  █████████ █████░░██████  ████ █████░░███████  $(GREEN)|   | ";
	@echo " |   |$(RESET)  ░░░░░░   ░░░░░░  ░░░░░░░░░ ░░░░░  ░░░░░░  ░░░░ ░░░░░  ░░░░░███  $(GREEN)|   | ";
	@echo " |   |$(RESET)                                                        ███ ░███  $(GREEN)|   | ";
	@echo " |   |$(RESET)                                                       ░░██████   $(GREEN)|   | ";
	@echo " |   |$(RESET)                                                        ░░░░░░    $(GREEN)|   | ";
	@echo " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
	@echo "(_____)                                                                (_____)";
	@echo "$(RESET)";

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(LIBFT) minilibx $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(LIBFT) $(CFLAGS) $(MLXFLAGS) -o $(NAME_BONUS)
	@echo "$(GREEN)Compilation complete$(RESET)"

minilibx:
	@if [ -d "minilibx-linux" ]; then \
		echo "$(RED)minilibx-linux already exists$(RESET)"; \
	else \
		echo "$(GREEN)Cloning minilibx-linux...$(RESET)"; \
		git clone https://github.com/42Paris/minilibx-linux.git; \
	fi
	@echo "$(GREEN)Compiling minilibx-linux...$(RESET)"
	@cd $(MLX_PATH) && $(MAKE)

$(LIBFT):
	@if [ -d "libft" ]; then \
		echo "$(RED)libft already exists$(RESET)"; \
	else \
		echo "$(GREEN)Cloning libft...$(RESET)"; \
		git clone https://github.com/KrijnS8/libft.git; \
	fi
	@echo "$(GREEN)Compiling libft...$(RESET)"
	@cd $(LIBFT_PATH) && $(MAKE)

valgrind: all
	@valgrind $(VALGRIND_FLAGS) $(NAME) map.ber

run: all
	@if [ -e "map.ber" ]; then \
		echo "$(GREEN)STARTING SO_LONG...$(RESET)"; \
		./$(NAME) map.ber; \
		echo "$(RED)CLOSING SO_LONG...$(RESET)"; \
	else \
		echo "$(RED)NO MAP.BER FILE$(RESET)"; \
	fi

runbonus: rebonus
	@if [ -e "map.ber" ]; then \
		echo "$(GREEN)STARTING SO_LONG_BONUS...$(RESET)"; \
		./$(NAME_BONUS) map.ber; \
		echo "$(RED)CLOSING SO_LONG_BONUS...$(RESET)"; \
	else \
		echo "$(RED)NO MAP.BER FILE$(RESET)"; \
	fi

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS);
	@if [ -d "libft" ]; then \
		cd $(LIBFT_PATH) && $(MAKE) clean; \
	fi

lib: minilibx $(LIBFT)

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

.PHONY: all bonus minilibx clean lib cleanlib fclean re rebonus