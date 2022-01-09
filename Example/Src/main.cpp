
#include "DharaFTL.hpp"
#include "NandExample.hpp"
#include <cstdio>

#define GC_RATIO 4


char write_buf[512] = "Hello world!!!";
char read_buf[512];

constexpr uint32_t LOG2_PAGE_SIZE = 9; // 2^9 = 512 bytes
constexpr uint32_t LOG2_PAGES_PER_BLOCK = 3; // 2^3 = 8 (8 * 512 = 4096 - Erase block size, see NandExample.hpp)

// NandExample instance
static NandExample FlashMemory(LOG2_PAGE_SIZE, LOG2_PAGES_PER_BLOCK, NandExample::SECTORS_NUMBER);
// Dhare flash layer translation instance
static DharaFTL Map;


// Основная программа
int main(void)
{
    size_t page_size = FlashMemory.GetPageSize();
    uint8_t page_buf[page_size];
    dhara_error_t err;

    printf("Map init\n");
    Map.Init(&FlashMemory, page_buf, GC_RATIO);

    printf("Block number: %d\n", Map.GetBlockNum());
    printf("Block size: %d\n", Map.GetBlockSize());
    printf("Memory size: %d\n", Map.GetMemSize());
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        if (Map.Write(0, (const uint8_t *) write_buf, &err) < 0)
            printf("Write aborted!\r\n");


        if (Map.Read(0, (uint8_t *) read_buf, &err) < 0)
            printf("Read aborted!\r\n");

        printf("Result: %s\r\n", read_buf);
    }

    return 0;  
}