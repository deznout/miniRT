/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbrent <hbrent@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 09:56:02 by hbrent            #+#    #+#             */
/*   Updated: 2022/07/27 10:26:22 by hbrent           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
