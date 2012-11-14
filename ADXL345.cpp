#include <ADXL345.h>
#include <CONFIG.h>

void ADXL345::read(void){
  #ifdef SPI_BUS
	SPI.setDataMode(SPI_MODE3);
	digitalWriteFast(ACC_SS,LOW);
	SPI.transfer(READ | MULTI | DATAX0);

	lsb = SPI.transfer(0x00);
	msb = SPI.transfer(0x00);
	accY = (-1*((msb << 8) | lsb));

	lsb = SPI.transfer(0x00);
	msb = SPI.transfer(0x00);
	accX = ((msb << 8) | lsb);

	lsb = SPI.transfer(0x00);
	msb = SPI.transfer(0x00);
	accZ = ((msb << 8) | lsb);

	digitalWriteFast(ACC_SS,HIGH);
  #endif
  #ifdef I2C_BUS
	  I2c.read(ADXL435_ADDR,DATAX0,6);
	  lsb = I2c.receive();
	  msb = I2c.receive();

	  accY = (-1*((msb << 8) | lsb));//the chip is on the board wrong. this is to fix the axis
	  lsb = I2c.receive();
	  msb = I2c.receive();

	  accX = ((msb << 8) | lsb);
	  lsb = I2c.receive();
	  msb = I2c.receive();
	  accZ = ((msb << 8) | lsb);
  #endif
}

void ADXL345::init(void){
  #ifdef SPI_BUS
	SPI.setDataMode(SPI_MODE3);
	pinModeFast(ACC_SS,OUTPUT);
	digitalWriteFast(ACC_SS,HIGH);

	digitalWriteFast(ACC_SS,LOW);
	SPI.transfer(WRITE | SINGLE | BW_RATE);
	SPI.transfer(0x0C);
	digitalWriteFast(ACC_SS,HIGH);

	digitalWriteFast(ACC_SS,LOW);
	SPI.transfer(WRITE | SINGLE | POWER_CTL);
	SPI.transfer(0x08);
	digitalWriteFast(ACC_SS,HIGH);

	digitalWriteFast(ACC_SS,LOW);
	SPI.transfer(WRITE | SINGLE | DATA_FORMAT);
	SPI.transfer(0x0B);
	digitalWriteFast(ACC_SS,HIGH);

  #endif
  #ifdef I2C_BUS
  	I2c.write(ADXL435_ADDR,BW_RATE,0x0C);
  	I2c.write(ADXL435_ADDR,POWER_CTL,0x08);
  	I2c.write(ADXL435_ADDR,DATA_FORMAT,0x0B);
  	I2c.write(ADXL435_ADDR,FIFO_CTL,0x00);
  #endif

}