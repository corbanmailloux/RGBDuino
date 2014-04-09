//PWM pins for the LEDs
#define redpin 9
#define greenpin 10
#define bluepin 11

//set up SoftwareSerial for the bluetooth module.
#include <SoftwareSerial.h>
#define SoftRx 2
#define SoftTx 3
SoftwareSerial BTSerial(SoftRx, SoftTx);

//color variables 
int redvalue=0;
int greenvalue=0;
int bluevalue=0;

void setup(){ 
  //configure pins
  pinMode(SoftRx, INPUT);
  pinMode(SoftTx, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  //check for proper baud rate
  BTSerial.begin(9600);
} 


void loop() {
  //App Inventor sends three bytes (RGB, 0 to 255).
  if ( BTSerial.available() > 2){
    //make sure it's 3 bytes
    if ( BTSerial.available() == 3){
      //read each of the 3 bytes for brightness into the variables
      redvalue=BTSerial.read(); 
      greenvalue=BTSerial.read();
      bluevalue=BTSerial.read();
      //flush the buffer
      BTSerial.flush();
    } 
    else {
      //if the data is not 3 bytes treat it as invalid and flush the buffer.
      BTSerial.flush();
    }
  } 
  //write the current values to the pwm pins.
  analogWrite(redpin, redvalue);
  analogWrite(greenpin, greenvalue);
  analogWrite(bluepin, bluevalue);
}

