/**
 ******************************************************************************
 * @file    crc.h
 * @brief   This file provides all the functions prototypes for
 *          the crc.c file.
 ******************************************************************************
 */

#ifndef __CRC_H__
#define __CRC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "main.h"

    uint16_t create_crc(uint8_t *ptr, uint8_t DataLen);
    int check_crc(uint8_t *ptr, uint8_t DataLen);
    uint8_t *add_crc(uint8_t *Data);

#ifdef __cplusplus
}
#endif
#endif /*__ CRC_H__*/
