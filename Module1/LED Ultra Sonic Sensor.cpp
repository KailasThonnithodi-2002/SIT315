// initalise the variables
const int RED = 4;
const int YELLOW = 5;
const int GREEN = 6;

const int TRIG = 2;
const int ECHO = 3;

const int MAX = 200;
const int MIN = 100;

void setup()
{
  // basic leds (the closer the object, it will bling red
  // the further the object, the more it will blink green
  // if in between the specified min and max, then yellow
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  // ultra sonic sensor requirements
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}


long distance () 
{
  long echo_read;
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // returning the distance from the echo record
  // ultra sonic send signal like a bat and relays the 
  // the distance based on the trigger, then echo which returns
  echo_read = pulseIn(ECHO, HIGH);
  return echo_read * 0.034 / 2;
}


void led_distance() 
{
  if (distance() >= MAX) 
  {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);
  }
  else if (distance() < MAX && distance() > MIN)
  {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, HIGH);
    digitalWrite(GREEN, LOW);
  }
  else 
  {
    digitalWrite(RED, LOW);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, HIGH);
  }
}


void loop()
{
  delay(100);
  Serial.print("Distance: " + String(distance()));
  led_distance();
  Serial.println();
}
