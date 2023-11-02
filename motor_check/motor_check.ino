void forward();
void backward();
void ektu_right();
void vloi_right();
void purai_right();
void power_right();
void ektu_left();
void vloi_left();
void purai_left();
void power_left();
void sread();
void Stop();


void setup()
{
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);

  Serial.begin(9600);
  while(digitalRead (6)==LOW)
  {
  Serial.println("hi");
  }
}
void loop()

{
  forward();
  
}

void forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 210);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 210);
  Serial.print("f");
}
void backward()
{
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 150);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 150);
  Serial.print("back");
}

void ektu_right()
{
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 150);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 130);
  Serial.print("er");
}
void power_right()
{
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 170);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 180);
  //Serial.print("pr");
}
void power_left()
{
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 180);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 170);
  //Serial.print("pl");
}
void ektu_left()
{
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 130);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 150);
  Serial.print("el");
}

