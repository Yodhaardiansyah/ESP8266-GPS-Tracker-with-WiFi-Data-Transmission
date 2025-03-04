
```md
# ESP8266 GPS Tracker with WiFi Data Transmission

This project uses an ESP8266 to read GPS coordinates from a GPS module and send the data to a web server via WiFi.

## Features
- Connects ESP8266 to WiFi.
- Reads GPS data (latitude and longitude).
- Sends GPS coordinates to a web server at regular intervals.
- Uses `TinyGPS++` for GPS parsing.
- Sends HTTP GET requests to a specified URL.

## Components Used
- **ESP8266** (e.g., NodeMCU, Wemos D1 Mini)
- **GPS Module** (e.g., Neo-6M, u-blox)
- **WiFi Connection**

## Wiring (ESP8266 to GPS Module)
| GPS Module Pin | ESP8266 Pin |
|---------------|------------|
| RX (Receive)  | GPIO4 (D2) |
| TX (Transmit) | GPIO5 (D1) |
| VCC           | 3.3V       |
| GND           | GND        |

## Configuration
### WiFi Credentials
Update the following lines in the code with your WiFi details:
```cpp
const char* ssid = "your_wifi_ssid";
const char* password = "your_wifi_password";
```

### Server URL
Ensure the target server (`www.yourwebsite.com`) can receive GPS data via GET requests. Modify this line if needed:
```cpp
String url = "http://www.yourwebsite.com/gpsdata.php?lat=" + latitude + "&lng=" + longitude;
```

## Installation & Setup
1. **Clone the repository**:
   ```bash
   git clone https://github.com/Yodhaardiansyah/ESP8266-GPS-Tracker-with-WiFi-Data-Transmission.git
   ```
2. **Install Required Libraries** in Arduino IDE:
   - `ESP8266WiFi`
   - `SoftwareSerial`
   - `TinyGPS++`
3. **Upload the code** to your ESP8266.
4. **Monitor Serial Output** to check GPS readings and HTTP requests.

## How to Push Code to GitHub
1. Initialize Git in your project folder:
   ```bash
   git init
   ```
2. Add a remote repository:
   ```bash
   git remote add origin https://github.com/Yodhaardiansyah/ESP8266-GPS-Tracker-with-WiFi-Data-Transmission.git
   ```
3. Add all files:
   ```bash
   git add .
   ```
4. Commit changes:
   ```bash
   git commit -m "Initial commit - ESP8266 GPS Tracker"
   ```
5. Push to GitHub:
   ```bash
   git branch -M main
   git push -u origin main
   ```

## Author
**Yodha Ardiansyah**  
📷 Instagram: [@yodhaar_](https://instagram.com/yodhaar_)  

---

Make sure to replace `your_wifi_ssid`, `your_wifi_password`, and `www.yourwebsite.com` with your actual credentials and server URL before uploading your code. 🚀
```
