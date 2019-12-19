#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "PubSubClient.h"

// CONNECTION information to complete
#define IOTHUBNAME "sdis-iot"
#define DEVICEID "john"
#define PWD "SharedAccessSignature sr=sdis-iot.azure-devices.net%2Fdevices%2Fjohn&sig=giaTcb3qA0V2uETziY9NrvY%2Fs74XzSTK3ThjOhaDYOA%3D&se=1576756351"

// computed Host Username and Topic
#define USERNAME IOTHUBNAME ".azure-devices.net/" DEVICEID "/?api-version=2018-06-30"
#define PORT 8883
#define HOST IOTHUBNAME ".azure-devices.net"
#define TOPIC "devices/john/messages/devicebound/#"

WiFiClientSecure espClient;
uint8_t received = 0;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  received = 1;
}

PubSubClient mqtt_client(HOST, PORT, callback, espClient);

void mqttReconnect(){
    while (!mqtt_client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (mqtt_client.connect(DEVICEID,USERNAME,PWD)) {
            Serial.println("connected");
            mqtt_client.subscribe(TOPIC);
            Serial.print("subscribing ");
            Serial.println(TOPIC);
        } else {
            Serial.print("Error: failed with state ");
            Serial.println(mqtt_client.state());
            delay(2000);
        }
    }
    if (received){
        Serial.println("Sending back cenas");
        //mqtt_client.publish("devices/john/messages/", "Thanks!");
        received = 0;
    }
}

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);

    WiFi.begin("raspberrypi", "UJr2016#");

    Serial.print("Connecting");
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();

    Serial.print("Connected, IP address: ");
    Serial.println(WiFi.localIP());
    
    /*if (!MDNS.begin("hello-world-device")) {             // Start the mDNS responder for esp8266.local
        Serial.println("Error setting up MDNS responder!");
    }

    MDNS.addService("mqtt", "tcp", 1883);
    Serial.println("mDNS responder started");*/
    
}

// the loop function runs over and over again forever
void loop() {
    mqttReconnect();
    mqtt_client.loop();
    //MDNS.update();
}