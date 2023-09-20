/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:18:19 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/07 15:25:18 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int key, t_data *data)
{
	if (key == XK_Escape)
		end_game(data);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		moves(data, key);
	else
		return (-1);
	return (0);
}

int	valid_map(t_data *data, t_info *info, char *file)
{
	info_init(info);
	data_init(data);
	height_y(file, data);
	if (width_x(file, data, 0) == -1)
		return (err_pick('r', data->fd));
	if (checker(info, data) == -1)
		return (-1);
	free_map(data->map_dup, data->y);
	if (width_x(file, data, 0) == -1)
		return (err_pick('r', data->fd));
	return (0);
}

int	map_file(t_data *data, char *file_type)
{
	int	i;

	data->fd = open(file_type, O_RDONLY);
	i = (int)ft_strlen(file_type) - 1;
	while (file_type[i] != '.')
		i--;
	if (ft_strncmp(file_type + i, ".ber", 5) != 0)
		return (err_pick('f', data->fd));
	if (data->fd < 0)
		return (err_pick('/', data->fd));
	close(data->fd);
	return (0);
}

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (i <= size)
	{
		free(map[i]);
		i++;
	}
	free(map);
}
