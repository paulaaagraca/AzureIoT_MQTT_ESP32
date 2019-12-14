// Access IoTHub via MQTTT Protocol with mosquitto library (no IoT SDK used)
//

#include <cstdio>
#include <fstream>
#include "mosquitto.h"

#define COUNT 3

// CONNECTION information to complete
#define IOTHUBNAME "sdis-iot"
#define DEVICEID "gonca"
#define PWD "SharedAccessSignature sr=sdis-iot.azure-devices.net%2Fdevices%2Fgonca&sig=WNUBJhrl%2F%2BjyQ%2FQOxhOOfrrMVtogzPivAYvTRrn9Wb8%3D&se=1576257247"


#define CERTIFICATEFILE "IoTHubRootCA_Baltimore.pem"

// computed Host Username and Topic
#define USERNAME IOTHUBNAME ".azure-devices.net/" DEVICEID "/?api-version=2018-06-30"
#define PORT 8883
#define HOST IOTHUBNAME ".azure-devices.net"
#define TOPIC "devices/" DEVICEID "/messages/events/"

int main()
{
	int rc;
	
    struct mosquitto_message *msg;

	mosquitto_lib_init();

	rc = mosquitto_subscribe_simple(
			&msg, COUNT, true,
			"devices/#", 0,
			HOST, PORT,
			DEVICEID, 60, true,
			USERNAME, PWD,
			NULL, NULL);

	if(rc){
		printf("Error: %s\n", mosquitto_strerror(rc));
		mosquitto_lib_cleanup();
		return rc;
	}

	for(int i=0; i<COUNT; i++){
		printf("%s %s\n", msg[i].topic, (char *)msg[i].payload);
		mosquitto_message_free_contents(&msg[i]);
	}
	free(msg);

	mosquitto_lib_cleanup();

	return 0;
}
