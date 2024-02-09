#include "so_long.h"

// this main func is for testing read_map func
int main(void) 
{
    char *file_path = "./maps/invalid_map1.ber"; // テストファイルのパスを指定
    char *map_str = read_map(file_path);
    if (map_str == NULL)
    {
        printf("File could not be read or does not exist.\n");
        return (1);
    }
	if (validate_map(map_str))
    	printf("File content:\n%s\n", map_str);
    free(map_str);
    return (0);
}