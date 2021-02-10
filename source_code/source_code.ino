/* Obstacle Avoiding Robot Using Ultrasonic Sensor and Arduino Uno*/

int trigPin = 9;      // trig pin of HC-SR04
int echoPin = 10;     // Echo pin of HC-SR04

int revleft3 = 3;       //REVerse motion of Left motor
int fwdleft2 = 2;       //ForWarD motion of Left motor
int revright8 = 8;      //REVerse motion of Right motor
int fwdright7 = 7;      //ForWarD motion of Right motor

long duration, distance;

void setup() {
  
  delay(random(500,2000));   // delay for random time
  Serial.begin(9600);
  pinMode(revleft3, OUTPUT);      // set Motor pins as output
  pinMode(fwdleft2, OUTPUT);
  pinMode(revright8, OUTPUT);
  pinMode(fwdright7, OUTPUT);
  
  pinMode(trigPin, OUTPUT);         // set trig pin as output
  pinMode(echoPin, INPUT);          //set echo pin as input to capture reflected waves
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);     // send waves for 10 us
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH); // receive reflected waves
  distance = duration / 58.2;   // convert to distance
  Serial.print ("Distance: ");
  Serial.println(distance);
  delay(10);
    // If you dont get proper movements of your robot then alter the pin numbers
  if (distance > 25)            
  { Serial.print ("Distance: ");
    Serial.println(distance);
    digitalWrite(fwdright7, HIGH);                    // move forward
    digitalWrite(revright8, LOW);
    digitalWrite(fwdleft2, HIGH);                                
    digitalWrite(revleft3, LOW);                                                       
  }

  if (distance < 25)
  { Serial.print ("Distance: ");
    Serial.println(distance);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright8, LOW);
    digitalWrite(fwdleft2, LOW);                                
    digitalWrite(revleft3, LOW);
    delay(500);
    digitalWrite(fwdright7, LOW);      //movebackword         
    digitalWrite(revright8, HIGH);
    digitalWrite(fwdleft2, LOW);                                
    digitalWrite(revleft3, HIGH);
    delay(500);
    digitalWrite(fwdright7, LOW);  //Stop                
    digitalWrite(revright8, LOW);
    digitalWrite(fwdleft2, LOW);                                
    digitalWrite(revleft3, LOW);  
    delay(500);  
    digitalWrite(fwdright7, HIGH);       
    digitalWrite(revright8, LOW);   
    digitalWrite(revleft3, LOW);                                 
    digitalWrite(fwdleft2, LOW);  
    delay(500);
  }

}
