#ifndef _FPGA_H_
#define _FPGA_H_

typedef char uint8;

typedef unsigned short uint16;

typedef unsigned int uint32;

typedef long uint64;

//#define PAGE_1 0x00
#define GPMI_BASE 0x0000
#define PARPORT_BASE 0x0378
#define ISA_BASE 0x0240

#define X_OFFSET 0x00
#define Y_OFFSET 0x04
#define Z_OFFSET 0x08
#define OSC_OFFSET 0x10
#define IO_OFFSET 0x18
#define SPI_OFFSET 0x20

#define DATA_OFFSET 0x00

/*
********************************************************************************************************
** Function name:		FPGA_Init
** Descriptions:		初始化FPGA接口
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint8 FPGA_Init(void);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		FPGA_Info
** Descriptions:		读取FPGA信息
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void FPGA_Info(void);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		FPGA_Read
** Descriptions:		FPGA读取数据
** input parameters:    pBuf:   读出数据的指针
**                      num:    要读数据的长度
**                      addr:   要读数据的地址相对于文件开始位置
** output parameters:   无
** Returned value:      uint32  读出的数据长度
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint32 FPGA_Read(uint32 , uint8 *, uint32);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		FPGA_Write
** Descriptions:		FPGA读取数据
** input parameters:    pBuf:   写入数据的指针
**                      num:    要写数据的长度
** output parameters:   无
** Returned value:      uint32  写入的数据长度
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

uint32 FPGA_Write(uint32 , uint8 *,uint32);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		IO0_Write
** Descriptions:		FPGA写入IO0
** input parameters:    无
** output parameters:   无
** Returned value:      uint8  IO0的值
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void IO0_Write(uint8);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		IO1_Write
** Descriptions:		FPGA写入IO1
** input parameters:    无
** output parameters:   无
** Returned value:      uint8  IO1的值
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void IO1_Write(uint8);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		IO2_Write
** Descriptions:		FPGA写入IO2
** input parameters:    无
** output parameters:   无
** Returned value:      uint8  IO2的值
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void IO2_Write(uint8);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		IO3_Write
** Descriptions:		FPGA写入IO3
** input parameters:    无
** output parameters:   无
** Returned value:      uint8  IO3的值
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void IO3_Write(uint8);

#ifdef __cplusplus

}

#endif

/*
********************************************************************************************************
** Function name:		IO4_Write
** Descriptions:		FPGA写入IO4
** input parameters:    无
** output parameters:   无
** Returned value:      uint8  IO4的值
********************************************************************************************************
*/
#ifdef __cplusplus

extern "C" {

#endif

void IO4_Write(uint8);

#ifdef __cplusplus

}

#endif

#endif
