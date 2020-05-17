/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/manuel/IoT_maps/gmaps-iot-v1/src/gmaps.ino"
#include "google-maps-device-locator.h"
#include "SeeedOLED.h"

 

// Uncomment to show debugging logs
//SerialLogHandler logHandler(LOG_LEVEL_TRACE);
void setup();
void updateTime();
void customPubish();
void loop();
#line 8 "/Users/manuel/IoT_maps/gmaps-iot-v1/src/gmaps.ino"
GoogleMapsDeviceLocator locator;
int hour=0;
int minutes=0;
int lastMinute=-1;

// SYSTEM_THREAD(ENABLED);

void locationCallback(float lat, float lon, float accuracy);

void setup() {
 	  Serial.begin(9600);
	  Wire.begin();
    SeeedOled.init();  	
 	  SeeedOled.clearDisplay();
    SeeedOled.setNormalDisplay();
    SeeedOled.setPageMode(); 
    SeeedOled.setTextXY(2, 0);
    SeeedOled.putString("GPS v5.1");
    locator.withEventName("deviceLocator");
    locator.withSubscribe(locationCallback).withLocatePeriodic(120);
    Time.zone(+7);
}

void updateTime()
{
Time.now();    
hour = Time.hourFormat12();
minutes = Time.minute();
SeeedOled.setNormalDisplay();
SeeedOled.setPageMode();
SeeedOled.setTextXY(4,5);
SeeedOled.putNumber(hour);
SeeedOled.putString(":");
SeeedOled.putNumber(minutes);
}

void customPubish(){
  Particle.publish("location",Time.minute );
}
void loop() {
	  locator.loop();
    updateTime();
}

void locationCallback(float lat, float lon, float accuracy) {
}