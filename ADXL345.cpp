#include <ADXL345.h>

void ADXL345::read(void){
  I2c.read(ADXL435_ADDR,DATAX0,6);
  lsb = I2c.receive();
  msb = I2c.receive();
  accY = (-1*((msb << 8) | lsb)) - offsetY;//the chip is on the board wrong. this is to fix the axis
  lsb = I2c.receive();
  msb = I2c.receive();
  accX = ((msb << 8) | lsb) - offsetX;
  lsb = I2c.receive();
  msb = I2c.receive();
  accZ = ((msb << 8) | lsb) - offsetZ;
}

void ADXL345::init(void){
  I2c.write(ADXL435_ADDR,BW_RATE,0x0C);
  I2c.write(ADXL435_ADDR,POWER_CTL,0x08);
  I2c.write(ADXL435_ADDR,DATA_FORMAT,0x01);
  I2c.write(ADXL435_ADDR,FIFO_CTL,0x00);
  accSumX = 0;
  accSumY = 0;
  accSumZ = 0;
  offsetX = 0;
  offsetY = 0;
  offsetZ = 0;
  for(int i =0;i<128;i++){
    read();
    accSumX += accX;
    accSumY += accY;
    accSumZ += accZ;
    delay(5);
  }
  accSumX = accSumX >> 7;
  accSumY = accSumY >> 7;
  accSumZ = accSumZ >> 7;
  offsetX = accSumX;
  offsetY = accSumY;
  offsetZ = (accSumZ + 131);

}