/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:24 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 14:28:25 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_struct *lc)
{
	int		img_w;
	int		img_h;
	char	*str;

	str = "xpms/wall.xpm";
	lc->wall = mlx_xpm_file_to_image(lc->mlx_init, str, &img_w, &img_h);
	str = "xpms/tank3.0.xpm";
	lc->character = mlx_xpm_file_to_image(lc->mlx_init, str, &img_w, &img_h);
	str = "xpms/bullet.xpm";
	lc->collectible = mlx_xpm_file_to_image(lc->mlx_init, str, &img_w, &img_h);
	str = "xpms/finish.xpm";
	lc->door = mlx_xpm_file_to_image(lc->mlx_init, str, &img_w, &img_h);
	if (!lc->wall || !lc->character || !lc->collectible || !lc->door)
		error_message("Failed to upload the image");
}

static void	print_string(t_struct *lc)
{
	char	*str;

	str = ft_itoa(lc->step);
	mlx_string_put(lc->mlx_init, lc->mlx_window, 40, 50, 0x00FF00,
		"STEP: ");
	mlx_string_put(lc->mlx_init, lc->mlx_window, 80, 50, 0x00FF00, str);
	free(str);
}

void	put_screen_options(t_struct *lc, int *i, int *x, int *y)
{
	if (lc->map[*i] == 'C')
		mlx_put_image_to_window(lc->mlx_init, lc->mlx_window, lc->collectible,
			*x, *y);
	if (lc->map[*i] == 'E')
		mlx_put_image_to_window(lc->mlx_init, lc->mlx_window, lc->door,
			*x, *y);
	if (lc->map[*i] == '\n')
	{
		(*x) = -64;
		(*y) += 64;
	}
}

void	put_screen(t_struct *lc, int x, int y, int i)
{
	while (lc->map[i])
	{
		if (lc->map[i] == '1')
			mlx_put_image_to_window(lc->mlx_init, lc->mlx_window,
				lc->wall, x, y);
		if (lc->map[i] == 'P')
		{
			mlx_put_image_to_window(lc->mlx_init, lc->mlx_window,
				lc->character, x, y);
			lc->player = i;
		}
		put_screen_options(lc, &i, &x, &y);
		x += 64;
		i++;
		print_string(lc);
	}
}
