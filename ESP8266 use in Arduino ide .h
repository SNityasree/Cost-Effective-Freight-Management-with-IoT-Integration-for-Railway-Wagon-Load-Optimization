#include <ESP8266WiFi.h>  // Include the ESP8266 WiFi library

void setup() {
  Serial.begin(115200);  // Start serial communication at 115200 baud rate

  // Set WiFi to Station (client) mode and disconnect from any previously connected network
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
}

void loop() {
  Serial.println("scan start");

  // Scan for available networks and return the number of networks found
  int n = WiFi.scanNetworks();
  Serial.println("scan done");

  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.println(String(n) + " networks found");
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI (signal strength) for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.println(" dBm)");
    }
  }

  Serial.println("");  // Print a newline for spacing
  delay(5000);         // Wait 5 seconds before next scan
}
