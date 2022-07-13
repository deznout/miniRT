//
// Created by Hoover Brent on 7/7/22.
//

#include <fcntl.h>
#include "../minirt.h"

float   ft_atof(const char* s)
{
    float rez = 0, fact = 1;
    if (*s == '-'){
        s++;
        fact = -1;
    };
    for (int point_seen = 0; *s; s++){
        if (*s == '.'){
            point_seen = 1;
            continue;
        };
        int d = *s - '0';
        if (d >= 0 && d <= 9){
            if (point_seen) fact /= 10.0f;
            rez = rez * 10.0f + (float)d;
        };
    };
    return rez * fact;
};

int check_cylinder(char **elem_content, t_scene *scene)
{

    return (1);
}

int check_space(char **elem_content, t_scene *scene)
{

    return (1);
}

int check_plane(char **elem_content, t_scene *scene)
{

    return (1);
}

int check_light(char **elem_content, t_scene *scene)
{

    return (1);
}

int check_camera(char **elem_content, t_scene *scene)
{

    return (1);
}

int check_ambient(char **elem_content, t_scene *scene)
{
    scene->ambient.identifier_num += 1;
    while (elem_content)
    {
        scene->ambient.light_height_ratio = ft_atof(elem_content[i]);
    }
    return (1);
}

int define_element(char *elem_str, t_scene *scene)
{
    char    **elem_content;

    elem_content = ft_split(elem_str, ' ');
    if (!ft_strncmp("A", elem_content[0], 1))
        return (check_ambient(elem_content, scene));
    if (!ft_strncmp("C", elem_content[0], 1))
        return (check_camera(elem_content, scene));
    if (!ft_strncmp("L", elem_content[0], 1))
        return (check_light(elem_content, scene));
    if (!ft_strncmp("pl", elem_content[0], 2))
        return (check_plane(elem_content, scene));
    if (!ft_strncmp("sp", elem_content[0], 2))
        return (check_space(elem_content, scene));
    if (!ft_strncmp("cy", elem_content[0], 2))
        return (check_cylinder(elem_content, scene));
    return (0);
}

int check_scene(t_scene *scene, char *content)
{
    int     i;
    char    **elements;

    i = 0;
    elements = ft_split(content, '\n');
    while (elements[i])
        if (!define_element(elements[i++], scene))
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
        printf("Incorrect file!\n");
        exit (1);
    }
    content = malloc(10000);
    rd = (int)read(fd, content, 10000);
    content[rd] = '\0';
    if (!check_scene(scene, content))
    {
        printf("Incorrect scene!\n");
        exit (1);
    }
}
