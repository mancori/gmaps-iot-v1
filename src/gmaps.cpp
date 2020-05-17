/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/manuel/IoT_maps/gmaps/src/gmaps.ino"
#include "google-maps-device-locator.h"
#include "SeeedOLED.h"

 

// Uncomment to show debugging logs
//SerialLogHandler logHandler(LOG_LEVEL_TRACE);
void setup();
void updateDisplay();
void loop();
#line 8 "/Users/manuel/IoT_maps/gmaps/src/gmaps.ino"
GoogleMapsDeviceLocator locator;
int hour=0;
int minutes=0;

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
    SeeedOled.putString("GPS v3.1");
    locator.withEventName("deviceLocator");
    locator.withSubscribe(locationCallback).withLocatePeriodic(120);
    Time.zone(+7);
}

void updateDisplay()
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

void loop() {
	locator.loop();
    updateDisplay();
}

void locationCallback(float lat, float lon, float accuracy) {
  Serial.println("LocationCallback()");
	  Serial.printlnf("lat=%f lon=%f accuracy=%f", lat, lon, accuracy);
	SeeedOled.clearDisplay();   // clears the screen and buffer

	// 10 characters fit at text size 2

	char buf[16];
	snprintf(buf, sizeof(buf), "%.6f", lat);
  //SeeedOled.putString(buf, sizeof(buf), "%.6f", lat);
	snprintf(buf, sizeof(buf), "%.6f", lon);
  //SeeedOled.putString(buf, sizeof(buf), "%.6f", lon);
	snprintf(buf, sizeof(buf), "%.1f", accuracy);
  //SeeedOled.putString(buf);
}