//
// Created by Hoover Brent on 7/7/22.
//

#include <fcntl.h>
#include "../minirt.h"
/*
int check_float(char *str)
{
    int i;

    i = 0;
    if (str[i + 1] && str[i] == '-')
        i++;
    if (str[i] == '0' && str[i + 1] != '0')
    {
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i + 1] && str[i] == '.')
            i++;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        return (CORRECT);
    }
    if (str[i] != '0')
    {
        while (str[i] && ft_isdigit(str[i]))
            i++;
        if (str[i] == '.' && str[i + 1])
            i++;
        while (str[i] && ft_isdigit(str[i]))
            i++;
        return (CORRECT);
    }
    return (INCORRECT);
}
*/
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

int check_sphere(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->sphere.point_xyz[i] = ft_atof(v_points[i]);
            i++;
        }
        scene->sphere.bright_diam_ratio = ft_atof(elem_content[2]);
        v_points = ft_split(elem_content[3], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->sphere.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->sphere.r_g_b[i] >= 0 && scene->sphere.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->sphere.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}

int check_plane(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->light.point_xyz[i] = ft_atof(v_points[i]);
            i++;
        }
        scene->light.light_height_ratio = ft_atof(elem_content[2]);
        if (!(scene->light.light_height_ratio >= 0.0 && scene->light.light_height_ratio <= 1.0))
            return (INCORRECT);
        v_points = ft_split(elem_content[3], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->light.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->light.r_g_b[i] >= 0 && scene->light.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->light.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}

int check_light(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->light.point_xyz[i] = ft_atof(v_points[i]);
            i++;
        }
        scene->light.light_height_ratio = ft_atof(elem_content[2]);
        if (!(scene->light.light_height_ratio >= 0.0 && scene->light.light_height_ratio <= 1.0))
            return (INCORRECT);
        v_points = ft_split(elem_content[3], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->light.r_g_b[i] = ft_atoi(v_points[i]);
            if (!(scene->light.r_g_b[i] >= 0 && scene->light.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->light.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}

int check_camera(char **elem_content, t_scene *scene)
{
    int     i;
    char    **v_points;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 4)
    {
        i = 0;
        v_points = ft_split(elem_content[1], ',');
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->camera.point_xyz[i] = ft_atof(v_points[i]);
            i++;
        }
        v_points = ft_split(elem_content[2], ',');
        i = 0;
        while (v_points[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->camera.orient_vector[i] = ft_atof(v_points[i]);
            if (!(scene->camera.orient_vector[i] >= -1 && scene->camera.orient_vector[i] <= 1))
                return (INCORRECT);
            i++;
        }
        scene->camera.fov_in_degrees = ft_atoi(elem_content[3]);
        if (!(scene->camera.fov_in_degrees >= 0 && scene->camera.fov_in_degrees <= 180))
            return (INCORRECT);
        scene->camera.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
}

int check_ambient(char **elem_content, t_scene *scene)
{
    char    **colors;
    int     i;

    i = 0;
    while (elem_content[i])
        i++;
    if (i == 3)
    {
        i = 0;
        scene->ambient.light_height_ratio = ft_atof(elem_content[1]);
        if (!(scene->ambient.light_height_ratio >= 0.0 && scene->ambient.light_height_ratio <= 1.0))
            return (INCORRECT);
        colors = ft_split(elem_content[2], ',');
        while (colors[i])
        {
            if (i > 2)
                return (INCORRECT);
            scene->ambient.r_g_b[i] = ft_atoi(colors[i]);
            if (!(scene->ambient.r_g_b[i] >= 0 && scene->ambient.r_g_b[i] <= 255))
                return (INCORRECT);
            i++;
        }
        scene->ambient.identifier_num += 1; // after checking that all params are correct -> then align a value
        return (CORRECT);
    }
    return (INCORRECT);
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
        return (check_sphere(elem_content, scene));
    if (!ft_strncmp("cy", elem_content[0], 2))
        return (check_cylinder(elem_content, scene));
    return (INCORRECT);
}

int check_scene(t_scene *scene, char *content)
{
    int     i;
    char    **elements;

    i = 0;
    elements = ft_split(content, '\n');
    while (elements[i])
        if (!define_element(elements[i++], scene)) // + check the number of A/C/L
            return (INCORRECT);
    return (CORRECT);
}

void    ft_open(t_scene *scene, char *arg)
{
    int     fd;
    int     rd;
    char    *content;

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
