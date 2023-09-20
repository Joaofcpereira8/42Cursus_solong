/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:50:27 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/03 12:50:27 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_print(t_info *info, t_data *data)
{
	if (info->trig == -1)
		return (msg_error('w'));
	if (info->char_trig == -1)
		return (msg_error('l'));
	if (info->cltb_av < 1)
		return (msg_error('c'));
	cltb_fill(info, data, data->plr_x, data->plr_y);
	floodfill(data->map_dup, info, data->plr_x, data->plr_y);
	data->ex_x = info->ex_x;
	data->ex_y = info->ex_y;
	if (info->plr != 1)
		return (msg_error('p'));
	if (info->cltb_av != info->cltb_ch)
		return (msg_error('C'));
	if (info->ext_av != 1)
		return (msg_error('e'));
	if (info->ext_av != info->ext_ch)
		return (msg_error('E'));
	return (0);
}

int	err_pick(char type, int i)
{
	if (type == 'f')
		ft_putstr_fd("Error\nMap format is wrong. Use [path]/[mapname].ber\n", 2);
	else if (type == 'r')
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
	else if (type == '/')
	{
		ft_putstr_fd("Error\nFile not found. Use [path]/[mapname].ber\n", 2);
		close(i);
	}
	exit(0);
}

int	msg_error(char error)
{
	if (error == 'p')
		ft_putstr_fd("Error\nNumber of player should be 1\n", 2);
	else if (error == 'e')
		ft_putstr_fd("Error\nNumber of exits should be 1\n", 2);
	else if (error == 'c')
		ft_putstr_fd("Error\nThere should be at least 1 collectible\n", 2);
	else if (error == 'i')
		ft_putstr_fd("Error\nUnusable map\n", 2);
	else if (error == 'w')
		ft_putstr_fd("Error\nMap does not have boundaries\n", 2);
	else if (error == 'r')
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
	else if (error == 'l')
		ft_putstr_fd("Error\nThere is an invalid character\n", 2);
	else if (error == 'E')
		ft_putstr_fd("Error\nExit is unreachable\n", 2);
	else if (error == 'C')
		ft_putstr_fd("Error\nAt least 1 of the collectibles is unreachable\n", 2);
	return (-1);
}

int	args_error(int n)
{
	ft_putstr_fd("Invalid arguments! Use ./so_long maps/[usable_map]", 2);
	return (n);
}
