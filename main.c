#include "./MLX42/include/MLX42/MLX42.h"

// Written by Bruh
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 256
#define HEIGHT 256

/* DON'T DELETE IT! this is for opening a winfow 
int main(void)
{
    void *mlx; // The magical mlx pointer

    // Initialize mlx
    mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);

    // The window will stay open until you close it
    mlx_loop(mlx);

    return 0;
}
*/

int main(int argc, char **argv)
{
   if (argc != 2)
   {
        printf("invalid input\n"); // change this part acccording to subject pdf
        return (0); // change this part acccording to subject pdf exit(EXIT_SUCCESS) ???
   }
    if (is_ber(argv[1]))
    {
        printf("file type is .ber\n"); //delete it!
        validate_map(argv[1]);
    }
    else
        printf("file type is NOT .ber\n"); //delete it!
    
    return (0);
}


// // Exit the program as failure.
// static void ft_error(void)
// {
// 	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// // Print the window width and height.
// static void ft_hook(void* param)
// {
// 	const mlx_t* mlx = param;

// 	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
// }

// int32_t	main(void)
// {

// 	// MLX allows you to define its core behaviour before startup.
// 	mlx_set_setting(MLX_MAXIMIZED, true);
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
// 	if (!mlx)
// 		ft_error();

// 	/* Do stuff */

// 	// Create and display the image.
// 	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
// 	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
// 		ft_error();

// 	// Even after the image is being displayed, we can still modify the buffer.
// 	mlx_put_pixel(img, 0, 0, 0xFF0000FF);

// 	// Register a hook and pass mlx as an optional param.
// 	// NOTE: Do this before calling mlx_loop!
// 	mlx_loop_hook(mlx, ft_hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }

