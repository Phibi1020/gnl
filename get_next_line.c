/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftan <ftan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 21:08:55 by ftan              #+#    #+#             */
/*   Updated: 2022/05/27 20:37:28 by ftan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_content (int fd, char *buf, char *stash)
{
	int		lines;
	char	*temp;

	//get the first string of buffer size
	lines = read(fd, buf, BUFFER_SIZE);
	//if lines is not 0 means there is a string lines are the number of bytes read
	while (lines > 0)
	{
		//put eol in buffer
		buf[lines] = '\0';
		//strdup is just to malloc
		if (!stash)
			stash = ft_strdup("");
		//to join sting together 
		temp = stash;
		stash = ft_strjoin(temp, buf);
		free (temp);
		if (ft_strchr (buf, '\n'))
			break ;
		lines = read (fd, buf, BUFFER_SIZE);
	}
	return (stash);
}

char	*ft_sep(char *line)
{
	char	*return_line;
	size_t	count;

	count = 0;
	//count how many characters are there in first line; check for new line separator to stop
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	//in the case where passed line is a blank
	if (line[count] == '\0' || line[1] == '\0')
		return (0);
	//return line is actually the next line
	return_line = ft_substr(line, count + 1, ft_strlen(line) - 1);
	//if the returned line is empty then free the memory
	if (*return_line == '\0')
	{
		free (return_line);
		return_line = NULL;
	}
	//add a EOL symbol to cut desired string
	line[count + 1] = '\0'; 
	//return the next line to the static variable
	return (return_line); 
}

char	*get_next_line(int fd)
{
	char		*t;
	char		*buf;
	static char	*stash;

	buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
	t = ft_read_content(fd, buf, stash);
	free (buf);
	buf = NULL;
	if (!t)
		return (NULL);
	stash = ft_sep(t); 
	return (t);
}

// int main()
// {
// 	int fd = open("text.txt", O_RDONLY);
//  	printf("%s\n",get_next_line(fd));
// 	printf("Hello World");
// }
