/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:19:19 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/07 15:25:30 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include <fcntl.h>

# define WALL "./images/WALL1.xpm"
# define FLOOR "./images/FLOOR1.xpm"
# define COLLECT "./images/POKEBALL.xpm"

//-----exit-----//
# define EXIT "./images/EXIT.xpm"
# define EXIT_CLOSED "./images/EXIT_CLOSED.xpm"

//-----up-----//
# define PLAYERW "./images/PLAYER_S_W.xpm"
# define PLAYERW_W "./images/PLAYER_W_W.xpm"

//-----down-----//
# define PLAYERS "./images/PLAYER_S_S.xpm"
# define PLAYERS_W "./images/PLAYER_W_S.xpm"

//-----left-----//
# define PLAYERA "./images/PLAYER_S_A.xpm"
# define PLAYERA_W "./images/PLAYER_W_A.xpm"

//-----right-----//
# define PLAYERD "./images/PLAYER_S_D.xpm"
# define PLAYERD_W "./images/PLAYER_W_D.xpm"

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		plr_x;
	int		plr_y;
	int		ex_x;
	int		ex_y;
	int		fd;
	int		width;
	int		height;
	int		collected;
	int		to_collect;
	int		moves;
	char	direction;
	char	**map_dup;
	void	*wall_img;
	void	*floor_img;
	void	**cltb_img;
	void	**exit_img;
	void	**playerw_img;
	void	**playera_img;
	void	**players_img;
	void	**playerd_img;
}				t_data;

typedef struct s_info
{
	int	plr;
	int	enmy;
	int	floor;
	int	ex_x;
	int	ex_y;
	int	cltb_av;
	int	cltb_ch;
	int	wall;
	int	ext_av;
	int	ext_ch;
	int	trig;
	int	char_trig;
}				t_info;

//-------utils.c-------//
int		handle_input(int key, t_data *data);
int		valid_map(t_data *data, t_info *info, char *file);
int		map_file(t_data *data, char *file_type);
void	free_map(char **map, int size);

//-------utils2.c-------//
void	height_y(char *file, t_data *data);
int		width_x(char *file, t_data *data, int y);
void	floodfill(char **map_dup, t_info *info, int x, int y);
void	cltb_fill(t_info *info, t_data *data, int x, int y);

//-------error.c-------//
int		error_print(t_info *info, t_data *data);
int		err_pick(char type, int i);
int		msg_error(char error);
int		args_error(int n);

//-------checker.c-------//
void	player_checker(t_info *info, t_data *data, int x, int y);
void	wall_checker(t_info *info, t_data *data, int x, int y);
void	char_checker(t_info *info, char c);
int		checker(t_info *info, t_data *data);
void	exit_checker(t_info *info, int x, int y);

//-------images.c-------//
void	img_paste(t_data *data);
void	img_inits(t_data *data);
void	plr_inits(t_data *data);
void	img_select(t_data *data, int x, int y);
int		end_game(t_data *data);

//-------player_picks.c-------//
void	plr_picks_up(t_data *data);
void	plr_picks_down(t_data *data);
void	plr_picks_left(t_data *data);
void	plr_picks_right(t_data *data);

//-------sprites.c-------//
void	moves(t_data *data, int key);
void	moves2(t_data *data, int key);
int		check_mov(t_data *data, int x, int y);
int		update(t_data *data);
void	fps(t_data *data, int x, int y);

//-------inits.c-------//
void	data_init(t_data *data);
void	info_init(t_info *info);

#endif
