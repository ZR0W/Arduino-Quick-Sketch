// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

//led indicator pin
const int ledPin = 7;

// defines variables
long duration;
int distance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(ledPin, OUTPUT); //Sets the ledPin as an Output
  Serial.begin(9600); // Starts the serial communication
  }

void loop() {
  digitalWrite(ledPin, LOW); //reset led
  
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH); //time in micro seconds
  
  // Calculating the distance
  distance= duration*0.034/2; //0.034 cm/micro second
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance(cm): ");
  Serial.println(distance);
  if(distance < 10){
    digitalWrite(ledPin, HIGH);
  }
  delay(100);
}
