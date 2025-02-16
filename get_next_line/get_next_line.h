/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbay <hbay@student.42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 14:28:40 by hbay              #+#    #+#             */
/*   Updated: 2023/09/26 14:28:41 by hbay             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_read(char *str, int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *str, char *buf);
int		ft_check_nl(char *str);
char	*ft_one_line(char *str);
char	*ft_after_line(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
#endif
