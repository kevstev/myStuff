/*
  Analog Input
 Demonstrates analog input by reading an analog sensor on analog pin 0 and
 turning on and off a light emitting diode(LED)  connected to digital pin 13. 
 The amount of time the LED will be on and off depends on
 the value obtained by analogRead(). 
 
 The circuit:
 * Potentiometer attached to analog input 0
 * center pin of the potentiometer to the analog pin
 * one side pin (either one) to ground
 * the other side pin to +5V
 * LED anode (long leg) attached to digital output 13
 * LED cathode (short leg) attached to ground
 
 * Note: because most Arduinos have a built-in LED attached 
 to pin 13 on the board, the LED is optional.
 
 
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 
 This example code is in the public domain.
 
 http://arduino.cc/en/Tutorial/AnalogInput
 
 */

int sensorPin = A5;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
#define aref_voltage 3.3
float tempFarenheitPrev = 70;
float tempFarenheitAvg = 70;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  analogReference(EXTERNAL);
  pinMode(12, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);    
  Serial.print(sensorValue); Serial.println(" sensor Value");
  
  float voltage = sensorValue *3.3;
  voltage /=1024.0;
  
 // Serial.print(voltage); Serial.println(" voltage");
  
  float tempCelsius = (voltage -0.5) * 100; //10mv per degree -500mv offset
  //Serial.print(tempCelsius); Serial.println(" tempCelsius");
 
   float tempFarenheitNow = (tempCelsius * 9.0/5.0) + 32.0;
   
 
   float tempFarenheitAvg = (tempFarenheitPrev + tempFarenheitNow) / 2;
 
   Serial.print(tempFarenheitNow); Serial.println(" NOW degreeds F");
   Serial.print(tempFarenheitPrev); Serial.println(" PREV degreeds F");
   Serial.print(tempFarenheitAvg); Serial.println(" AVG degreeds F");
 
   //   Serial.println("Writing high");
   //  digitalWrite(12, HIGH);
   //  delay(5000);

   if (tempFarenheitAvg > 130.0)
   {
     Serial.println("Writing LOW");
     digitalWrite(12, LOW);

   }
   if (tempFarenheitAvg < 129.50)
   {
     Serial.println("Writing HIGH");
     digitalWrite(12, HIGH);
   }
 
   tempFarenheitPrev = tempFarenheitAvg; 
   delay(3000);                  
}
