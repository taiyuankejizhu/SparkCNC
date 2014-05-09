#ifndef _GPMI_H_
#define _GPMI_H_

typedef char uint8;

typedef unsigned short uint16;

typedef unsigned int uint32;

#define PAGE_1 0

#define X_OFFSET 0x00
#define Y_OFFSET 0x40
#define Z_OFFSET 0x80
#define IO_OFFSET 0xC0
#define OS_OFFSET 0xE0

/*
********************************************************************************************************
** Function name:		GPMI_Init
** Descriptions:		初始化GPMI接口
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint8 GPMI_Init(void);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		GPMI_Info
** Descriptions:		GPMI读取Flash信息
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void GPMI_Info(void);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		GPMI_Read
** Descriptions:		GPMI读取数据
** input parameters:    a:      要读取数据的地址
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint32 GPMI_Read(uint32 , uint8 *, uint32);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		GPMI_Write
** Descriptions:		GPMI读取数据
** input parameters:    pBuf:   写入数据的指针
**                      num:    要写数据的长度
** output parameters:   无
** Returned value:      uint32  写入的数据长度
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint32 GPMI_Write(uint32 , uint8 *,uint32);

#ifdef __cplusplus

}

#endif

#endif
