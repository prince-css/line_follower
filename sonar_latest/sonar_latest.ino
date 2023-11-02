int lvalue=0,ldis=0;
int fvalue=0,fdis=0;
void sonar_activate();
void forward();
void backward();
void ektu_left();

void power_left();
void ektu_right();
void power_right();
void Stop();
void sonar_activate();
void setup()
{
  pinMode(53,INPUT);    //for left sonar
  pinMode(52,OUTPUT);   //for left sonar
  pinMode(51,OUTPUT);    //for right sonar
  pinMode(50,INPUT);   //for right sonar
 
 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  
 
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

     
     
    
  
      
     sonar_activate();

     
     if(fdis>9 && ldis>=9 && ldis<18)
     {

       sonar_activate();
      forward();
     }

     
     
     sonar_activate();
     
     
     if(fdis>11&&ldis<11)                                        //sonar will activate if there is no white line under the sensors
     {
       
       sonar_activate();
       ektu_left();
     }

     
     sonar_activate();
     
     
     if(fdis>25&&ldis>=15)
     {
      sonar_activate();
       Stop();
       delay(100);
       ektu_right();
     }     
      
     
     sonar_activate();
     
     
      if(fdis<9)
     { 
      sonar_activate();
      
      
      power_left();
     }
     
}
     void forward()
{
 digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 
 analogWrite(13,90);
 digitalWrite(9,HIGH);
 digitalWrite(8,LOW);
 
 analogWrite(12,90);
}

void ektu_left()
{
  digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 
 analogWrite(13,50);
 digitalWrite(9,HIGH);
 digitalWrite(8,LOW);
 
 analogWrite(12,150);
}



void power_left()
{
  digitalWrite(11,LOW);
 digitalWrite(10,HIGH);
 
 analogWrite(13,120);
 digitalWrite(9,HIGH);
 digitalWrite(8,LOW);
 
 analogWrite(12,120);
  }
void ektu_right()
{
   digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 
 analogWrite(13,180);
 digitalWrite(9,HIGH);
 digitalWrite(8,LOW);
 
 analogWrite(12,20);
}


void power_right()
{
  digitalWrite(11,HIGH);
 digitalWrite(10,LOW);
 
 analogWrite(13,120);
 digitalWrite(9,LOW);
 digitalWrite(8,HIGH);
 
 analogWrite(12,120);
  

}

void Stop()
{
  digitalWrite(11,LOW);
 digitalWrite(10,HIGH);
 
 analogWrite(13,0);
 digitalWrite(9,LOW);
 digitalWrite(8,HIGH);
 
 analogWrite(12,0);
}

void sonar_activate()
{
  digitalWrite(52,LOW);
  
  delayMicroseconds(2);
  digitalWrite(52,HIGH);
  
  delayMicroseconds(5);
  digitalWrite(52,LOW);
  
  lvalue=pulseIn(53,HIGH);
  ldis=lvalue / 29 / 2;
Serial.println(ldis); 

digitalWrite(50,LOW);
delayMicroseconds(2);
digitalWrite(50,HIGH);
delayMicroseconds(5);
digitalWrite(50,LOW);
fvalue=pulseIn(51,HIGH);
fdis=fvalue / 29 / 2 ;
Serial.println(fdis);
}
