#ifndef ADXL345_h
#define ADXL345_h

#include <Arduino.h>
#include <I2C.h>

#define ADXL435_ADDR 0x53

#define OFSX 0x1E //15.6 mg/LSB (that is, 0x7F = +2 g)
#define OFSY 0x1F
#define OFSZ 0x20

#define BW_RATE 0x2C
//00001100 - 400hz
#define POWER_CTL 0x2D
//00001000
#define DATA_FORMAT 0x31
//0x01 +/- 4g

#define DATAX0 0x32
#define DATAX1 0x33
#define DATAY0 0x34
#define DATAY1 0x35
#define DATAZ0 0x36
#define DATAZ1 0x37
#define FIFO_CTL 0x38
#define GRAVITY 131//close for the chips I tested

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
		int16_t offsetX;
		int16_t offsetY;
		int16_t offsetZ;
		uint8_t msb;
		uint8_t lsb;
};


#endif