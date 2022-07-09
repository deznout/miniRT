//
// Created by Hoover Brent on 7/7/22.
//

#include <fcntl.h>
#include "../minirt.h"

int get_element(char *str, t_scene *scene)
{
    char    **arr;
    int     i;

    i = 0;
    arr = ft_split(str, ' ');
    while (arr[i])
        printf("%s\n", arr[i++]);
    if (!ft_strncmp("A", arr[0], 1))
    {
        scene->ambient.identifier = 1;
        return 1;
    }
    else if (!ft_strncmp("C", arr[0], 1))
    {
        scene->camera.identifier = 1;
        return 1;
    }
    else if (!ft_strncmp("L", arr[0], 1))
    {
        scene->light.identifier = 1;
        return 1;
    }
    else if (!ft_strncmp("pl", arr[0], 2))
    {
        scene->plane.identifier = 1;
        return 1;
    }
    else if (!ft_strncmp("sp", arr[0], 2))
    {
        scene->sphere.identifier = 1;
        return 1;
    }
    else if (!ft_strncmp("cy", arr[0], 2))
    {
        scene->cylinder.identifier = 1;
        return 1;
    }
    return (0);
}

int check_scene(t_scene *scene, char *content)
{
    int     i;
    char    **arr;

    i = 0;
    arr = ft_split(content, '\n');
    while (arr[i])
        if (!get_element(arr[i++], scene))
            return (0);
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
