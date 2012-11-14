#include <ADXL345.h>
#include <I2C.h>
#include <Streaming.h>

ADXL345 accel;

float accXScaled,accYScaled,accZScaled;

void setup(){
  Serial.begin(57600);
  I2c.begin();
  I2c.setSpeed(1);
  accel.init();
}

void loop(){
  accel.read();
  accXScaled = accel.accX * 0.036029411;
  accYScaled = accel.accY * 0.036029411;
  accZScaled = accel.accZ * 0.036029411;
  Serial<<millis()<<","<<accXScaled<<","<<accYScaled<<","<<accZScaled<<"\r\n";
  //Serial<<millis()<<","<<accel.accX<<","<<accel.accY<<","<<accel.accZ<<"\r\n";
  delay(10);
}



