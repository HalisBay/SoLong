/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:03 by hbay              #+#    #+#             */
/*   Updated: 2023/10/04 16:15:09 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_reader(t_struct *lc, char *str)
{
	int	fd;

	lc->row = 0;
	lc->column = 0;
	fd = open(str, O_RDWR);
	lc->map = get_next_line(fd);
	if (fd == -1)
		error_message("map file permission denied");
	if (!lc->map)
		error_message("empty map");
	lc->map2d = ft_split(lc->map, '\n');
	while (lc->map2d[lc->row])
	{
		lc->column = 0;
		while (lc->map2d[lc->row][lc->column])
			lc->column++;
		lc->row++;
	}
}

int	exit_func(void)
{
	exit(0);
}

int	checker(t_struct *lc, char *av)
{
	is_ber(av);
	map_reader(lc, av);
	wall_control(lc);
	cpe_counter(lc);
	is_space(lc);
	is_missing(lc);
	is_any_char(lc);
	player_loc(lc);
	exit_loc(lc);
	have_coin(lc);
	if (lc->row > 22 || lc->column > 42)
		error_message("range of the map is too large");
	return (0);
}

int	main(int ac, char **av)
{
	t_struct	*lc;

	lc = malloc(sizeof(t_struct));
	if (ac == 2)
	{
		checker(lc, av[1]);
		exit_reach(lc);
		lc->mlx_init = mlx_init();
		lc->mlx_window = mlx_new_window(lc->mlx_init, lc->column * 64,
				lc->row * 64, "./so_long");
		mlx_string_put(lc->mlx_init, lc->mlx_window, lc->column * 23,
			lc->row * 28, 0x00FF00, "PRESS A KEY TO START THE GAME!!!!");
		put_image(lc);
		mlx_hook(lc->mlx_window, 2, 0, key_target, lc);
		mlx_hook(lc->mlx_window, 17, 1L << 17, exit_func, lc);
		mlx_loop(lc->mlx_init);
	}
}
