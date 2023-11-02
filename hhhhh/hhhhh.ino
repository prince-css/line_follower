 int  L3,LF,BL,L2,L1,R1,R2,R3,RF,BR,i,count=0,L,R,LL=0,RR=0,b;
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
void s_forward();
void check();
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

    // only L3 R3 check

    
   
    //check ends here
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
      if(LF>REF &&L3>REF && L2>REF && L1<REF ||R1<REF && R2>REF && R3>REF && RF>REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }

//TEST LEFT
      
      sread();
if(LF>REF && L3<REF && R3>REF && RF>REF)
{
  node[0]=1;
  Serial.println("node 1");
  sread();
  check();
  while(!(LF<REF || RF<REF))
  { 
    sread();
    s_forward();
    check();
  }
sread();
check();
if(LF<REF && RF>REF && RR==0 && LL==1)
{Serial.println("mm");
  check();
  node[1]=1;
  Serial.println("node 2");
  sread();
 if( L2<REF || L1<REF || R1<REF || R2<REF )
 {
  node[2]=1;
  Serial.println("node 3");
 }

if(node[0]==1 && node[1]==1 && node[2]==0)
{
  sread();
   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {
    sread();
    s_forward(); 
  }
   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;LL=0;
}
else if(node[0]==1 && node[1]==1 && node[2]==1)
{Serial.println("node pache");
  check();
  sread();
  while(!(LF>REF && L3>REF && L2>REF&&(L1>REF && R1>REF) && R2>REF && R3>REF && RF>REF))
  {sread();
   s_forward();
   count++; 
  }
  b=count;
Serial.print(b);
 // forward();
  //delay(50);
  
   while(!(LF>REF && L3>REF && L2>REF&&(L1<REF || R1<REF) && R2>REF && R3>REF && RF>REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;LL=0;
  }
}

else if(LF<REF || RF<REF && RR==1 && LL==1)
{check();
  sread();
  if( L2<REF || L1<REF || R1<REF || R2<REF )
 {check();
  forward();
    LL=0;RR=0;
 }
   
else if( L2>REF && L1>REF && R1>REF &&R2>REF && RR==1 && LL==1 )
{check();
Serial.println("yes");
  sread();
  while(!(LF>REF && L3>REF && L2>REF&&(L1<REF || R1<REF) && R2>REF && R3>REF && RF>REF))
  {sread();
    power_left();
    LL=0;RR=0;}
}

}

}
//TEST LEFT ENDS HERE


      // TEST RIGHT 
      sread();
if(LF>REF && L3>REF &&R3<REF && RF>REF)
{
  nod[0]=1;
 sread();
 check();
  while(!(LF<REF || RF<REF))
  { sread();
  check();
    s_forward();
    Serial.print("gh");
  }
  check();
if(LF>REF && RF<REF && LL==0 && RR==1)
{
  Serial.println("naa");
  nod[1]=1;
  sread();
 if( L2<REF || L1<REF || R1<REF || R2<REF )
 {
  nod[2]=1;
 }

if(nod[0]==1 && nod[1]==1 && nod[2]==0)
{
  sread();
   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {sread();
   s_forward(); 
  }
 // forward();
 // delay(50);

   while(!(LF>REF && L3>REF && L2>REF&&L1<REF && R1<REF && R2>REF && R3>REF && RF>REF))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;
  }

else if(nod[0]==1 && nod[1]==1 && nod[2]==1)
{
  sread();
   while(!(LF>REF && L3>REF && L2>REF&&L1>REF && R1>REF && R2>REF && R3>REF && RF>REF))
  {
    sread();
    Serial.println("soja");
   s_forward(); 
  }
   while(!(LF>REF && L3>REF && L2>REF&&(L1<REF || R1<REF) && R2>REF && R3>REF && RF>REF))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;nod[2]=0;
   RR=0;LL=0;
}
}

else if(LF<REF || RF<REF && RR==1 && LL==1)
{check();
  sread();
  if( L2<REF || L1<REF || R1<REF || R2<REF )
 {
  forward();
    LL=0;RR=0;
 }
   
else if( L2>REF && L1>REF && R1>REF &&R2>REF )
{
  sread();
  Serial.print("tt");
  while(!(LF>REF && L3>REF && L2>REF&&(L1<REF || R1<REF) && R2>REF && R3>REF && RF>REF))
  power_left();
    LL=0;RR=0;
}

}
  }
//TEST RIGHT ENDS HERE

    
      
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

  //white in black
 sread();
  if(L3<REF && R3<REF &&LF<REF && RF<REF)
  {
  while(1)  
  {

    // only L3 R3 check

    
   
    //check ends here
        sread();
        if(L3>REF && (L2<REF || L1<REF || R1<REF || R2<REF) && R3>REF)
        {sread();
          break; 
        }
      sread();
        if(LF<REF && L3<REF && L2<REF && L1<REF && R1<REF && R2<REF && R3<REF && RF<REF)
       {sread();
        while(!(LF>REF ||L3>REF || L2>REF || L1>REF || R1>REF || R2>REF || R2>REF || R3>REF|| RF>REF))
        {  sread();
          forward();
        } 
        }
        sread();
      if(LF<REF &&L3<REF && L2<REF && L1>REF ||R1>REF && R2<REF && R3<REF && RF<REF)
      {
        sread();
        forward();
         Serial.print("f\n");
      }

//TEST LEFT
      
      sread();
if(LF<REF && L3>REF && R3<REF && RF<REF)
{
  node[0]=1;
  Serial.println("node 1");
  sread();
  kcheck();
  while(!(LF>REF || RF>REF))
  { 
    sread();
    s_forward();
    kcheck();
  }
sread();
kcheck();
if(LF>REF && RF<REF && RR==0 && LL==1)
{Serial.println("mm");
  kcheck();
  node[1]=1;
  Serial.println("node 2");
  sread();
 if( L2>REF || L1>REF || R1>REF || R2>REF )
 {
  node[2]=1;
  Serial.println("node 3");
 }

if(node[0]==1 && node[1]==1 && node[2]==0)
{
  sread();
   while(!(LF<REF && L3<REF && L2<REF&&L1<REF && R1<REF && R2<REF && R3<REF && RF<REF))
  {
    sread();
    s_forward(); 
  }
   while(!(LF<REF && L3<REF && L2<REF&&L1>REF && R1>REF && R2<REF && R3<REF && RF<REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;LL=0;
}
else if(node[0]==1 && node[1]==1 && node[2]==1)
{Serial.println("node pache");
  kcheck();
  sread();
  while(!(LF<REF && L3<REF && L2<REF&&(L1<REF && R1<REF) && R2<REF && R3<REF && RF<REF))
  {sread();
   s_forward(); 
  }
 // forward();
  //delay(50);
  
   while(!(LF<REF && L3<REF && L2<REF&&(L1>REF || R1>REF) && R2<REF && R3<REF && RF<REF))
   {sread();
    power_left();
    
  
   }
   node[0]=0;node[1]=0;node[2]=0;LL=0;
  }
}

else if(LF>REF || RF>REF && RR==1 && LL==1)
{kcheck();
  sread();
  if( L2>REF || L1>REF || R1>REF || R2>REF )
 {kcheck();
  forward();
    LL=0;RR=0;
 }
   
else if( L2<REF && L1<REF && R1<REF &&R2<REF && RR==1 && LL==1 )
{kcheck();
Serial.println("yes");
  sread();
  while(!(LF<REF && L3<REF && L2<REF&&(L1>REF || R1>REF) && R2<REF && R3<REF && RF<REF))
  {sread();
    power_left();
    LL=0;RR=0;}
}

}

}
//TEST LEFT ENDS HERE


      // TEST RIGHT 
      sread();
if(LF<REF && L3<REF &&R3>REF && RF<REF)
{
  nod[0]=1;
 sread();
 kcheck();
  while(!(LF>REF || RF>REF))
  { sread();
  kcheck();
    s_forward();
    Serial.print("gh");
  }
  kcheck();
if(LF<REF && RF>REF && LL==0 && RR==1)
{
  Serial.println("naa");
  nod[1]=1;
  sread();
 if( L2>REF || L1>REF || R1>REF || R2>REF )
 {
  nod[2]=1;
 }

if(nod[0]==1 && nod[1]==1 && nod[2]==0)
{
  sread();
   while(!(LF<REF && L3<REF && L2<REF&&L1<REF && R1<REF && R2<REF && R3<REF && RF<REF))
  {sread();
   s_forward(); 
  }
 // forward();
 // delay(50);

   while(!(LF<REF && L3<REF && L2<REF&&L1>REF && R1>REF && R2<REF && R3<REF && RF<REF))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;
  }

else if(nod[0]==1 && nod[1]==1 && nod[2]==1)
{
  sread();
   while(!(LF<REF && L3<REF && L2<REF&&L1<REF && R1<REF && R2<REF && R3<REF && RF<REF))
  {
    sread();
    Serial.println("soja");
   s_forward(); 
  }
   while(!(LF<REF && L3<REF && L2<REF&&(L1>REF || R1>REF) && R2<REF && R3<REF && RF<REF))
   {sread();
    power_right();
    
  
   }
   nod[0]=0;nod[1]=0;nod[2]=0;
   RR=0;LL=0;
}
}

else if(LF>REF || RF>REF && RR==1 && LL==1)
{kcheck();
  sread();
  if( L2>REF || L1>REF || R1>REF || R2>REF )
 {
  forward();
    LL=0;RR=0;
 }
   
else if( L2<REF && L1<REF && R1<REF &&R2<REF )
{
  sread();
  Serial.print("tt");
  while(!(LF<REF && L3<REF && L2<REF&&(L1>REF || R1>REF) && R2<REF && R3<REF && RF<REF))
  power_left();
    LL=0;RR=0;
}

}
  }
//TEST RIGHT ENDS HERE

    
      
      else if(LF<REF && L3<REF && (L2>REF || L1>REF) && R1<REF && R2<REF && R3<REF && RF<REF)
      {
        sread();
        ektu_left();
        Serial.print("el\n");
      }
      
      else if(LF<REF&&L3<REF && L2<REF && L1<REF&& (R1>REF || R2>REF) && R3<REF&&RF<REF)
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

  analogWrite(13, 200);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);

  analogWrite(8, 200);
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
    if(L3>REF)
    {
      L=0;
    }
    sread();
    if(R3>REF)
    {
      R=0;
    }
        sread();
    if(L3<REF)
    {
      L=1;
      if(L==1)
      {
        LL=1;
      }
    }
    sread();
    if(R3<REF)
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
    if(L3<REF)
    {
      L=0;
    }
    sread();
    if(R3<REF)
    {
      R=0;
    }
        sread();
    if(L3>REF)
    {
      L=1;
      if(L==1)
      {
        LL=1;
      }
    }
    sread();
    if(R3>REF)
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


