#include <SoftwareSerial.h>

int vs = 10;
int flags = 0;
int flags1 = 0;

// defines pins numbers
const int trigPin = 3;
const int echoPin = 2;
const int ledPin = 6;
const int ledPin1 = 5;

// defines variables
long duration;
int distance;
int safetyDistance;

SoftwareSerial BTserial(9, 8); // RX | TX

void setup() 
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(ledPin, OUTPUT);
    pinMode(ledPin1, OUTPUT);
    
    Serial.begin(9600);
    Serial.println("---------------Slave Node------------------");
    
    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(38400);  
}

void loop()
{
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  safetyDistance = distance;
  if (safetyDistance <= 50){
    digitalWrite(ledPin, HIGH);
    digitalWrite(ledPin1, LOW);
  }
  else{
    digitalWrite(ledPin, LOW);
    digitalWrite(ledPin1, HIGH);
  }
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  
  long measurement = vibration();
  delay(50);
  Serial.print("Vibration: ");
  Serial.println(measurement);
  if(measurement > 50) {
     alertMsg(); }
  
  //delay(60000); //instead of delay, we will use vib sensor, >50
  //alertMsg();
}


void alertMsg(){
  if(flags == 0){
    BTserial.println("---------------------------------------------");
    BTserial.println("Accident Detected!!");
    BTserial.println("Name: Siddhesh Dhoke");
    BTserial.println("Blood Group: B+");
    BTserial.println("Contact Number: 7445000111");
    BTserial.println("Car No.: MH 02 AE 5464");
    BTserial.println("---------------------------------------------");
    //flags++;
  }
}

long vibration() {
  long measurement = pulseIn(vs, HIGH); //do changes here
  return measurement;  
}
