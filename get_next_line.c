#include<stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
char    *ft_read_content(int fd, char *buf, char *s)
{
    int lines;
    char    *temp;
    
    lines = read(fd, buf, BUFFER_SIZE);
    while (lines > 0)
    {
        buf[lines] = '\0';
        if (!s)
            s = ft_strdup("");
        //assign current address to temp the free it
        temp = s;
        s = ft_strjoin(temp, buf);
        free(temp);
        if(ft_strchr(buf, '\n'))
            break;
        lines = read(fd, buf, BUFFER_SIZE);
    }
    return (s);
}
char    *ft_sep(char *line)
{
    
}

#ifndef O_RDONLY
# define O_RDONLY 0
#endif
char    *ft_get_next_line(int fd){
    char *t;
    char *buf;
    static char *s;
    // char    *temp;

    buf = (char *) malloc (sizeof(char) * (BUFFER_SIZE + 1));
    t = ft_read_content(fd, buf, s);
    //free the temp string used
    free(buf);
    buf = NULL;
    if (!t)
        return (NULL);
    s = ft_sep(t);
    return t;
    
}

int main(int arc, char **argv){

    int f_d;
    (void)arc;
    f_d = open(argv[1], O_RDONLY);
    if (f_d > 0){
        ft_get_next_line(f_d);
    }
}