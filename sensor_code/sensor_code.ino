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


  pinMode(A11, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  pinMode(A10, INPUT);
  
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
//black line in white surface

sread();
if(BL>REF&&L3>REF&&L2>REF && L1<REF && R1<REF && R2>REF&&R3>REF&&BR>REF)
{

  Serial.println("f");

forward();
  
}

#//FINDING "L"
sread();
if(BL<REF&&BR>REF)
{
sread();

  while(!(L3>REF&&L2>REF && L1<REF && R1<REF && R2>REF&&R3>REF))
  {
    Serial.println("THIS IS L POINT AND GOING TO LEFT");
     sread();
    power_left();

  }

}


#//FOLLOWING THE LINE FLUENTLY
  sread();
  if(L3>REF&&L2<REF&&L1<REF&&R1>REF&&R2>REF&&R3>REF)

{
  sread();

    Serial.println("ektu left");

  ektu_left();

}
sread();
 if(L3>REF&&L2<REF&&L1>REF&&R1>REF&&R2>REF&&R3>REF)

{
  sread();

    Serial.println("arektu left");

  ektu_left();

}
sread();
if(L3>REF&&L2>REF&&L1>REF&&R1<REF&&R2<REF&&R3>REF)

{
  sread();
  Serial.println("ektu right");

  ektu_right();


}
sread();
if(L3>REF&&L2>REF&&L1>REF&&R1>REF&&R2<REF&&R3>REF)

{
  sread();
  Serial.println("arektu right");

  ektu_right();


}


#//FINDING "R"
sread();
 if(BL>REF&&BR<REF)
{
 sread();
while(!(L3>REF&&L2>REF&&L1<REF&&R1<REF&&R2>REF&&R3>REF))
  {
    Serial.println("THIS IS R POINT AND GOING TO RIGHT");
     sread();
     
    power_right();
  }
  }



#//FINDING "T" 


sread();
if(((L3<REF&&R3<REF)||(L3<REF&&RF<REF)||(LF<REF&&R3<REF)||(LF<REF&&RF<REF))&&L2<REF&&L1<REF&&R1<REF&&R2<REF)
{
 
  sread();
  while(!(L3>REF&&L2>REF && L1<REF && R1<REF && R2>REF&&R3>REF))
  {
    Serial.println("THIS IS 'T' POINT AND GOING TO LEFT");
     sread();
    power_left();

  }

}


#//FINDING 'END POINT'

sread();
if(L3<REF&&LF<REF&&BL<REF&&L2<REF&&L1<REF&&R1<REF&&R2<REF&&R3<REF&&RF<REF&&BR<REF)
{
    sread();
    Stop();

}




}

void sread()
{
  BL = analogRead(A9);
  LF = analogRead(A6);
  L3 = analogRead(A11);
  L2 = analogRead(A1);
  L1 = analogRead(A2);
  R1 = analogRead(A3);
  R2 = analogRead(A4);
  R3 = analogRead(A5);
  RF = analogRead(A8);
  BR = analogRead(A10);


}
void forward()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 200);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 200);
  Serial.print("f");
}
void backward()
{
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 200);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 200);
  Serial.print("back");
}
void ektu_right()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 0);
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
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 170);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);

  analogWrite(12, 170);
  Serial.print("pr");
}
void ektu_left()
{
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);

  analogWrite(13, 150);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 0);
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
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);

  analogWrite(13, 170);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);

  analogWrite(12, 170);
  Serial.print("pl");


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
