#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte server[] = {10, 0, 1, 12};

EthernetClient client;

void setup()
{
	Ethernet.begin(mac);
	Serial.begin(9600);

	if(client.connect(server, 8888)){
		Serial.println("Connected");
	} else {
		Serial.println("Connection failed");
	}

	delay(1000);
}

void loop()
{
	client.println("POST /test.tag.arduino HTTP/1.1");
	client.println("Host: 10.0.1.12:8888");
	// client.println("Connection: close");
	// client.println("Accept: */*");
	client.println("Content-Length: 32");
	client.println("Content-Type: application/json");
	client.println("");
	client.println("{'action':'login','user':2}");
	// Serial.println("Posted");
	delay(1000);
}