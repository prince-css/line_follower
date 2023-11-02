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
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  forward();
  //delay(10000);

}



void forward()
{
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 200);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 200);
  //Serial.print("f");
}
void backward()
{
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 200);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 200);
  Serial.print("back");
}
void ektu_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 90);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 150);
  Serial.print("er");
}
void vloi_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 180);
  Serial.print("vr");
}

void power_right()
{
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 170);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 170);
  Serial.print("pr");
}
void ektu_left()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 150);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 90);
  Serial.print("el");
}
void vloi_left()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 180);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 0);
  Serial.print("vl");
}

void power_left()
{
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
 analogWrite(13, 170);

  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  analogWrite(8, 170);
  //Serial.print("pl");


}

void Stop()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 0);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 0);
  Serial.print("stop");
}


