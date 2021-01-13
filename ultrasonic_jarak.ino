// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
//const int buzzer = 11;
const int ledPin = 7;

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  //pinMode(buzzer, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600); // Starts the serial communication
}


void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance, 0.034 dari 340 * 10^-6 (ubah ms to s)* 100 (ngubah m/s ke cm/s)
  //bagi 2 karena sinyal suara berangkat sampe pulang
  distance= duration*0.034/2;
  
  safetyDistance = distance;
  if (safetyDistance <= 15){
    //digitalWrite(buzzer, HIGH);
    digitalWrite(ledPin, HIGH);
  }
  else{
   // digitalWrite(buzzer, LOW);
    digitalWrite(ledPin, LOW);
  }
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distance); 
}
