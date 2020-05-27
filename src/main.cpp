/*
    May 24 2020     Initial
    May 25 2020     Play wifi and ntp...
*/

#include <Arduino.h>
#include <wifiutils.h>

String mainVersion = "main.cpp/ESP32 May 25 2020, 1.20";

void setup() {

    // put your setup code here, to run once:
    
    Serial.begin(9600);
    Serial.println();
    Serial.println(mainVersion.c_str());
    Serial.println(getWifiUtilsVersion().c_str());
    scanSSID();     // Check for WIFI networks
}


void loop() {
    char SSIDname[64];
    // Wait a bit before scanning again
    getBestSSID(SSIDname);
    Serial.print("Best Identified network :");
    Serial.println(SSIDname);
    delay(5000);
}