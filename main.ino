#include <Arduino_FreeRTOS.h>

void TaskAnalogRead (void *pvParameters);

void setup() {
  Serial.begin(9600);  
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB, on LEONARDO, MICRO, YUN, and other 32u4 based boards.
  }

    xTaskCreate(
        TaskAnalogRead,
        "AnalogRead",
        128,  // Stack size
        NULL,
        1,  // Priority
        NULL 
    );

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
  // Empty. Processes are done in Tasks.
}


void TaskAnalogRead(void *pvParameters)  // This is a task.
{
  (void) pvParameters;
  
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
*/

  for (;;)
  {
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    vTaskDelay(1000 / portTICK_PERIOD_MS );  // one tick delay (15ms) in between reads for stability
    
  }
}