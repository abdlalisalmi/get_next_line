#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    while (get_next_line(fd, &line))
    {
        printf("%s\n", line);
        free_all(&line);
    }
    printf("%s\n", line);
    free_all(&line);
    return (0);
}
