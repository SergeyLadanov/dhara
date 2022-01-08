
#include "main.h"
#include "dhara.h"
#include <cstdio>

#define NUM_SECTORS		200
#define GC_RATIO		4


char write_buf[128] = "Hello world!!!";
char read_buf[128];

// Основная программа
int main(void)
{
    // const size_t page_size = 1 << sim_nand.log2_page_size;
	// uint8_t page_buf[page_size];
     struct dhara_map map;
	// int i;

    // dhara_error_t err;



	// printf("%d\n", (int)sizeof(map));

	// sim_reset();

    printf("Map init\n");
	//dhara_map_init(&map, &sim_nand, page_buf, GC_RATIO);
	dhara_map_resume(&map, NULL);
	printf("  capacity: %d\n", dhara_map_capacity(&map));
	printf("\n");


    // for (int i = 0; i < 2; i++)
    // {
    //     if (dhara_map_write(&map, 0, write_buf, &err) < 0)
    //         printf("Write aborted!\r\n");


    //     if (dhara_map_read(&map, 0, read_buf, &err) < 0)
    //         printf("Read aborted!\r\n");

    //     printf("Result: %s\r\n", read_buf);
    // }




    return 0;  
}