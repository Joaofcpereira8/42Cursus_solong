/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:06:22 by jofilipe          #+#    #+#             */
/*   Updated: 2023/06/29 19:03:53 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	height_y(char *file, t_data *data)
{
	char	*line;
	char	*temp;
	char	*cut;

	data->fd = open(file, O_RDONLY);
	temp = get_next_line(data->fd);
	close (data->fd);
	cut = ft_strtrim(temp, "\n");
	free (temp);
	data->x = (int)ft_strlen(cut);
	free(cut);
	if (data->x == 0)
		err_pick('r', data->fd);
	data->fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->y++;
		free (line);
	}
	data->y--;
	close (data->fd);
	free (line);
}

int	width_x(char *file, t_data *data, int y)
{
	int		len;
	char	*temp;

	data->map_dup = ft_calloc(data->y + 1, sizeof(char *));
	data->fd = open(file, O_RDONLY);
	while (y <= data->y)
	{
		temp = get_next_line(data->fd);
		data->map_dup[y] = ft_strtrim(temp, "\n");
		free(temp);
		if (!data->map_dup[y])
			break ;
		len = (int)ft_strlen(data->map_dup[y]);
		if (data->x != len || data->x <= 0)
		{
			free_map(data->map_dup, y + 1);
			err_pick('r', data->fd);
		}
		y++;
	}
	return (close(data->fd));
}

void	floodfill(char **map_dup, t_info *info, int x, int y)
{
	if (map_dup[y][x] == '1' || map_dup[y][x] == 'X'
		|| !map_dup[y][x])
		return ;
	else
	{
		if (map_dup[y][x] == 'E' && info->cltb_ch == info->cltb_av)
			exit_checker(info, x, y);
		map_dup[y][x] = 'X';
		floodfill(map_dup, info, (x + 1), y);
		floodfill(map_dup, info, (x - 1), y);
		floodfill(map_dup, info, x, (y + 1));
		floodfill(map_dup, info, x, (y - 1));
	}
}

void	cltb_fill(t_info *info, t_data *data, int x, int y)
{
	if (data->map_dup[y][x] == '1'
		|| data->map_dup[y][x] == '-' || data->map_dup[y][x] == 'E'
		|| data->map_dup[y][x] == '/' || !data->map_dup[y][x])
		return ;
	else
	{
		if (data->map_dup[y][x] == 'C')
			info->cltb_ch++;
		data->map_dup[y][x] = '/';
		cltb_fill(info, data, x + 1, y);
		cltb_fill(info, data, x - 1, y);
		cltb_fill(info, data, x, y + 1);
		cltb_fill(info, data, x, y - 1);
	}
}
