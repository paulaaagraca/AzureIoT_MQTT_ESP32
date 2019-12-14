#include <Arduino.h>
#include <WiFiClientSecure.h>
#include "PubSubClient.h"

// CONNECTION information to complete
#define IOTHUBNAME "sdis-iot"
#define DEVICEID "john"
#define PWD "SharedAccessSignature sr=sdis-iot.azure-devices.net%2Fdevices%2Fjohn&sig=5vTlzVoSonyrGQinvYmlzBx9SRXubdCqpODXBUpkTys%3D&se=1576341172"

// computed Host Username and Topic
#define USERNAME IOTHUBNAME ".azure-devices.net/" DEVICEID "/?api-version=2018-06-30"
#define PORT 8883
#define HOST IOTHUBNAME ".azure-devices.net"
#define TOPIC "devices/john/messages/#"

WiFiClientSecure espClient;
char* received;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  received = topic;
}

PubSubClient mqtt_client(HOST, PORT, callback, espClient);

void mqttReconnect(){
    while (!mqtt_client.connected()) {
        Serial.println("Connecting to MQTT...");
        if (mqtt_client.connect(DEVICEID,USERNAME,PWD)) {
            Serial.println("connected");
            if(DEVICEID == "gonca"){
                mqtt_client.publish(TOPIC, "helloworld");
                Serial.println("publishing");
            }
            else{
                mqtt_client.subscribe(TOPIC);
                Serial.print("subscribing ");
                Serial.println(TOPIC);
            }
        } else {
            Serial.print("Error: failed with state ");
            Serial.println(mqtt_client.state());
            delay(2000);
        }
    }
    if (received != NULL){
        Serial.println("Sending back cenas");
        //mqtt_client.publish(received, "Thanks!");
        received = NULL;
    }
}

// the setup function runs once when you press reset or power the board
void setup() {
    Serial.begin(115200);

    WiFi.begin("Network Error", "toortoor");

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