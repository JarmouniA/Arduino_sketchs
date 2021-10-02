#include <Wire.h>
#include <I2Cdev.h>
#include <MPU6050.h>

 /* AFS_SEL | Full Scale Range | LSB Sensitivity
 * --------+------------------+----------------
 * 0       | +/- 2g           | 8192 LSB/mg
 * 1       | +/- 4g           | 4096 LSB/mg
 * 2       | +/- 8g           | 2048 LSB/mg
 * 3       | +/- 16g          | 1024 LSB/mg
*/

MPU6050 mpu;

#define MPU6050_ACCEL_FS_2          0x00
#define MPU6050_ACCEL_FS_4          0x01
#define MPU6050_ACCEL_FS_8          0x02
#define MPU6050_ACCEL_FS_16         0x03

int16_t ax, ay, az;
int16_t gx, gy, gz;

struct _aaReal{
  int16_t x;
  int16_t y;
  int16_t z;
}aaReal;

int16_t aa, gravity, q;

void setup(){
 Serial.begin(9600);
 Serial.println("Initialize MPU");
 mpu.initialize();
 delay(1000);
 
 mpu.setFullScaleAccelRange(MPU6050_ACCEL_FS_16);
 Serial.println(mpu.getFullScaleAccelRange());
 delay(1000);
 
 // verify connection
 Serial.println("Testing device connections...");
 Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
 delay(1000);   
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
 
 ax = map(ax, -17000, 17000, -1500, 1500);
 ay = map(ay, -17000, 17000, -1500, 1500);
 az = map(az, -17000, 17000, -1500, 1500);
 
 //Serial.println(ax);
  Serial.print("A: "); Serial.print(ax); Serial.print("\t");  Serial.print(ay); Serial.print("\t");  Serial.print(az); Serial.print("\t");
  Serial.print("G: "); Serial.print(gx); Serial.print("\t");  Serial.print(gy); Serial.print("\t");  Serial.print(gz); Serial.print("\t");
  Serial.print("\n");
  delay(1000);

  // display real acceleration, adjusted to remove gravity
  /* mpu.dmpGetQuaternion(&q, fifoBuffer);
  mpu.dmpGetAccel(&aa, fifoBuffer);
  mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
  Serial.print(gravity.z);
  
  Serial.print("ACC real\t");
  Serial.print(aaReal.y);
  Serial.print("\t");
  Serial.print(aaReal.x);
  Serial.print("\t");
  Serial.println(aaReal.z);
  delay(1000); */
}
