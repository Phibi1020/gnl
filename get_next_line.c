/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftan <ftan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:08:55 by ftan              #+#    #+#             */
/*   Updated: 2022/05/23 12:10:02 by ftan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_content (int fd, char *buf, char *stash)
{
	int	lines;
	char	*temp;

	lines = read(fd, buf, BUFFER_SIZE);
	while (lines > 0)
	{
		buf[lines] = '\0';
		if (!stash)
			stash = ft_strdup("");
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free (temp);
		if (ft_strchr (buf, '\n'))
			break;
		lines = read (fd, buf, BUFFER_SIZE);
	}
	return (stash);
}

char	*ft_sep(char *line)
{
	char	*return_line;
	size_t	count;

	count = 0;
	//count the position of eol
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0' || line[1] == '\0')
		return(0);
	//get the substring of the line bfore the newline
	return_line = ft_substr(line, count+1, ft_strlen(line) -1);
	if(*return_line == '\0')
	{
		free(return_line);
		return_line = NULL;
	}
	//append eof to line to only return the desired substring
	line[count + 1] = '\0';
	//return the position of next string to static
	return(return_line);
}

char    *get_next_line(int fd){
	char *t;
	char *buf;
	static char *stash;

	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	t = ft_read_content(fd, buf, stash);
	//free the temp string used
	free(buf);
	buf = NULL;
	if (!t)
		return NULL;
	stash = ft_sep(t);
	return (t);    
}