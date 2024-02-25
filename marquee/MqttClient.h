// (c) 2020 Gergo Torcsvari
// This code is licensed under MIT license (see LICENSE.txt for details)

#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "libs/ArduinoJson/ArduinoJson.h"

#define MQTT_USER "marquee-scroller"
#define MQTT_PASSWORD "marquee-scroller"

struct PanelFace {
  // 0 - empty, 1 - clock, 2 - binary, 3 - percent, 4 - char
  byte faceType = 0;
  byte percent = 0;
  char character = ' ';
};

class MqttClient
{
  public:
    MqttClient();
    void connect(String url, int port, String topic, String faceTopic, String deviceId);
    String getMessage();
    void loop();
    PanelFace panelFace[8];
    boolean faceModified = false;

  private:
    void callback(char* topic, byte* payload, unsigned int length);
    void reconnect();
    PubSubClient client;
    WiFiClient wifiClient;
    String msg = "";
    boolean connected = false;
    String url = "";
    int port = 0;
    String deviceId = "";
    String mqttDeviceId = "";
    String topic = "";
    String faceTopic = "";
};
