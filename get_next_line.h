/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftan <ftan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:14:00 by ftan              #+#    #+#             */
/*   Updated: 2022/05/25 22:19:38 by ftan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *str);
char	*ft_strchr(const char *s, int i);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
#endif