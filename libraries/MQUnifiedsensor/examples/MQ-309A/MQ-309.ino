/*
  MQUnifiedsensor Library - reading an MQ309

  Demonstrates the use a MQ309 sensor.
  Library originally added 01 may 2019
  by Miguel A Califa, Yersson Carrillo, Ghiordy Contreras, Mario Rodriguez
 
  Added example
  modified 23 May 2019
  by Miguel Califa 

 This example code is in the public domain.

*/

//Include the library
#include <MQUnifiedsensor.h>

//Definitions
#define pin A0 //Analog input 0 of your arduino
#define type 309 //MQ309
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ309(pin, type);

//Variables
float H2, CH4, CO, Alcohol;

void setup() {
  Serial.begin(9600); //Init serial port
    //init the sensor
  /*****************************  MQInicializar****************************************
  Input:  pin, type 
  Output:  
  Remarks: This function create the sensor object.
  ************************************************************************************/ 
  MQ309.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

void loop() {
  MQ309.update();
  /*
    //Si el valor de RL es diferente a 10K por favor asigna tu valor de RL con el siguiente metodo:
    MQ309.setRL(10);
  */
  /*
  //Rutina de calibracion - Uncomment if you need (setup too and header)
  if(calibration_button)
  {
    float R0 = MQ309.calibrate();
    MQ309.setR0(R0);
  }
  */
  /*****************************  MQReadSensor  ****************************************
  Input:   Gas - Serial print flag
  Output:  Value in PPM
  Remarks: This function use readPPM to read the value in PPM the gas in the air.
  ************************************************************************************/ 
  //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ309.readSensor("", true); // Return CO concentration
  // Options, uncomment where you need
  H2 =  MQ309.readSensor("H2"); // Return H2 concentration
  CH4 =  MQ309.readSensor("CH4"); // Return CH4 concentration
  CO =  MQ309.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ309.readSensor("Alcohol"); // Return Alcohol concentration

  Serial.println("***************************");
  Serial.println("Lectures for MQ-309");
  Serial.print("Volt: ");Serial.print(MQ309.getVoltage(false));Serial.println(" V"); 
  Serial.print("R0: ");Serial.print(MQ309.getR0());Serial.println(" Ohm"); 
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("CH4: ");Serial.print(CH4,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Alcohol: ");Serial.print(Alcohol,2);Serial.println(" ppm");
  Serial.println("***************************");  
}
