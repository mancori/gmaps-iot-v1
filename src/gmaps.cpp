/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/manuel/IoT_maps/gmaps-iot-v1/src/gmaps.ino"
#include <google-maps-device-locator.h>
#include "SeeedOLED.h"

void setup();
void updateTime();
void locationCallback(float lat, float lon, float accuracy);
void loop();
#line 4 "/Users/manuel/IoT_maps/gmaps-iot-v1/src/gmaps.ino"
GoogleMapsDeviceLocator locator;
int hour=0;
int minutes=0;
int lastMinute=0;

void setup() {
    Serial.begin(9600);
	  Wire.begin();
    SeeedOled.init();  	
 	  SeeedOled.clearDisplay();
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode(); 
    SeeedOled.setTextXY(2, 0);
    SeeedOled.putString("GPS v1.3");
    locator.withEventName("deviceLocator");
    locator.withSubscribe(locationCallback).withLocatePeriodic(30);
    Time.zone(+7);
    lastMinute = Time.minute();
}

void updateTime()
{ 
hour = Time.hourFormat12();
minutes = Time.minute();
if (lastMinute +1 == minutes ){
 	  SeeedOled.clearDisplay();
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode();
    SeeedOled.setTextXY(4,5);
    SeeedOled.putNumber(hour);
    SeeedOled.putString(":");
    if(minutes<10 ){
       SeeedOled.putNumber(0); 
       SeeedOled.putNumber(minutes); 
    }
    SeeedOled.putNumber(minutes); 
    lastMinute = minutes;
}
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode();
    SeeedOled.setTextXY(4,5);
    SeeedOled.putNumber(hour);
    SeeedOled.putString(":");
    if(minutes<10 ){
       SeeedOled.putNumber(0); 
       SeeedOled.putNumber(minutes); 
    }
    SeeedOled.putNumber(minutes); 
}

void locationCallback(float lat, float lon, float accuracy) {
  // Handle the returned location data for the device. This method is passed three arguments:
  // - Latitude
  // - Longitude
  // - Accuracy of estimated location (in meters)
}

void loop() {
  locator.loop();
  updateTime();
}
            
