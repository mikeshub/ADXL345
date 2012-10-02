#include <ADXL345.h>

void ADXL345::read(void){
  I2c.read(ADXL435_ADDR,DATAX0,6);
  lsb = I2c.receive();
  msb = I2c.receive();
  accY = (-1*((msb << 8) | lsb)) - OFFSET_Y;//the chip is on the board wrong. this is to fix the axis
  lsb = I2c.receive();
  msb = I2c.receive();
  accX = ((msb << 8) | lsb) - OFFSET_X;
  lsb = I2c.receive();
  msb = I2c.receive();
  accZ = ((msb << 8) | lsb) - OFFSET_Z;
}

void ADXL345::init(void){
  I2c.write(ADXL435_ADDR,BW_RATE,0x0C);
  I2c.write(ADXL435_ADDR,POWER_CTL,0x08);
  I2c.write(ADXL435_ADDR,DATA_FORMAT,0x0B);
  I2c.write(ADXL435_ADDR,FIFO_CTL,0x00);


}