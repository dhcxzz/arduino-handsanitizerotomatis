// defines pins numbers
const int trigPin = A2;
const int echoPin = A1;
#define PUMP 4
#define LED 3
long duration;
int distance;

void setup() {
 
    pinMode(PUMP,OUTPUT);
    pinMode(LED,OUTPUT);
    digitalWrite(LED,HIGH); 
    pinMode(trigPin, OUTPUT); 
    pinMode(echoPin, INPUT); 

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

    // Calculating the distance
    distance= duration*0.034/2;
    delay(10);

    if(distance !=0 && distance<10)
    {
        digitalWrite(PUMP,LOW);
        delay(250);
        digitalWrite(PUMP,HIGH);
        delay(1200);
    }
    else
    {
        digitalWrite(PUMP,HIGH); 
    }
}
