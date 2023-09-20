/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jofilipe <jofilipe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:45:40 by jofilipe          #+#    #+#             */
/*   Updated: 2023/07/07 15:20:26 by jofilipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_info	info;

	if (argc == 2)
	{
		if (map_file(&data, argv[1]) == -1)
			return (-1);
		if (valid_map(&data, &info, argv[1]) == -1)
		{
			free_map(data.map_dup, data.y);
			return (-1);
		}
		data.mlx_ptr = mlx_init();
		data.win_ptr = mlx_new_window(data.mlx_ptr, (data.x * 50),
				((data.y + 1) * 50), "so_long");
		img_paste(&data);
		mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
			&end_game, &data);
		mlx_key_hook(data.win_ptr, &handle_input, &data);
		mlx_loop_hook(data.mlx_ptr, &update, &data);
		mlx_loop(data.mlx_ptr);
		end_game(&data);
	}
	return (args_error(-1));
}
