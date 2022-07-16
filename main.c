#include "minirt.h"

int check_float(char *str)
{
    int i;
    int dot;

    i = 0;
    dot = 0;
    if (str[i] == '-')
        i++;
//    if (str[i] == '0' && str[i + 1] != '0')
//    {
//        while (str[i] && ft_isdigit(str[i]))
//            i++;
//        if (str[i + 1] && str[i] == '.')
//        {
//            i++;
//            dot++;
//        }
//        while (str[i] && ft_isdigit(str[i]))
//            i++;
//        if (dot > 1)
//            return (INCORRECT);
//        return (CORRECT);
//    }
//    if (str[i] != '0' && ft_isdigit(str[i]))
//    {
//        while (str[i] && ft_isdigit(str[i]))
//            i++;
//        if (str[i] == '.' && ft_isdigit(str[i + 1]))
//            i++;
//        while (str[i] && ft_isdigit(str[i]))
//            i++;
//        return (CORRECT);
//    }
//    return (INCORRECT);
}

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

int	main(int ac, char** ag)
{
    if (ac == 2)
    {
        t_scene scene;

        scene.ambient.identifier_num = 0;
        scene.camera.identifier_num = 0;
        scene.cylinder.identifier_num = 0;
        scene.light.identifier_num = 0;
        scene.plane.identifier_num = 0;
        scene.sphere.identifier_num = 0;

        printf("%f\n", ft_atof("-.34"));
        printf("%f\n", ft_atof("-3..34"));
        printf("%f\n", ft_atof("-00.34"));
        printf("%f\n", ft_atof("-34."));
        printf("%f\n\n\n", ft_atof("345"));
        printf("-.34 = %d\n", check_float("-.34"));
        printf("-3..34 = %d\n", check_float("-3..34"));
        printf("-00.34 = %d\n", check_float("-00.34"));
        printf("0.34 = %d\n", check_float("0.34"));
        printf("-10.34 = %d\n", check_float("-10.34"));
        printf("-0.34 = %d\n", check_float("-0.34"));
        printf("-34. = %d\n", check_float("-34."));
        printf("34 = %d\n", check_float("34"));
        //ft_open(&scene, ag[1]);
        //check(&scene, ag[1]);
//        draw_map(&scene);
//        mlx_key_hook(scene.win, actions, &scene);
//        mlx_hook(scene.win, 17, 0, leave_game, &scene);
//        mlx_loop(scene.mlx);
    }
    return (0);
}
