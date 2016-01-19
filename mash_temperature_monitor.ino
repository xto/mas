#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 10

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin(); 
}


void loop(void)
{
  if (Serial.available() > 0) { 
    Serial.read();   
    sensors.requestTemperatures();
    Serial.println(sensors.getTempCByIndex(0)); 
    Serial.flush();
  }
}
