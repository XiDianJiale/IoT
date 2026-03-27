#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <WebServer.h>
#include <ArduinoJson.h>

const char* ssid = "JialeH";      // 比如 "CMCC-1234" (注意 ESP32 仅支持 2.4G WiFi)
const char* password = "88888888";  // 比如 "12345678"

// const char* backendServerNAME = "http://192.168.222.161:8080/api/sensor/data";
const char* backendServerNAME = "http://20.189.117.142:8080/api/sensor/data";

void setup() {
  Serial.begin(115200);

  // 连接 WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // 连接成功，显示 IP 地址
  Serial.println("");
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {

 if (WiFi.status() == WL_CONNECTED) {

 HTTPClient http;

 

 // 1. 初始化 HTTP 连接

 http.begin(backendServerNAME);

 http.addHeader("Content-Type", "application/json");

 // 2. 构造 Mock 传感器数据 (JSON)

 // 简历亮点：提到使用了 ArduinoJson 进行内存优化型序列化

 JsonDocument doc;

 doc["sensorId"] = "ESP32_DevKitC_01";

 doc["temperature"] = 25.0 + random(0, 100) / 10.0; // 模拟 25.0 - 35.0 波动

 doc["humidity"] = 60 + random(-5, 5);

 doc["timestamp"] = millis();

 String requestBody;

 serializeJson(doc, requestBody);

 // 3. 发送 POST 请求

 Serial.print("Sending POST to server... ");

 int httpResponseCode = http.POST(requestBody);

 if (httpResponseCode > 0) {

 String response = http.getString();

 Serial.println("Response Code: " + String(httpResponseCode));

 Serial.println("Server Response: " + response);

 } else {

 Serial.print("Error on sending POST: ");

 Serial.println(httpResponseCode);

 }

 // 4. 释放资源

 http.end();

 } else {

 Serial.println("WiFi Disconnected");

 }

 // 每 5 秒推送一次数据

 delay(5000);

}