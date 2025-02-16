/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:31 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 14:28:32 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpe_counter(t_struct *lc)
{
	int	i;

	lc->player = 0;
	lc->coin = 0;
	lc->score = 0;
	lc->exit = 0;
	lc->step = 0;
	i = 0;
	while (lc->map[i])
	{
		if (lc->map[i] == 'P')
			lc->player++;
		if (lc->map[i] == 'E')
			lc->exit++;
		if (lc->map[i] == 'C')
			lc->coin++;
		i++;
	}
	if (lc->player != 1 || lc->exit != 1 || lc->coin == 0)
		error_message("There is a problem with the number of C,P or E");
}

void	is_ber(char *argv1)
{
	int	i;

	i = 0;
	while (argv1[i])
		i++;
	i--;
	if (argv1[i] != 'r' || argv1[i - 1] != 'e'
		|| argv1[i - 2] != 'b' || argv1[i - 3] != '.')
		error_message("the map's name is not .ber extantion");
}

void	is_any_char(t_struct *lc)
{
	int	i;
	int	j;

	i = 0;
	while (lc->map2d[i])
	{
		j = 0;
		while (lc->map2d[i][j])
		{
			if (lc->map2d[i][j] != 'P' && lc->map2d[i][j] != 'E'
				&& lc->map2d[i][j] != 'C' && lc->map2d[i][j] != '1'
				&& lc->map2d[i][j] != '0')
			{
				error_message("there are/(is an) undefined character/s.");
			}
			j++;
		}
		i++;
	}
}
