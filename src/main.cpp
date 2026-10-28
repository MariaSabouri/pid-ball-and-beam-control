#include <Arduino.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include "SparkFun_VL53L1X.h"
#include <vector>

using namespace std;

double errorIntegralCalculation(int);

Servo servo;
SFEVL53L1X distanceSensor;

/*
initialization:
teta0 : initial degree of balancer
*/
double teta0 = 28;

void setup()
{

  /*
  servo setup :
  */
  servo.setPeriodHertz(50);
  servo.attach(12, 1000, 2000);
  servo.write(teta0);
  delay(2000);

  /*
  VL setup :
  */
  Wire.begin();

  Serial.begin(115200);
  Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor.begin() != 0)
  {
    Serial.println("Sensor failed to begin. Please check wiring. Freezing...");
    while (1);
  }
  Serial.println("Sensor online!");
}

/*
Software requirements
*/
static vector<double> error_arr;
double teta;
double error;
// exp_dis : expected distance
double exp_dis = 100;

/*
PID Gains and your definition area
*/
double Kp = 0.002;
double Ki = 0.00005;
double Kd = 0.008;

void loop()
{
  distanceSensor.startRanging();
  while (!distanceSensor.checkForDataReady())
  {
    delay(1);
  }
  double distance = distanceSensor.getDistance();
  distanceSensor.clearInterrupt();
  distanceSensor.stopRanging();

  Serial.print("Distance(mm): ");
  Serial.print(distance);
  Serial.println("");

  //   /*
  //   PID calculations:
  //   */
  error = distance - exp_dis;


  if (error_arr.empty())
  {
    teta = Kp * error;
  }
  else
  {

  if (error > -10 & error <10)
  {
    error = 0 ;
  }

    teta = Kp * error + Kd * (error - error_arr[error_arr.size()-1]) + Ki * errorIntegralCalculation(10);
  }

  Serial.print("error: ");
  Serial.println(error);


  Serial.print("teta: ");
  Serial.println(teta);

  servo.write(teta0 + teta / M_PI * 180);
  error_arr.push_back(error);
}


double errorIntegralCalculation(int i)
{
  Serial.print("error arr:");
  Serial.println(error_arr.size());

  int size = error_arr.size();
  int res = 0;
  if (i <= size)
  {
    for (int j = size - i; j < size - 1; j++)
    {
      res = res + (error_arr[j] + error_arr[j + 1]) * 0.5;
    }
  }
  else
  {
    res = 0;
  }
  return res;
}
