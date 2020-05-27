/*
    May 25 2020     Initial
*/
#include <WiFi.h>

String wifiutilsVersion = "wifiutils.cpp May 25 2020, 1.09";

const char* ssid     = "freebox_ponto";
const char* password = "superpassword";

String getWifiUtilsVersion() {
  return wifiutilsVersion;
}

void setupWifi() {
      // Set WiFi to station mode and disconnect from an AP if it was previously connected
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void scanSSID() {
    Serial.println(" scan start");

    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print(")");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    Serial.println("");
}
void getBestSSID(char *SSIDname) {
    char selectedSSID[64] = "";
    int  selectedSSIDlevel = 0
    ;
    int n = WiFi.scanNetworks();
    if (n != 0) {
        for (int i = 0; i < n; ++i) {
          if(strlen(selectedSSID) == 0) {
            strcpy(selectedSSID, WiFi.SSID(i).c_str());
            selectedSSIDlevel = WiFi.RSSI(i);
          } // 1st one ? 
          else {
            if(WiFi.RSSI(i) > selectedSSIDlevel) { // Better level ? 
              strcpy(selectedSSID, WiFi.SSID(i).c_str());
              selectedSSIDlevel = WiFi.RSSI(i);
            }
          }
        }
    }
    strcpy(SSIDname, (strlen(selectedSSID) == 0 ? "NULL" : selectedSSID ));
    return;
}

void testConnection() {
    // Wifi Test ===========================================================================
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    // Print local IP address and start web server
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());


}
