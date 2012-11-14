#include <SPI.h>
#include <ADXL345.h>
#include <I2C.h>
#include <Streaming.h>
#include <digitalWriteFast.h>
#include <CONFIG.h>

//in ADXL345.h switch the define to use I2C or SPI

ADXL345 accel;

float accXScaled,accYScaled,accZScaled;

void setup(){
  Serial.begin(57600);
  pinMode(MISO,INPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  I2c.begin();
  I2c.setSpeed(1);
  accel.init();
}

void loop(){
  accel.read();
  accXScaled = accel.accX * 0.03684210526;
  accYScaled = accel.accY * 0.03698113207;
  accZScaled = accel.accZ * 0.03904382470;
  //Serial<<millis()<<","<<accXScaled<<","<<accYScaled<<","<<accZScaled<<"\r\n";
  Serial<<millis()<<","<<accel.accX<<","<<accel.accY<<","<<accel.accZ<<"\r\n";
  delay(10);
}



