//
// Created by Hoover Brent on 7/7/22.
//

#include <fcntl.h>
#include "../minirt.h"

int check_scene(t_scene *scene, char *content)
{
    int     i;
    char    **arr;

    i = 0;
    arr = ft_split(content, '\n');
    while (arr[i])
        printf("count = %s\t%p\n", arr[i++], scene);

    return (1);
}

void    ft_open(t_scene *scene, char *arg)
{
    int	fd;
    int	rd;
    char *content;

    content = ft_substr(arg, ft_strlen(arg) - 3, 3);
    rd = ft_strncmp(content, ".rt", 3);
    free(content);
    fd = open(arg, O_RDONLY);
    if (fd < 0 || rd != 0)
    {
        printf("Incorrect map!\n");
        exit (1);
    }
    content = malloc(10000);
    rd = (int)read(fd, content, 10000);
    content[rd] = '\0';
    if (!check_scene(scene, content))
    {
        printf("Incorrect map!\n");
        exit (1);
    }
}
