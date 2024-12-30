#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
    image presentation:

*/
typedef struct	s_img {
	void	*img;  // mlx_new_image(mlx_connection, width, height)
	char	*addr; // img.addr now points to the start of your image data like this:
                    // [Byte1][Byte2][Byte3][Byte4][Byte5][Byte6]...
                    //  ^ img.addr points here
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;


void ft_draw_inside_img (t_img *img, int x, int y, int color)
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

int main()
{
    /* window */
    void *mlx_connection;
    void *mlx_window;
    
    mlx_connection = mlx_init();
    mlx_window = mlx_new_window(mlx_connection, 500, 500, "my first window");
    
    /* image */
    t_img img;

    img.img = mlx_new_image(mlx_connection, 500, 500);
    if(!img.img)
        return (1);
        
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

    ft_draw_inside_img(&img, 250, 250, 0xFFFFFF);
    mlx_put_image_to_window(mlx_connection, mlx_window, img.img, 0, 0);
    mlx_loop(mlx_connection);
    
    return 0;
}