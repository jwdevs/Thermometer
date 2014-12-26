/*
 Software serial multple serial test
 
 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 
 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)
 
 Note:
 Not all pins on the Mega and Mega 2560 support change interrupts,
 so only the following can be used for RX:
 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
 
 Not all pins on the Leonardo support change interrupts,
 so only the following can be used for RX:
 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).
 
 created back in the mists of time
 modified 25 May 2012
 by Tom Igoe
 based on Mikal Hart's example
 
 This example code is in the public domain.
 
 */
#include <SoftwareSerial.h>
#include  <JeeLib.h>// Low power functions library
#include <math.h>
SoftwareSerial xbee(6, 7); // RX, TX

//Temperature sensor
#include "TSIC.h"       // include the library

#define TEMP_VCC 4
#define TEMP_SIG 5
#define INVALID_TEMP -255
#define XBEE_SLEEP_PIN 2
// instantiate the library, representing the sensor
TSIC Sensor1(TEMP_SIG,TEMP_VCC);    // Signalpin, VCCpin
//TSIC Sensor2(5, 2);  // Signalpin, VCCpin, NOTE: we can use the same VCCpin to power both sensors

uint16_t temperature = 0;
float tempInC = 0;

ISR(WDT_vect) { Sleepy::watchdogEvent(); } // Setup the watchdog

float readTemp() {
    float temp = 0;
    int retry = 0;
    bool ok = false;
    while(retry++<5 && !(ok=Sensor1.getTemperture(&temperature)));
    if (ok) {
        temp = Sensor1.calc_Celsius(&temperature);
        if(temp > -10 && temp < 40) {
            return temp;
        }
    }
    return INVALID_TEMP;
}


void setup()
{
    // Open serial communications and wait for port to open:
    //Serial.begin(9600);
    // set the data rate for the SoftwareSerial port
    xbee.begin(9600);
    pinMode(8, OUTPUT);
    pinMode(XBEE_SLEEP_PIN,OUTPUT);
    digitalWrite(XBEE_SLEEP_PIN, HIGH);
}

void sendMessage(float temp) {
    digitalWrite(XBEE_SLEEP_PIN, LOW);
    digitalWrite(8,HIGH);
    delay(50);
    xbee.print(F("{1;1;"));
    xbee.print(temp);
    xbee.print(F("}"));
    
     delay(50);
    digitalWrite(8, LOW);
    digitalWrite(XBEE_SLEEP_PIN, HIGH);
}

bool diodeOn = false;
float lastTemp = 20;
void loop() // run over and over
{
    
    
    tempInC = readTemp();
    //tempInC = 21;
    if(tempInC != INVALID_TEMP && fabsf(tempInC - lastTemp) < 15.0) {
        sendMessage(tempInC);
        lastTemp = tempInC;
    }
    //Serial.println("Temperature read:");
    //Serial.println(tempInC++);
    
    /*if(diodeOn == true) {
        digitalWrite(8, LOW);
        diodeOn = false;
    } else {
        digitalWrite(8,HIGH);
        diodeOn = true;
    }*/
    Sleepy::loseSomeTime(30000);
    //Sleepy::loseSomeTime(1000);
    //Narcoleptic.delay(5000);
    //delay(5000);
}
