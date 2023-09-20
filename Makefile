# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jofilipe <jofilipe@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/18 15:33:42 by jofilipe          #+#    #+#              #
#    Updated: 2023/05/18 15:33:44 by jofilipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror -g
LIBXFLAGS	= -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lm
LIBFTFLAGS	= -L ./libft -lft

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes
SRCS		= mandatory
SRCS_BONUS	= bonus
LIBFT		= libft
LIBX 		= minilibx-linux

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
SRC				= main.c utils.c utils2.c checker.c inits.c error.c images.c player_picks.c sprites.c
OBJS 			:= $(SRC:.c=.o)
BONUS			= main_bonus.c utils_bonus.c utils2_bonus.c checker_bonus.c inits_bonus.c error_bonus.c images_bonus.c player_picks_bonus.c sprites_bonus.c enemy_img_bonus.c enemy_pick_bonus.c enmy_mov_bonus.c
OBJS_BONUS		:= $(BONUS:.c=.o)
NAME			= so_long
NAME_BONUS		= so_long_bonus
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))


#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	make $(MKFLAGS) -C $(LIBFT)
	make all -C $(LIBX)

	$(CC) $(CFLAGS) $(TARGET) $(LIBFTFLAGS) $(LIBXFLAGS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	make clean -C $(LIBX)
	$(RM) $(TARGET) $(TARGET_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

bonus: $(TARGET_BONUS)
	make -C $(LIBFT)
	make -C $(LIBX)
	$(CC) $(CFLAGS) $(TARGET_BONUS) $(LIBFTFLAGS) $(LIBXFLAGS) -o $(NAME_BONUS) -I $(DEPS)

debug:
	$(CC) $(CFLAGS) $(LIBXFLAGS) $(SRC)

re: fclean all