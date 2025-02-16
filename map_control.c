/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:27:57 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 14:27:59 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_loc(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (lc->map2d[i])
	{
		j = 0;
		while (lc->map2d[i][j])
		{
			if (lc->map2d[i][j] == 'P')
			{
				lc->plrx = j;
				lc->plry = i;
				break ;
			}
			j++;
		}
		i++;
	}
	lc->tmap2d = ft_split(lc->map, '\n');
	is_accesible_map(lc, lc->plry, lc->plrx);
}

void	is_accesible_map(t_struct *lc, int y, int x)
{
	if (lc->tmap2d[y][x + 1] == '0' || lc->tmap2d[y][x + 1] == 'C'
		|| lc->tmap2d[y][x + 1] == 'P')
	{
		lc->tmap2d[y][x + 1] = '.';
		is_accesible_map(lc, y, x + 1);
	}
	if (lc->tmap2d[y][x - 1] == '0' || lc->tmap2d[y][x - 1] == 'C'
		|| lc->tmap2d[y][x - 1] == 'P')
	{
		lc->tmap2d[y][x - 1] = '.';
		is_accesible_map(lc, y, x - 1);
	}
	if (lc->tmap2d[y + 1][x] == '0' || lc->tmap2d[y + 1][x] == 'C'
		|| lc->tmap2d[y + 1][x] == 'P')
	{
		lc->tmap2d[y + 1][x] = '.';
		is_accesible_map(lc, y + 1, x);
	}
	if (lc->tmap2d[y - 1][x] == '0' || lc->tmap2d[y - 1][x] == 'C'
		|| lc->tmap2d[y - 1][x] == 'P')
	{
		lc->tmap2d[y - 1][x] = '.';
		is_accesible_map(lc, y - 1, x);
	}
}

void	exit_loc(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (lc->map2d[i])
	{
		j = 0;
		while (lc->map2d[i][j])
		{
			if (lc->map2d[i][j] == 'E')
			{
				lc->exitx = j;
				lc->exity = i;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	have_coin(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (lc->tmap2d[i])
	{
		j = 0;
		while (lc->tmap2d[i][j])
		{
			if (lc->tmap2d[i][j] == 'C')
				error_message("The player cant finish the game");
			j++;
		}
		i++;
	}
}

void	exit_reach(t_struct *lc)
{
	if (lc->tmap2d[lc->exity][lc->exitx + 1] == '.')
		return ;
	else if (lc->tmap2d[lc->exity][lc->exitx - 1] == '.')
		return ;
	else if (lc->tmap2d[lc->exity + 1][lc->exitx] == '.')
		return ;
	else if (lc->tmap2d[lc->exity - 1][lc->exitx] == '.')
		return ;
	else
		error_message("The player cant finish the game");
}
