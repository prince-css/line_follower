int  L3,LF,BL,L2,L1,R1,R2,R3,RF,BR,i,count=0;
int node[3]={0,0,0};
int nod[3]={0,0,0};
int t[3]={0,0,0};
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
      sread();
        if(LF>REF && L3>REF && L2>REF && L1>REF && R1>REF && R2>REF && R3>REF && RF>REF)
       {sread();
        while(!(LF<REF ||L3<REF || L2<REF || L1<REF || R1<REF || R2<REF || R2<REF || R3<REF|| RF<REF))
        {  sread();
          forward();
        } 
        }
        sread();
      if(LF>REF &&L3>REF && L2>REF && L1<REF && R1<REF && R2>REF && R3>REF && RF>REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }

//TEST LEFT
      
      sread();
if(LF>REF && (L3<REF || L2<REF)&& R3>REF && RF>REF)
{
  node[0]=1;
}
sread();
if(LF<REF && RF>REF)
{
  node[1]=1;
  sread();
 if( L2<REF || L1<REF || R1<REF || R2<REF )
 {
  node[2]=1;
 }
}
if(node[0]==1 && node[1]==1 && node[2]==0)
{
  sread();
   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {sread();
   forward(); 
  }
   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;
}
else if(node[0]==1 && node[1]==1 && node[2]==1)
{
  sread();
  while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {sread();
   forward(); 
  }
   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;
}

//TEST LEFT ENDS HERE


      // TEST RIGHT 
      sread();
if(LF>REF && L3>REF && R2<REF&& R3<REF && RF>REF)
{
  node[0]=1;
}
sread();
if(LF>REF && RF<REF)
{
  node[1]=1;
  sread();
 if( L2>REF || L1>REF || R1>REF || R2>REF )
 {
  node[2]=1;
 }
}
if(nod[0]==1 && nod[1]==1 && nod[2]==0)
{
  sread();
   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {sread();
   forward(); 
  }
  forward();
  
   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;
}
else if(node[0]==1 && node[1]==1 && node[2]==1)
{
  sread();
   while(!(LF>REF  && RF>REF))
  {
    sread();
   forward(); 
  }
   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_right();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;
}
//TEST RIGHT ENDS HERE



//TEST '+'
sread();
 if(L3<REF && R3<REF)
 {
 sread();
 t[0]=1;
 
    sread();
    while(!(LF<REF && RF<REF))
    {
      sread();
      Serial.print("piku");
      forward(); 
    }
    sread();
    if(L3<REF || L2<REF || L1<REF|| R2<REF || R3<REF)
    {
      t[1]=1;
    }
    if(t[0]==1 && t[1]==1)
    {
      
    }
    else if(t[0]==1 && t[1]==0)
    {
      Serial.print("hi");
      while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
      {sread();
      power_left();
      Serial.print("hi");
      }
    }
 } 
// //LEFT
//
// 
//      sread();
//  if(LF<REF && RF>REF)
//  {
//   sread();
//   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
//   {sread();
//    forward();
//   
//   }
//   sread();
//   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && (R1<REF || R2<REF) && R3>REF && RF>REF))
//   {
//    sread();
//    power_left();
//   }
//  }
//
// // RIGHT
// if(LF>REF && RF<REF)
//  {
//   sread();
//   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
//   {sread();
//    forward();
//   
//   }
//   sread();
//   while(!(LF>REF && L3>REF && (L2<REF||L1<REF) && R1>REF && R2>REF && R3>REF && RF>REF))
//   {
//    sread();
//    power_right();
//   }
//  }
//      
      
      else if(LF>REF && L3>REF && (L2<REF || L1<REF) && R1>REF && R2>REF && R3>REF && RF>REF)
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      
      else if(LF>REF&&L3>REF && L2>REF && L1>REF&& (R1<REF || R2<REF) && R3>REF&&RF>REF)
      {
        sread();
        ektu_right();
        Serial.print("er\n");
      }




  

  }
  
  }
  //black line
  
//  else if(L3<REF && R3<REF && LF<REF && RF<REF)
//  {
//  while(1)
//  
//  {
//     sread();
//        if(L3>REF && (L2<REF || L1<REF || R1<REF || R2<REF) && R3>REF)
//        {sread();
//          break; 
//        }
//        sread();
////        if(LF<REF && L3<REF && L2<REF && L1<REF && R1<REF && R2<REF && R3<REF && RF<REF)
////        {
////          sread();
////          forward();
////          delay(300);
//        }
//    sread();
//      if(L3<REF && L2<REF && L1>REF && R1>REF && R2<REF && R3<REF)
//      {
//        sread();
//        forward();
//         Serial.print("f\n");
//      }
//      
//      sread();
//      if(L3<REF && (L2>REF && L1<REF) && R1<REF && R2<REF && R3<REF)
//      {
//        sread();
//        ektu_left();
//        Serial.print("el\n");
//      }
//      sread();
//      if(L3<REF && L2<REF && L1<REF&& (R1>REF || R2>REF) && R3<REF)
//      {
//        sread();
//        ektu_right();
//        Serial.print("er\n");
//      }
//      sread();
//      if(LF>REF && L1<REF && R1<REF && RF<REF) 
//      {
//        sread();
//      
//        while(!(L3<REF&&L2<REF&&(L1>REF||R1>REF) && R2<REF && R3<REF))
//        {
//          sread();
//          power_left();
//          Serial.print("pl\n");
//
//        }
//      
//
//        }
//        sread();
//      if(RF>REF && (L1>REF || R1>REF) && LF<REF) 
//      {
//      sread();
//       Serial.print("30r\n");
//      while(L1>REF||R1>REF)
//      {
//        
//        sread();
//        forward();
//         Serial.print("f + pr\n");
//      }
//      if(L1<REF && L2<REF)
//      {
//        sread();
//        while(!((L1>REF||R1>REF)))
//        {
//          sread();
//          L3=L2=R2=R3=0;
//          power_right();
//           Serial.print("pr\n");
//        }
//      }
//      }
//      
//      
//       sread();
//      if(RF<REF && (L1>REF || R1>REF) && LF>REF) 
//      {
//      sread();
//       Serial.print("30l\n");
//      while(L1>REF||R1>REF)
//      {
//        
//        sread();
//        forward();
//         Serial.print("f + pl\n");
//      }
//      if(L1<REF && L2<REF)
//      {
//        sread();
//        while(!((L1>REF||R1>REF)))
//        {
//          sread();
//          L3=L2=R2=R3=0;
//          power_left();
//           Serial.print("pl\n");
//        }
//      }
//      }
//      
//      sread();
//      if(RF>REF && L1<REF && R1<REF && LF<REF) 
//      {
//      sread();
//      
//      while(!(L3<REF&&L2<REF&&(L1>REF||R1>REF) && R2<REF && R3<REF))
//        {
//          sread();
//          power_right();
//           Serial.print("pr\n");
//        }
//      }
//  
//  }
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

  analogWrite(13, 150);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 150);
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

  analogWrite(13, 210);
  digitalWrite(10, LOW);
  digitalWrite(9, HIGH);

  analogWrite(8, 200);
  //Serial.print("pr");
}
void power_left()
{
  digitalWrite(7, LOW);
  digitalWrite(11, HIGH);

  analogWrite(13, 200);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 210);
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

