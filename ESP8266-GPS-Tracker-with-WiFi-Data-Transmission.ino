/*
 * ESP8266 GPS Tracker with WiFi Data Transmission
 * 
 * This program reads GPS coordinates using ESP8266 and sends data to a web server via WiFi.
 * 
 * Created by: Yodha Ardiansyah
 * Instagram: @yodhaar_
 */

#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// WiFi credentials (Replace with your own)
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";

// GPS Module RX pin to GPIO4 (D2)
// GPS Module TX pin to GPIO5 (D1)
#define GPS_RX 4
#define GPS_TX 5

SoftwareSerial neogps(GPS_RX, GPS_TX);
TinyGPSPlus gps;

unsigned long previousMillis = 0;
long interval = 60000; // 60 seconds interval for sending data

void setup() {
  Serial.begin(115200);
  neogps.begin(9600);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP()); // Print device IP address
}

void loop() {
  while (neogps.available()) {
    gps.encode(neogps.read());
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    sendGpsToServer();
  }
}

void sendGpsToServer() {
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 2000;) {
    while (neogps.available()) {
      if (gps.encode(neogps.read())) {
        newData = true;
        break;
      }
    }
  }

  if (newData) {
    newData = false;

    String latitude = String(gps.location.lat(), 6);
    String longitude = String(gps.location.lng(), 6);

    Serial.print("Latitude: ");
    Serial.print(latitude);
    Serial.print(" Longitude: ");
    Serial.println(longitude);

    if (latitude != "0.000000") {
      String url = "http://www.yourwebsite.com/gpsdata.php?lat=" + latitude + "&lng=" + longitude;

      Serial.println("Sending data to server: " + url);

      WiFiClient client;
      if (client.connect("www.yourwebsite.com", 80)) {
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: www.yourwebsite.com\r\n" +
                     "Connection: close\r\n\r\n");
        Serial.println("Data successfully sent!");

        delay(100);
        while (client.available()) {
          String line = client.readStringUntil('\r');
          Serial.print(line);
        }
      }
      client.stop();
    }
  }
}
