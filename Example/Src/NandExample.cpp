/*
 * NandExample.cpp
 *
 *  Created on: 8 янв. 2022 г.
 *      Author: Acer
 */

#include "NandExample.hpp"
#include <cstdio>
#include <cstring>

uint8_t NandExample::Pages[];

int NandExample::SectorIsBad(dhara_block_t bno)
{
    return false;
}


void NandExample::MarkBadSector(dhara_block_t bno)
{

}


int NandExample::EraseBlock(dhara_block_t bno, dhara_error_t *err)
{
    uint8_t *blk = Pages + (bno << GetLog2BlockSize());

	if (bno >= GetNumBlocks()) 
    {
        return -1;
	}

	printf("Erasing page: %d!\r\n", blk);

	memset(blk, 0xff, GetBlockSize());
	return 0;
}


int NandExample::Prog(dhara_page_t p, const uint8_t *data, dhara_error_t *err)
{
    int bno = p >> log2_ppb;
	int pno = p & ((1 << log2_ppb) - 1);
	uint8_t *page = Pages + (p << log2_page_size);

	if ((bno < 0) || (bno >= GetNumBlocks())) 
    {
        return -1;
	}

	printf("Write adr: %d\r\n", page);

	memcpy(page, data, GetPageSize());
	return 0;
}


int NandExample::BlockIsFree(dhara_page_t p)
{
    const int bno = p >> log2_ppb;
    const int pno = p & ((1 << log2_ppb) - 1);

    if ((bno < 0) || (bno >= GetNumBlocks())) 
    {
        return false;
    }


    uint8_t *blk = Pages + (bno << GetLog2BlockSize());

    if ((blk[0] == 0xFF) && (blk[1] == 0xFF))
    {
        printf("Page is erased!\r\n");
        return false;
    }

    printf("Page is not erased!\r\n");
    return true;
}


int NandExample::Read(dhara_page_t p, size_t offset, size_t length, uint8_t *data, dhara_error_t *err)
{
    int bno = p >> log2_ppb;
	uint8_t *page = Pages + (p << log2_page_size);

	if ((bno < 0) || (bno >= GetNumBlocks())) 
    {
        return -1;
	}

	if ((offset > GetPageSize()) || (length > GetPageSize()) || (offset + length > GetPageSize())) 
    {
        return -1;
	}


	printf("Read adr: %d\r\n", (page + offset));
	memcpy(data, page + offset, length);
	return 0;
}


int NandExample::CopyPage(dhara_page_t src, dhara_page_t dst, dhara_error_t *err)
{
    uint8_t *buf = new uint8_t[GetPageSize()];

    int status = 0;

	if ((Read(src, 0, GetPageSize(), buf, err) < 0) || (Prog(dst, buf, err) < 0))
    {
        status = -1;
    }

    delete[] buf;
		
	return status;
}

