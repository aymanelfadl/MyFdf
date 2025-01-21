
#include "fdf.h"




void ft_put_pixel(t_img *img, int x, int y, int color)
{
    /*When you write a pixel:
        *(unsigned int *)dst = color;

        // It's like:
        Memory before: [00][00][00][00]
                        ↓  ↓  ↓  ↓
        Color (red):   [00][FF][00][00]
                        A  R  G  B 
        access the adress with x and yand change in it ; 
    */
    char *pixel;
    pixel = img->addr + (x * (img->bits_per_pixel / 8) + (y * img->line_length));

    /* so now change the adress*/
    *(unsigned int *) pixel = color; 
}

void ft_lower_slope(t_img *img ,int dx, int dy, t_point *p1, t_point *p2)
{
    int i;
    int p;

    i = 0;
    p = 2 * dy - dx;
    ft_put_pixel(img, p1->x , p1->y, p1->color);
    while (i < dx)
    {
        p1->x += 1;
        if (p < 0)
            p = p + 2 * dy;
        else
        {
            p1->y += 1;
            p = p + 2 * dy - 2 * dx;
        }
        ft_put_pixel(img, p1->x, p1->y, p1->color);
        i++;
    }
}

void ft_higher_slope(t_img *img ,int dx, int dy, t_point *p1, t_point *p2)
{
    int i;
    int p;

    i = 0;
    p = 2 * dx - dy;
    ft_put_pixel(img, p1->x , p1->y, p1->color);
    while (i < dy)
    {
        p1->y += 1;
        if (p < 0)
            p = p + 2 * dx;
        else
        {
            p1->x += 1;
            p = p + 2 * dx - 2 * dy;
        }
        ft_put_pixel(img, p1->x, p1->y, p1->color);
        i++;
    }
}
/*
    calculate slope to draw a line between two points
*/
void ft_calculate_slope(t_img *img , t_point *p1, t_point *p2)
{
    int dx;
    int dy;

    dx = p2->x - p1->x;
    dy = p2->y - p2->x;

    if (abs(dx) > abs(dy))
        ft_lower_slope(img, dx, dy, p1, p2);
    else
        ft_higher_slope(img, dx, dy, p1, p2);
}

int main()
{
    /* window */
    void *mlx_connection;
    void *mlx_window;
    
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 1000, 1000, "my first window");
    
    /* image */
    t_img img;

    img.img = mlx_new_image(mlx_connection, 900, 900);
    if(!img.img)
        return (1);

    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    t_point p1, p2 , p3;
    p1.x = 0;
    p1.y = 0;
    p2.x = 20;
    p2.y = 10;
    p3.x = 1;
    p3.y = 50;
    p1.color = 0xFFFFFF;
    p2.color = 0x00FF00;
    ft_calculate_slope(&img, &p1, &p2);
    ft_calculate_slope(&img, &p1, &p3);
    mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 10, 10);
    mlx_loop(mlx_connection);
    
    return 0;
}