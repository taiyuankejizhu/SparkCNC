#ifndef SETTING_H
#define SETTING_H

#define VERSION "V1.0"

#define DATA_FILE "/dev/fpga"
#define BEEP_FILE "/dev/beep"
#define SPI_FILE  "/dev/spidev1.0"

/*FM25V02 ADDR: 0x000000 ~ 0x007FFF*/
#define X_AXIS_ADDR 0x000000
#define Y_AXIS_ADDR 0x000100
#define Z_AXIS_ADDR 0x000200

#endif // SETTING_H
