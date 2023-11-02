int  L3,LF,BL,L2,L1,R1,R2,R3,RF,BR;
int REF=500;
void forward();
void backward();
void ektu_left();
void vloi_left();
void purai_left();
void power_left();
void ektu_right();
void vloi_right();
void purai_right();
void power_right();
void sread();
void Stop();


void setup()
{


 // pinMode(A11, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
 // pinMode(A10, INPUT);
  
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
        sread();
      if(L3>REF && L2>REF && L1<REF && R1<REF && R2>REF && R3>REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }
      
      sread();
      if(L3>REF && (L2<REF && L1>REF) && R1>REF && R2>REF && R3>REF)
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      sread();
      if(L3>REF && L2>REF && L1>REF&& (R1<REF || R2<REF) && R3>REF)
      {
        sread();
        ektu_right();
        Serial.print("er\n");
      }
      sread();
      if(LF<REF && RF>REF) 
      {
        sread();
      
        while(!(L3>REF&&L2>REF&&(L1<REF||R1<REF) && R2>REF && R3>REF))
        {
          sread();
          power_left();
          Serial.print("pl\n");

        }
      Serial.println("power Left");

        }
      
      sread();
      if(RF<REF && LF>REF) 
      {
      sread();
      
      while(!(L3>REF&&L2>REF&&(L1<REF||R1<REF) && R2>REF && R3>REF))
        {
          sread();
          power_right();
           Serial.print("pr\n");
        }
      }
      sread();
  if(L3<REF && L2<REF && L1<REF && R1<REF && R2<REF && R3<REF)
  {
    sread();
    forward();
    Serial.println("t");
  }

}

void sread()
{
  //BL = analogRead(A9);
  LF = analogRead(A1);
  L3 = analogRead(A2);
  L2 = analogRead(A3);
  L1 = analogRead(A4);
  R1 = analogRead(A5);
  R2 = analogRead(A6);
  R3 = analogRead(A8);
  RF = analogRead(A9);
  //BR = analogRead(A10);


}
void forward()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 120);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 120);
  
}
void backward()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 120);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 120);
  Serial.print("back\n");
}
void ektu_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 100);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 0);
 
}
void vloi_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 70);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 120);
  Serial.print("vr\n");
}

void power_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 120);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 120);

}
void ektu_left()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 0);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 100);
 
}
void vloi_left()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 120);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 70);
  Serial.print("vl\n");
}

void power_left()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 120);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 120);
 

}

void Stop()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 0);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 0);
  Serial.print("stop\n");
}


