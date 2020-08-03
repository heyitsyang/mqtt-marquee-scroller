

#pragma once
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "libs/ArduinoJson/ArduinoJson.h"


class MqttClient
{
  public:
    MqttClient();
    void connect(String url, int port, String topic, String deviceId);
    String getMessage();
    void loop();

  private:
    void callback(char* topic, byte* payload, unsigned int length);
    PubSubClient client;
    WiFiClient wifiClient;
    String msg = "";
    boolean connected = false;
};
