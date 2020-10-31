# Publisher-Subscriber MQTT for Azure IoT Hub
This project builds a IoT prototype that uses a publisher-subcriber messaging pattern to connect sensor nodes. Azure IoT Hub is used as a MQTT broker and the sensor nodes are ESP32 devices.

1) [Starting Guide](#guide)
2) [Organization](#org)
2) [Support Materials](#materials)

## Starting Guide <a name="guide"></a>

The implemented system consists in a **MQTT publisher-subscriber communication system with Azure IoT Hub**.

The [document](https://github.com/paulaaagraca/AzureIoT_MQTT_ESP32/tree/master/docs) serves as a Starting Guide for the developed project in the course Distributed Systems.

## Organization

All files corresponding to the ESP32 implementation are present in [esp-azure](https://github.com/paulaaagraca/AzureIoT_MQTT_ESP32/tree/master/esp-azure). 

[pc](https://github.com/paulaaagraca/AzureIoT_MQTT_ESP32/tree/master/pc) contains all files corresponding to the implemented communication service between the cloud and the ESP32.

## Support Materials <a name="materials"></a>

**Azure IoT**
- [Communicate with your IoT hub using the MQTT protocol](https://docs.microsoft.com/en-us/azure/iot-hub/iot-hub-mqtt-support)
- [Azure IoT Hub MQTT Connection](https://www.opc-router.com/azure-iot-hub-mqtt-connection/#AzureIoTHubMQTTClientConfiguration)

**ESP32**
- [ESP Azure IoT SDK](https://github.com/espressif/esp-azure?fbclid=IwAR2gINJAbW_89AL0iq2T_c0TRb_Q0TVUISU9mHSa_gzrqex24haVat85E0s)
- [ESP32_AzureIoT - Azure IoT Hub library for esp32 devices in Arduino](https://github.com/VSChina/ESP32_AzureIoT_Arduino)
