// since the interrupt function does not properly function on 
// the ulra sonic sensor (due to no library imports and since)
// the sensor does not support the interrupt procedure, i will use the motion detector instead

int RED = 3;

int COUNT = 0;
const int ms = 2;

void setup()
{
  Serial.begin(9600);
  pinMode(ms, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(ms), toggle, RISING);
}

void toggle()
{
  digitalWrite(RED, HIGH);
  Serial.println("Detected");
}

void loop()
{
  COUNT += 1;
  Serial.println("Iteration " + String(COUNT));
  
  // the delay is pretending to compile another program.
  delay(10000);
}
