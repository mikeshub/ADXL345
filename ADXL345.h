#ifndef ADXL345_h
#define ADXL345_h

#include <Arduino.h>
#include <I2C.h>
#include <CONFIG.h>
#include <digitalWriteFast.h>
#include <SPI.h>

//#define SPI_BUS
//#define I2C_BUS

#define ADXL435_ADDR 0x53

#define OFSX 0x1E //15.6 mg/LSB (that is, 0x7F = +2 g)
#define OFSY 0x1F
#define OFSZ 0x20

#define BW_RATE 0x2C
//00001011 - 200hz
#define POWER_CTL 0x2D
//00001000
#define DATA_FORMAT 0x31
//0x0B full res mode
//full res mode you must select full res and the maximum g

#define DATAX0 0x32
#define DATAX1 0x33
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37
#define FIFO_CTL 0x38

#define ACC_SS 48


#define READ 0x80
#define WRITE 0x00
#define MULTI 0x40
#define SINGLE 0x00


class ADXL345{
	public:
		void init(void);
		void read(void);
		int16_t accX;
		int16_t accY;
		int16_t accZ;
	private:
		int32_t accSumX;
		int32_t accSumY;
		int32_t accSumZ;
		uint8_t msb;
		uint8_t lsb;
};


#endif