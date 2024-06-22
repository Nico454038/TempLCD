void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  //set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
}

void loop() {
  // read the analog / millivolts value for pin 38:
  // int analogValue = analogRead(38);
  int analogVolts = analogReadMilliVolts(38);

  float temperatureC = (analogVolts - 500) / 10.0; // calibration of the Thermistor
  float temperatureF = ((temperatureC * 9) / 5) + 32; // calculating Temp in Fahrenheit
  
  // print out the values you read:
  Serial.printf("\nTemperature: %.1fF",temperatureF);
  // Serial.printf("ADC millivolts value = %d\n",analogVolts);
  
  delay(100);  // delay in between reads for clear read from serial
}
