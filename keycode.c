/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:07 by hbay              #+#    #+#             */
/*   Updated: 2023/10/02 14:56:30 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	finish_control(t_struct *lc)
{
	if (lc->score == lc->coin)
	{
		mlx_destroy_window(lc->mlx_init, lc->mlx_window);
		ft_printf("%d\n", ++lc-> step);
		ft_printf("\033[1;32mYOU WONN!!!\033[0;39m\n");
		exit(0);
	}
	return (0);
}

static int	key_control(t_struct *lc, int pos)
{
	if (lc->map[pos] == 'C')
		lc->score++;
	if (lc->map[pos] == 'E')
	{
		finish_control(lc);
		return (0);
	}
	lc->map[pos] = 'P';
	lc->map[lc->player] = '0';
	ft_printf("%d\n", ++lc->step);
	return (1);
}

void	help_func(t_struct *lc, int key_code)
{
	if ((key_code == 13 || key_code == 126) && (lc->map[lc->player
				- lc->column - 1] != '1'))
		key_control(lc, lc->player - lc->column - 1);
	else if ((key_code == 0 || key_code == 123) && lc->map[lc->player
			- 1] != '1')
		key_control(lc, lc->player - 1);
	else if ((key_code == 2 || key_code == 124) && lc->map[lc->player
			+ 1] != '1')
		key_control(lc, lc->player + 1);
	else if ((key_code == 1 || key_code == 125) && (lc->map[lc->player
				+ lc->column + 1] != '1'))
		key_control(lc, lc->player + lc->column + 1);
}

int	key_target(int key_code, t_struct *lc)
{
	static int	flag = 0;

	if (key_code == 53 || key_code == 12)
	{
		mlx_destroy_window(lc->mlx_init, lc->mlx_window);
		exit_func();
	}
	if (flag)
		help_func(lc, key_code);
	flag = 1;
	mlx_clear_window(lc->mlx_init, lc->mlx_window);
	put_screen(lc, 0, 0, 0);
	return (0);
}
