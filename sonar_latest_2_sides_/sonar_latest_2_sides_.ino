int rvalue=0,rdis=0;
int lvalue=0,ldis=0;
void sonar_activate();

void sonar_activate();
void setup()
{
  pinMode(53,INPUT);    //for left sonar
  pinMode(52,OUTPUT);   //for left sonar
  pinMode(51,INPUT);    //for front sonar
  pinMode(50,OUTPUT);   //for front sonar
 
 
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);

  
 
Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:

     
     
    
 if(digitalRead(2)==HIGH)
 { 
      
     sonar_activate();
     delay(200);

//        Serial.println(ldis);
//        Serial.println("\t");
//        Serial.println(fdis);
//         delay(100);
if(ldis>27 && rdis<20 && rdis>9)
      {
        sonar_activate();
        digitalWrite(33,HIGH);             //forward then delay then  turn left

        
      }
       else if(rdis>27 && ldis<20 && ldis>10)
      {
        sonar_activate();
        digitalWrite(34,HIGH);       //forward then delay then  turn right
      }
     
    else if(ldis>=10 || rdis>=10)
     {

       sonar_activate();
       digitalWrite(30,HIGH) ;    // FORWARD
       //Serial.print(lvalue);
     }

     
     
   //  sonar_activate();
     
     
    else if((ldis>10 &&ldis<20)||rdis<10  )                                      //sonar will activate if there is no white line under the sensors
     {
       
       sonar_activate();
     digitalWrite(31,HIGH)   ;     // ektu_left
       //Serial.print("el");
     }

     
  //   sonar_activate();
     
     
    else if(ldis<10||(rdis>10&& rdis<20))
     {
      sonar_activate();
       
       digitalWrite(32,HIGH  );      //ektu_right
       
     }     
    else if(ldis>30 && rdis>30)
    {
      sonar_activate();
      digitalWrite(35,HIGH);
    }
      
      
     
     
 }   
    
     
}
   
void sonar_activate()
{
  digitalWrite(52,LOW);
  
  delayMicroseconds(2);
  digitalWrite(52,HIGH);
  
  delayMicroseconds(10);
  digitalWrite(52,LOW);
  
  rvalue=pulseIn(53,HIGH);
  rdis=rvalue / 58;
Serial.print("right:  ");
Serial.println(rdis); 

digitalWrite(50,LOW);
delayMicroseconds(2);
digitalWrite(50,HIGH);
delayMicroseconds(10);
digitalWrite(50,LOW);
lvalue=pulseIn(51,HIGH);
ldis=lvalue / 58 ;
Serial.print("Left:  ");
Serial.println(ldis);
}
