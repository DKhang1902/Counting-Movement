const int trigPin = 11;
const int echoPin = 12;
int count = 0;
int lastdistance = 0;
int distance = 0;
unsigned long duration;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

int getDistance(){
//Sets teh trigPin on HIGH state for 10 micro seconds
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 //Read the echoPin, returns the sound wave travel time in microseconds
 duration = pulseIn(echoPin, HIGH);

 distance = duration * 0.034 /2;
 return distance;
}

void printResult(int num,int dist,int last){
  Serial.print("The count: ");
  Serial.println(num);
  Serial.print(dist);
  Serial.print("   ");
  Serial.println(last);
}


void loop(){
  //Clear the trig Pin
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 
distance = getDistance();
 
if (distance <30 && lastdistance > 150){
  count+=1;
printResult(count, distance, lastdistance);
}
delay(20);
lastdistance = distance;

}
