#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
int main()
{
    char *str;
    int fd = open("test.txt", O_RDONLY);
    while((str = get_next_line(fd)) != NULL)
    {
        printf("line : %s", str);
    }

}