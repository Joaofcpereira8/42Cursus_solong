/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:23:22 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/03 19:23:22 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_paste(t_data *data)
{
	int	x;
	int	y;

	img_inits(data);
	y = 0;
	while (y <= data->y)
	{
		x = 0;
		while (x < data->x)
		{
			img_select(data, x, y);
			x++;
		}
		y++;
	}
}

void	img_inits(t_data *data)
{
	data->floor_img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR,
			&data->width, &data->height);
	data->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, WALL,
			&data->width, &data->height);
	data->cltb_img = mlx_xpm_file_to_image(data->mlx_ptr, COLLECT,
			&data->width, &data->height);
	data->exit_img = malloc(sizeof (void *) * 2);
	data->exit_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, EXIT_CLOSED,
			&data->width, &data->height);
	data->exit_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->width, &data->height);
	plr_inits(data);
}

void	plr_inits(t_data *data)
{
	data->playerw_img = malloc(sizeof (void *) * 2);
	data->playerw_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERW,
			&data->width, &data->height);
	data->playerw_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERW_W,
			&data->width, &data->height);
	data->players_img = malloc(sizeof (void *) * 2);
	data->players_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERS,
			&data->width, &data->height);
	data->players_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERS_W,
			&data->width, &data->height);
	data->playera_img = malloc(sizeof (void *) * 2);
	data->playera_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERA,
			&data->width, &data->height);
	data->playera_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERA_W,
			&data->width, &data->height);
	data->playerd_img = malloc(sizeof (void *) * 2);
	data->playerd_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERD,
			&data->width, &data->height);
	data->playerd_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERD_W,
			&data->width, &data->height);
}

void	img_select(t_data *data, int x, int y)
{
	if (data->map_dup[y][x] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, (x * 50), (y * 50));
	else if (data->map_dup[y][x] == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit_img[0], (x * 50), (y * 50));
	else if (data->map_dup[y][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, (x * 50), (y * 50));
	else if (data->map_dup[y][x] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->cltb_img, (x * 50), (y * 50));
	else if (data->map_dup[y][x] == 'P')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->players_img[0], (x * 50), (y * 50));
}

int	end_game(t_data *data)
{
	free_map(data->map_dup, data->y);
	mlx_destroy_image(data->mlx_ptr, data->wall_img);
	mlx_destroy_image(data->mlx_ptr, data->floor_img);
	mlx_destroy_image(data->mlx_ptr, data->cltb_img);
	mlx_destroy_image(data->mlx_ptr, data->exit_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->exit_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->playerw_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->playerw_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->playera_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->playera_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->playerd_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->playerd_img[1]);
	mlx_destroy_image(data->mlx_ptr, data->players_img[0]);
	mlx_destroy_image(data->mlx_ptr, data->players_img[1]);
	free(data->playerw_img);
	free(data->players_img);
	free(data->playera_img);
	free(data->playerd_img);
	free(data->exit_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

//fazer mlx_destroy_display antes de fazer free ao mlx_ptr porque precisamos de
//aceder ao mlx_ptr para recuperar a variavel da display, para nao haver leaks