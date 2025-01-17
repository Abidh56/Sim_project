#include "Wire.h"
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
unsigned long timer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) { } 
  Serial.println(F("Calculating offsets, do not move MPU6050"));
  delay(1000);
  // mpu.upsideDownMounting = true; 
  mpu.calcOffsets(); // gyro and accelero
//  Serial.println("Done!\n");
}

void loop() {
  mpu.update();

  if ((millis() - timer) > 50) {

    float z = map(mpu.getAngleZ(), -30, 30, -900, 900);
    Serial.println(z);

    timer = millis();
  }
}
