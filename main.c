#include "minirt.h"

int check_float(char *str)
{
    int dot;
    int flag;

    dot = 0;
    flag = 1;
    if (*str == '-')
        str++;
    if (*str == '0' && *(str + 1) == '.')
    {
        str += 2;
        while((*str))
        {
            if (!ft_isdigit(*str))
            {
                flag = 0;
                break;
            }
            str++;
        }
        if (flag)
            return(CORRECT);
    }
    if (*str != '0' && ft_isdigit(*str))
    {
        while((*str))
        {
            if (*str == '.')
                dot++;
            if (!ft_isdigit(*str) || dot > 1)
            {
                flag = 0;
                break;
            }
            str++;
        }
        if (flag)
            return(CORRECT);
    }
    return (INCORRECT);
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

        printf("%f\n", ft_atof("-0).34"));
        printf("%f\n", ft_atof("-3..3+4"));
        printf("%f\n", ft_atof("-00.34"));
        printf("%f\n", ft_atof("-34."));
        printf("%f\n\n\n", ft_atof("345"));
        printf("-.34 = %d\n", check_float("-.34"));
        printf("-3..34 = %d\n", check_float("-3..34"));
        printf("-00.34 = %d\n", check_float("-00.34"));
        printf("0.34009- = %d\n", check_float("0.34009-"));
        printf("-10.34. = %d\n", check_float("-10.34."));
        printf("-0.34 = %d\n", check_float("-0.34"));
        printf("-34. = %d\n", check_float("-34."));
        printf("34463456 = %d\n", check_float("34463456"));
        //ft_open(&scene, ag[1]);
        //check(&scene, ag[1]);
//        draw_map(&scene);
//        mlx_key_hook(scene.win, actions, &scene);
//        mlx_hook(scene.win, 17, 0, leave_game, &scene);
//        mlx_loop(scene.mlx);
    }
    return (0);
}
