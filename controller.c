/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:28 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 15:45:37 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_control(t_struct *lc)
{
	int	i;

	i = 0;
	while (i < lc->column)
	{
		if (lc->map2d[0][i] != '1' || lc->map2d[lc->row - 1][i] != '1')
			error_message("Wall error");
		i++;
	}
	i = 0;
	while (i < lc->row)
	{
		if (lc->map2d[i][0] != '1' || lc->map2d[i][lc->column - 1] != '1')
			error_message("Wall error");
		i++;
	}
}

void	is_space(t_struct *lc)
{
	int	i;

	i = 0;
	while (lc->map[i])
	{
		if (lc->map[i] == '\n')
		{
			if (i != 0 && (lc->map[i - 1] != '1' || lc->map[i + 1] != '1'))
				error_message("There is a space on the map");
		}
		i++;
	}
}

void	is_missing(t_struct *lc)
{
	int	i;
	int	a;

	i = 0;
	while (lc->map2d[i])
	{
		a = 0;
		while (lc->map2d[i][a])
			a++;
		if (a != lc->column)
			error_message("There is a problem with the map");
		i++;
	}
}
