#include <NewPing.h>
#define TRIGGER_PIN 10
#define ECHO_PIN 11
#define MAX_DISTANCE 200
int dist;
NewPing myHCSR04(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void setup()
{
	Serial.begin(9600);
	pinMode(6, OUTPUT);
}

void loop()
{
	Serial.println(myHCSR04.ping_cm());
	dist = myHCSR04.ping_cm();
	analogWrite(6, dist);
}

int temp() {	if ((dist < 10) && (dist> 0))

	{
		digitalWrite(6, HIGH);
	}
	else
	{
		digitalWrite(6, LOW);
	}
}
