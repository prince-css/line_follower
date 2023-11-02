int  L3,LF,BL,L2,L1,R1,R2,R3,RF,BR,i=0,count=0,L,R,LL=0,RR=0,khali=0;;
int maximum[8]={800,800,800,800,800,800,800,800};
int minimum[8]={600,600,600,600,600,600,600,600};
int REF[8]={600,600,600,600,600,600,600,600};
int node[3]={0,0,0};
int nod[3]={0,0,0};
int t[3]={0,0,0};
//int REF=600;
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
void s_forward();
void check();
void calibration();
void stops();


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
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(34, INPUT);
  pinMode(35, INPUT);

Serial.begin(9600);
calibration();
stops();
  while(digitalRead (6)==LOW)
  {
  Serial.println("hi");
  }
}
void loop()
{
 forward();
 khali=0;
  sread();
  if(L3>REF[1] && R3>REF[6] &&LF>REF[0] && RF>REF[7])
  {
  while(1)  
  {

    // only L3 R3 check

    
   
    //check ends here
        sread();
        if(L3<REF[1] && (L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5]) && R3<REF[6])
        {sread();
          break; 
        }
      sread();
        if(LF>REF[0] && L3>REF[1] && L2>REF[2] && L1>REF[3] && R1>REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7])
       {sread();
       for(khali=0;khali<=200;khali++)
       {
       if(khali==200)
          {
            digitalWrite(2,HIGH);
            if(digitalRead(30)==HIGH)
            {
              forward();
            }
            else if(digitalRead(31)==HIGH)
            {
              ektu_left();
            }
            else if(digitalRead(32)==HIGH)
            {
              ektu_right();
            }
             else if(digitalRead(33)==HIGH)
            {
              forward();
              delay(150);
              
              power_left();
              delay(250);
              forward();
              delay(200);
            }
            else if(digitalRead(34)==HIGH)
            {
              forward();
              delay(150);
              
              power_right();
              delay(250);
              forward();
              delay(200);
            } 
            else if(digitalRead(35)==HIGH)
            {
              forward(); 
            }
          }
       }
          }
        while(!(LF<REF[0] ||L3<REF[1] || L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5] || R2<REF[5] || R3<REF[6]|| RF<REF[7]))
        {  sread();
          forward();
          //khali++;
          
        } 
        }
        sread();
      if(LF>REF[0] &&L3>REF[1] && L2>REF[2] && L1<REF[3] ||R1<REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7])
      {
        sread();
        forward();
         Serial.print("f\n");
      }

//TEST LEFT
      
      sread();
if(LF>REF[0] && L3<REF[1] && R3>REF[6] && RF>REF[7])
{
  node[0]=1;
  Serial.println("node 1");
  sread();
  check();
  while(!(LF<REF[0] || RF<REF[7]))
  { 
    sread();
    s_forward();
    check();
  }
sread();
check();
if(LF<REF[0] && RF>REF[7] && RR==0 && LL==1)
{Serial.println("mm");
  check();
  node[1]=1;
  Serial.println("node 2");
  sread();
 if( L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5] )
 {
  node[2]=1;
  Serial.println("node 3");
 }

if(node[0]==1 && node[1]==1 && node[2]==0)
{
  sread();
   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&L1>REF[3] && R1>REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7]))
  {
    sread();
    s_forward(); 
  }
   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&L1<REF[3] && R1<REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7]))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;LL=0;
}


//30 left

else if(node[0]==1 && node[1]==1 && node[2]==1)
{Serial.println("node pache");
  check();
  sread();
  while(!((L1>REF[3] && R1>REF[4])))
  {sread();
   power_left(); 
  }
 // forward();
  //delay(50);
  sread();
   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&(L1<REF[3] || R1<REF[4]) && R2>REF[5] && R3>REF[6] && RF>REF[7]))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;LL=0;
  }
}

else if(LF<REF[0] || RF<REF[7] && RR==1 && LL==1)
{check();
  sread();
  if( L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5] )
 {check();
  forward();
    LL=0;RR=0;
 }
   
else if( L2>REF[2] && L1>REF[3] && R1>REF[4] &&R2>REF[5] && RR==1 && LL==1 )
{check();
Serial.println("yes");
  sread();
  while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&(L1<REF[3] || R1<REF[4]) && R2>REF[5] && R3>REF[6] && RF>REF[7]))
  {sread();
    power_left();
    LL=0;RR=0;}
}

}

}
//TEST LEFT ENDS HERE


      // TEST RIGHT 
      sread();
if(LF>REF[0] && L3>REF[1] &&R3<REF[6] && RF>REF[7])
{
  nod[0]=1;
 sread();
 check();
  while(!(LF<REF[0] || RF<REF[7]))
  { sread();
  check();
    s_forward();
    Serial.print("gh");
  }
  check();
if(LF>REF[0] && RF<REF[7] && LL==0 && RR==1)
{
  Serial.println("naa");
  nod[1]=1;
  sread();
 if( L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5] )
 {
  nod[2]=1;
 }

if(nod[0]==1 && nod[1]==1 && nod[2]==0)
{
  sread();
   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&L1>REF[3] && R1>REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7]))
  {sread();
   s_forward(); 
  }
 // forward();
 // delay(50);

   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&L1<REF[3] && R1<REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7]))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;
  }

  
// 30 right 



else if(nod[0]==1 && nod[1]==1 && nod[2]==1)
{
  sread();
   while(!(L1>REF[3] && R1>REF[4]))
  {
    sread();
    Serial.println("soja");
   power_right(); 
  }
  sread();
   while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&(L1<REF[3] || R1<REF[4]) && R2>REF[5] && R3>REF[6] && RF>REF[7]))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;nod[2]=0;
   RR=0;LL=0;
}
}

else if(LF<REF[0] || RF<REF[7] && RR==1 && LL==1)
{check();
  sread();
  if( L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5] )
 {
  forward();
    LL=0;RR=0;
 }
   
else if( L2>REF[2] && L1>REF[3] && R1>REF[4] &&R2>REF[5] )
{
  sread();
  Serial.print("tt");
  while(!(LF>REF[0] && L3>REF[1] && L2>REF[2]&&(L1<REF[3] || R1<REF[4]) && R2>REF[5] && R3>REF[6] && RF>REF[7]))
  power_left();
    LL=0;RR=0;
}

}
  }
//TEST RIGHT ENDS HERE

    
      
      else if(LF>REF[0] && L3>REF[1] && (L2<REF[2] || L1<REF[3]) && R1>REF[4] && R2>REF[5] && R3>REF[6] && RF>REF[7])
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      
      else if(LF>REF[0]&&L3>REF[1] && L2>REF[2] && L1>REF[3]&& (R1<REF[4] || R2<REF[5]) && R3>REF[6]&&RF>REF[7])
      {
        sread();
        ektu_right();
        Serial.print("er\n");
      } 
  }
  
  

  //white in black
 sread();
  if(L3<REF[1] && R3<REF[6] &&LF<REF[0] && RF<REF[7])
  {
  while(1)  
  {

    // only L3 R3 check

    
   
    //check ends here
        sread();
        if(L3>REF[1] && (L2<REF[2] || L1<REF[3] || R1<REF[4] || R2<REF[5]) && R3>REF[6])
        {sread();
          break; 
        }
      sread();
        if(LF<REF[0] && L3<REF[1] && L2<REF[2] && L1<REF[3] && R1<REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7])
       {sread();
        while(!(LF>REF[0] ||L3>REF[1] || L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5] || R2>REF[5] || R3>REF[6]|| RF>REF[7]))
        {  sread();
          forward();
                    khali++;
          if(khali>700)
          {
            digitalWrite(2,HIGH);
            if(digitalRead(30)==HIGH)
            {
              forward();
            }
            else if(digitalRead(31)==HIGH)
            {
              ektu_left();
            }
            else if(digitalRead(32)==HIGH)
            {
              ektu_right();
            }
             else if(digitalRead(33)==HIGH)
            {
              forward();
              delay(150);
              
              power_left();
              delay(250);
              forward();
              delay(200);
            }
            else if(digitalRead(34)==HIGH)
            {
              forward();
              delay(150);
              
              power_right();
              delay(250);
              forward();
              delay(200);
            } 
          }
        } 
        }
        sread();
      if(LF<REF[0] &&L3<REF[1] && L2<REF[2] && L1>REF[3] ||R1>REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7])
      {
        sread();
        forward();
         Serial.print("f\n");
      }

//TEST LEFT
      
      sread();
if(LF<REF[0] && L3>REF[1] && R3<REF[6] && RF<REF[7])
{
  node[0]=1;
  Serial.println("node 1");
  sread();
  kcheck();
  while(!(LF>REF[0] || RF>REF[7]))
  { 
    sread();
    s_forward();
    kcheck();
  }
sread();
kcheck();
if(LF>REF[0] && RF<REF[7] && RR==0 && LL==1)
{Serial.println("mm");
  kcheck();
  node[1]=1;
  Serial.println("node 2");
  sread();
 if( L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5] )
 {
  node[2]=1;
  Serial.println("node 3");
 }

if(node[0]==1 && node[1]==1 && node[2]==0)
{
  sread();
   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&L1<REF[3] && R1<REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7]))
  {
    sread();
    s_forward(); 
  }
   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&L1>REF[3] && R1>REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7]))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;LL=0;
}
else if(node[0]==1 && node[1]==1 && node[2]==1)
{Serial.println("node pache");
  kcheck();
  sread();
  while(!(L1<REF[3] && R1<REF[4]))
  {sread();
   power_left(); 
  }
 // forward();
  //delay(50);
  
   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&(L1>REF[3] || R1>REF[4]) && R2<REF[5] && R3<REF[6] && RF<REF[7]))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;LL=0;
  }
}

else if(LF>REF[0] || RF>REF[7] && RR==1 && LL==1)
{kcheck();
  sread();
  if( L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5] )
 {kcheck();
  forward();
    LL=0;RR=0;
 }
   
else if( L2<REF[2] && L1<REF[3] && R1<REF[4] &&R2<REF[5] && RR==1 && LL==1 )
{kcheck();
Serial.println("yes");
  sread();
  while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&(L1>REF[3] || R1>REF[4]) && R2<REF[5] && R3<REF[6] && RF<REF[7]))
  {sread();
    power_left();
    LL=0;RR=0;}
}

}

}
//TEST LEFT ENDS HERE


      // TEST RIGHT 
      sread();
if(LF<REF[0] && L3<REF[1] &&R3>REF[6] && RF<REF[7])
{
  nod[0]=1;
 sread();
 kcheck();
  while(!(LF>REF[0] || RF>REF[7]))
  { sread();
  kcheck();
    s_forward();
    Serial.print("gh");
  }
  kcheck();
if(LF<REF[0] && RF>REF[7] && LL==0 && RR==1)
{
  Serial.println("naa");
  nod[1]=1;
  sread();
 if( L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5] )
 {
  nod[2]=1;
 }

if(nod[0]==1 && nod[1]==1 && nod[2]==0)
{
  sread();
   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&L1<REF[3] && R1<REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7]))
  {sread();
   s_forward(); 
  }
 // forward();
 // delay(50);

   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&L1>REF[3] && R1>REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7]))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;
  }

else if(nod[0]==1 && nod[1]==1 && nod[2]==1)
{
  sread();
   while(!(L1<REF[3] && R1<REF[4] ))
  {
    sread();
    Serial.println("soja");
   power_right(); 
  }
   while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&(L1>REF[3] || R1>REF[4]) && R2<REF[5] && R3<REF[6] && RF<REF[7]))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;nod[2]=0;
   RR=0;LL=0;
}
}

else if(LF>REF[0] || RF>REF[7] && RR==1 && LL==1)
{kcheck();
  sread();
  if( L2>REF[2] || L1>REF[3] || R1>REF[4] || R2>REF[5] )
 {
  forward();
    LL=0;RR=0;
 }
   
else if( L2<REF[2] && L1<REF[3] && R1<REF[4] &&R2<REF[5] )
{
  sread();
  Serial.print("tt");
  while(!(LF<REF[0] && L3<REF[1] && L2<REF[2]&&(L1>REF[3] || R1>REF[4]) && R2<REF[5] && R3<REF[6] && RF<REF[7]))
  power_left();
    LL=0;RR=0;
}

}
  }
//TEST RIGHT ENDS HERE

    
      
      else if(LF<REF[0] && L3<REF[1] && (L2>REF[2] || L1>REF[3]) && R1<REF[4] && R2<REF[5] && R3<REF[6] && RF<REF[7])
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      
      else if(LF<REF[0]&&L3<REF[1] && L2<REF[2] && L1<REF[3]&& (R1>REF[4] || R2>REF[5]) && R3<REF[6]&&RF<REF[7])
      {
        sread();
        ektu_right();
        Serial.print("er\n");
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

  analogWrite(13, 170);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 170);
  Serial.println("f");
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

  analogWrite(13, 155);
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

  analogWrite(8, 155);
  Serial.print("el");
}
void s_forward()
{
  digitalWrite(7, HIGH);
  digitalWrite(11, LOW);

  analogWrite(13, 120);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 120);
  Serial.print("f");
}
void check()
{
   sread();
    if(L3>REF[1])
    {
      L=0;
    }
    sread();
    if(R3>REF[6])
    {
      R=0;
    }
        sread();
    if(L3<REF[1])
    {
      L=1;
      if(L==1)
      {
        LL=1;
      }
    }
    sread();
    if(R3<REF[6])
    {
      R=1;
      if(R==1)
      {
        RR=1;
      }
    }
    Serial.println("left");
    Serial.println(LL);
    Serial.println("right");
    Serial.println(RR);

}
void kcheck()
{
   sread();
    if(L3<REF[1])
    {
      L=0;
    }
    sread();
    if(R3<REF[6])
    {
      R=0;
    }
        sread();
    if(L3>REF[1])
    {
      L=1;
      if(L==1)
      {
        LL=1;
      }
    }
    sread();
    if(R3>REF[6])
    {
      R=1;
      if(R==1)
      {
        RR=1;
      }
    }
    Serial.println("left");
    Serial.println(LL);
    Serial.println("right");
    Serial.println(RR);

}
void calibration()
{
  for(i=0;i<1000;i++)
  {
    Serial.println(i);
    power_right();
    sread();
    maximum[0]=max(LF,maximum[0]);
    maximum[1]=max(L3,maximum[1]);
    maximum[2]=max(L2,maximum[2]);
    maximum[3]=max(L1,maximum[3]);
    maximum[4]=max(R1,maximum[4]);
    maximum[5]=max(R2,maximum[5]);
    maximum[6]=max(R3,maximum[6]);
    maximum[7]=max(RF,maximum[7]);
  }
  for(i=0;i<1000;i++)
  {
    Serial.println(i);
    power_left();
    sread();
    minimum[0]=min(LF,minimum[0]);
    minimum[1]=min(L3,minimum[1]);
    minimum[2]=min(L2,minimum[2]);
    minimum[3]=min(L1,minimum[3]);
    minimum[4]=min(R1,minimum[4]);
    minimum[5]=min(R2,minimum[5]);
    minimum[6]=min(R3,minimum[6]);
    minimum[7]=min(RF,minimum[7]);
  }
  for(i=0;i<8;i++)
  {
    REF[i]=(maximum[i]+minimum[i])/2;
   Serial.println(REF[i]);
  }
}
void stops()
{
   digitalWrite(7, HIGH);
  digitalWrite(11, HIGH);

  analogWrite(13, 0);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);

  analogWrite(8, 0);
  //Serial.println("f");
}



