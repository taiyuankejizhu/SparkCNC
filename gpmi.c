#include "gpmi.h"
#include "setting.h"
#include "fcntl.h"
#include "unistd.h"
#include "stdio.h"
#include "string.h"
#include "sys/ioctl.h"
#include "mtd/mtd-user.h"

/*存储数据接口的文件描述符*/
static int gpmi_fd;

/*
********************************************************************************************************
** Function name:		GPMI_Init
** Descriptions:		初始化GPMI接口
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
uint8 GPMI_Init(void)
{

    gpmi_fd = open(DATA_FILE, O_RDONLY);

    if(gpmi_fd < 0){
        printf("Can't open GPMI device!\n");
        return 0;
    }
    else{
        printf("GPMI device is openned!\n");
        return 1;
    }
}


/*
********************************************************************************************************
** Function name:		GPMI_Info
** Descriptions:		GPMI读取Flash信息
** input parameters:    无
** output parameters:   无
** Returned value:      无
********************************************************************************************************
*/
void GPMI_Info(void)
{
    struct mtd_info_user info;

    if(gpmi_fd < 0)
        return;

    if(ioctl(gpmi_fd, MEMGETINFO, &info)){
        printf("Can't get the info data!\n");
        return;
    }
    else{

        switch(info.type){
        case MTD_ABSENT:
            printf("type:MTD_ABSENT\n");
            break;
        case MTD_RAM:
            printf("type:MTD_RAM\n");
            break;
        case MTD_ROM:
            printf("type:MTD_ROM\n");
            break;
        case MTD_NORFLASH:
            printf("type:MTD_NORFLASH\n");
            break;
        case MTD_NANDFLASH:
            printf("type:MTD_NANDFLASH\n");
            break;
        case MTD_DATAFLASH:
            printf("type:MTD_DATAFLASH\n");
            break;
        case MTD_UBIVOLUME:
            printf("type:MTD_UBIVOLUME\n");
            break;
        default:
            printf("type:none\n");
            break;
        }

        switch(info.flags){
        case MTD_WRITEABLE:
            printf("flags:MTD_WRITEABLE\n");
            break;
        case MTD_BIT_WRITEABLE:
            printf("flags:MTD_BIT_WRITEABLE\n");
            break;
        case MTD_NO_ERASE:
            printf("flags:MTD_NO_ERASE\n");
            break;
        case MTD_POWERUP_LOCK:
            printf("flags:MTD_POWERUP_LOCK\n");
            break;
        case MTD_CAP_ROM:
            printf("flags:MTD_CAP_ROM\n");
            break;
        case MTD_CAP_RAM:
            printf("flags:MTD_CAP_RAM\n");
            break;
        case MTD_CAP_NORFLASH:
            printf("flags:MTD_CAP_NORFLASH\n");
            break;
        default:
            printf("flags:none\n");
            break;
        }

        printf("size:%d\n" ,info.size);
        printf("erasesize:%d\n" ,info.erasesize);
        printf("writesize:%d\n" ,info.writesize);
        printf("oobsize:%d\n" ,info.oobsize);
        printf("eccsize:%d\n" ,info.eccsize);
        printf("ecctype:%d\n" ,info.ecctype);
    }
}

/*
********************************************************************************************************
** Function name:		GPMI_Read
** Descriptions:		GPMI读取数据
** input parameters:    pBuf:   读出数据的指针
**                      num:    要读数据的长度
**                      addr:   要读数据的地址相对于文件开始位置
** output parameters:   无
** Returned value:      uint32  读出的数据长度
********************************************************************************************************
*/
uint32 GPMI_Read(uint32 addr ,uint8 *pBuf ,uint32 num)
{
    struct mtd_info_user info;
    uint32 n;

    if(gpmi_fd < 0)
        return 0;

    if(ioctl(gpmi_fd, MEMGETINFO, &info)){
        printf("Can't get the info data!\n");
        return 0;
    }
    else{
        /*check the write length*/
        if(num + addr > info.writesize)
            num = info.writesize - addr;

        lseek(gpmi_fd, addr, SEEK_SET);

        n = read(gpmi_fd ,pBuf ,num);
        return n;
    }
}

/*
********************************************************************************************************
** Function name:		GPMI_Write
** Descriptions:		GPMI读取数据
** input parameters:    pBuf:   写入数据的指针
**                      num:    要写数据的长度
**                      addr:   写入数据的地址相对于文件开始位置
** output parameters:   无
** Returned value:      uint32  写入的数据长度
********************************************************************************************************
*/
uint32 GPMI_Write(uint32 addr ,uint8 *pBuf ,uint32 num)
{
    struct mtd_info_user info;
    struct erase_info_user e_info;
    uint32 n;

    if(gpmi_fd < 0)
        return 0;

    if(ioctl(gpmi_fd, MEMGETINFO, &info)){
        printf("Can't get the info data!\n");
        return 0;
    }
    else{
        e_info.start = PAGE_1;
        e_info.length = info.erasesize;

        /*erase the page_1,if the device is not a nand flash device ,
        this step should be ignore*/
        if (ioctl(gpmi_fd,MEMERASE,&e_info) < 0) {
            printf("Erasing page_1 failed!\n");
            return 0;
        }

        /*check the write length*/
        if(num + addr > info.writesize)
            num = info.writesize - addr;

        lseek(gpmi_fd, addr, SEEK_SET);

        /*write the data to page_1*/
        n = write(gpmi_fd, pBuf, num);
        if (n < num) {
            printf("Error writing image.\n");
            return 0;
        }

        return n;
    }
}

