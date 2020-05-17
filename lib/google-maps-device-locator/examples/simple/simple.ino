#include "google-maps-device-locator.h"
#include "SeeedOLED.h"


// Uncomment to show debugging logs
SerialLogHandler logHandler(LOG_LEVEL_TRACE);

GoogleMapsDeviceLocator locator;

SerialLogHandler logHandler;
GoogleMapsDeviceLocator locator;

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
    SeeedOled.putString("GPS");
	locator.withSubscribe(locationCallback).withLocatePeriodic(120);
}


void loop() {
	locator.loop();
}

void locationCallback(float lat, float lon, float accuracy) {
	Serial.printlnf("lat=%f lon=%f accuracy=%f", lat, lon, accuracy);
	SeeedOled.clearDisplay();   // clears the screen and buffer

	// 10 characters fit at text size 2
	SeeedOled.setTextSize(2);
	SeeedOled.setTextColor(WHITE);
	SeeedOled.setCursor(0,0);

	char buf[16];
	snprintf(buf, sizeof(buf), "%.6f", lat);
	SeeedOled.println(buf);

	snprintf(buf, sizeof(buf), "%.6f", lon);
	SeeedOled.println(buf);

	snprintf(buf, sizeof(buf), "%.1f", accuracy);
	SeeedOled.println(buf);

	SeeedOled.display();
}