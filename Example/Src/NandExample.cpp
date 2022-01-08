/*
 * NandExample.cpp
 *
 *  Created on: 8 янв. 2022 г.
 *      Author: Acer
 */

#include "NandExample.hpp"


int NandExample::SectorIsBad(dhara_block_t bno)
{
    return 0;
}

void NandExample::MarkBadSector(dhara_block_t bno)
{

}

int NandExample::EraseBlock(dhara_block_t bno, dhara_error_t *err)
{
    return 0;
}

int NandExample::Prog(dhara_page_t p, const uint8_t *data, dhara_error_t *err)
{
    return 0;
}

int NandExample::BlockIsFree(dhara_page_t p)
{
    return 0;
}

int NandExample::Read(dhara_page_t p, size_t offset, size_t length, uint8_t *data, dhara_error_t *err)
{
    return 0;
}

int NandExample::CopyPage(dhara_page_t src, dhara_page_t dst, dhara_error_t *err)
{
    return 0;
}

