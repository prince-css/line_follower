int  L3,LF,BL,L2,L1,R1,R2,R3,RF,BR,i,count=0;
int REF=600;
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
//void Stop();


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
//  pinMode(A10, INPUT);
  
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
  sread();
  if(L3>REF && R3>REF &&LF>REF && RF>REF)
  {
  while(1)  
  {
        sread();
        if(L3<REF && (L2>REF || L1>REF || R1>REF || R2>REF) && R3<REF)
        {sread();
          break; 
        }
//        sread();
//        if(LF>REF && L3>REF && L2>REF && L1>REF && R1>REF && R2>REF && R3>REF && RF>REF)
//        {
//          sread();
//          forward();
//          delay(300);
//        }
        sread();
      if(L3>REF && L2>REF && L1<REF && R1<REF && R2>REF && R3>REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }
      
      
      sread();
      if((L3>REF &&(L2<REF || L1<REF) && R1>REF && R2>REF && R3>REF))
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
         }
        Serial.print("er\n");
      }


//power left
      
      sread();
      if(LF<REF) 
      {
        sread();
        while(!(RF>REF &&L2>REF && L1>REF && R1>REF&&R2>REF))
        {
          sread();
          forward();
        }
        while(!(L3>REF&&L2>REF&&(L1<REF&&R1<REF) && R2>REF && R3>REF))
        {
          sread();
          //L3=L2=R2=R3=1023;
          power_left();
          Serial.print("pl\n");

        }
        }

       
//POWER right

      sread();
      if(RF<REF) 
      {
        sread();
        while(!(RF>REF &&L2>REF && L1>REF && R1>REF&&R2>REF))
        {
          sread();
          forward();
        }
      
      while(!(L3>REF&&L2>REF&&(L1<REF&&R1<REF) && R2>REF && R3>REF))
        {
          sread();
          //L3=L2=R2=R3=1023;
          power_right();
           Serial.print("pr\n");
        }
      }
  

  }
  
  

  //black line
  
  else if(L3<REF && R3<REF && LF<REF && RF<REF)
  {
  while(1)
  
  {
     sread();
        if(L3>REF && (L2<REF || L1<REF || R1<REF || R2<REF) && R3>REF)
        {sread();
          break; 
        }
        sread();
//        if(LF<REF && L3<REF && L2<REF && L1<REF && R1<REF && R2<REF && R3<REF && RF<REF)
//        {
//          sread();
//          forward();
//          delay(300);
        }
    sread();
      if(L3<REF && L2<REF && L1>REF && R1>REF && R2<REF && R3<REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }
      
      sread();
      if(L3<REF && (L2>REF && L1<REF) && R1<REF && R2<REF && R3<REF)
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      sread();
      if(L3<REF && L2<REF && L1<REF&& (R1>REF || R2>REF) && R3<REF)
      {
        sread();
        ektu_right();
        Serial.print("er\n");
      }
      sread();
      if(LF>REF && L1<REF && R1<REF && RF<REF) 
      {
        sread();
      
        while(!(L3<REF&&L2<REF&&(L1>REF||R1>REF) && R2<REF && R3<REF))
        {
          sread();
          power_left();
          Serial.print("pl\n");

        }
      

        }
        sread();
      if(RF>REF && (L1>REF || R1>REF) && LF<REF) 
      {
      sread();
       Serial.print("30r\n");
      while(L1>REF||R1>REF)
      {
        
        sread();
        forward();
         Serial.print("f + pr\n");
      }
      if(L1<REF && L2<REF)
      {
        sread();
        while(!((L1>REF||R1>REF)))
        {
          sread();
          L3=L2=R2=R3=0;
          power_right();
           Serial.print("pr\n");
        }
      }
      }
      
      
       sread();
      if(RF<REF && (L1>REF || R1>REF) && LF>REF) 
      {
      sread();
       Serial.print("30l\n");
      while(L1>REF||R1>REF)
      {
        
        sread();
        forward();
         Serial.print("f + pl\n");
      }
      if(L1<REF && L2<REF)
      {
        sread();
        while(!((L1>REF||R1>REF)))
        {
          sread();
          L3=L2=R2=R3=0;
          power_left();
           Serial.print("pl\n");
        }
      }
      }
      
      sread();
      if(RF>REF && L1<REF && R1<REF && LF<REF) 
      {
      sread();
      
      while(!(L3<REF&&L2<REF&&(L1>REF||R1>REF) && R2<REF && R3<REF))
        {
          sread();
          power_right();
           Serial.print("pr\n");
        }
      }
  
  }
  }

void sread()
{
    RF=analogRead(A1);
    R3=analogRead(A2);
    R2=analogRead(A3);
    R1=analogRead(A4);
    L1=analogRead(A5);
    L2=analogRead(A6);
    L3=analogRead(A8);
    LF=analogRead(A9);


}
void forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 95);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 135);
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

  analogWrite(13, 150);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 200);
  Serial.print("pr");
}
void power_left()
{
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 200);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 150);
  Serial.print("pl");
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

