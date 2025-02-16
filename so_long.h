/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:27:49 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 14:27:53 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx/mlx.h"
# include <fcntl.h>

typedef struct s_struct
{
	void	*mlx_init;
	void	*mlx_window;
	char	*map;
	char	**map2d;
	char	**tmap2d;
	void	*wall;
	void	*character;
	void	*collectible;
	void	*door;
	void	*road;
	int		row;
	int		column;
	int		player;
	int		coin;
	int		exit;
	int		step;
	int		score;
	int		plrx;
	int		plry;
	int		exitx;
	int		exity;
}	t_struct;
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	is_ber(char *argv1);
void	error_message(char *message);
void	map_reader(t_struct *lc, char *str);
int		exit_func(void);
void	wall_control(t_struct *lc);
void	cpe_counter(t_struct *lc);
void	is_space(t_struct *lc);
void	is_missing(t_struct *lc);
void	is_any_char(t_struct *lc);
void	player_loc(t_struct *lc);
void	exit_loc(t_struct *lc);
void	is_accesible_map(t_struct *lc, int y, int x);
void	have_coin(t_struct *lc);
void	exit_reach(t_struct *lc);
void	put_image(t_struct *lc);
void	put_screen(t_struct *lc, int x, int y, int i);
int		exit_func(void);
int		key_target(int key_code, t_struct *lc);

#endif