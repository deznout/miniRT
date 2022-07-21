//
// Created by Hoover Brent on 7/21/22.
//
#ifndef JENISH_PARSER_H
#define JENISH_PARSER_H

# include "../minirt.h"
typedef struct s_scene t_scene;

int check_cylinder(char **elem_content, t_scene *scene);
int check_sphere(char **elem_content, t_scene *scene);
int check_plane(char **elem_content, t_scene *scene);
int check_light(char **elem_content, t_scene *scene);
int check_camera(char **elem_content, t_scene *scene);
int check_ambient(char **elem_content, t_scene *scene);

float   ft_atof(const char* s);
int     check_float(char *str);

#endif //JENISH_PARSER_H
