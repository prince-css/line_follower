int BL,LF,L3,L2,L1,R1,R2,R3,RF,BR;
void setup()
{ 
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A6, INPUT);
  pinMode(A8, INPUT);
  pinMode(A9, INPUT);
  //pinMode(A14, INPUT);
  //pinMode(A15, INPUT);
  Serial.begin(9600);
}
void loop()
{
   
    RF=analogRead(A1);
    R3=analogRead(A2);
    R2=analogRead(A3);
    R1=analogRead(A4);
    L1=analogRead(A5);
    L2=analogRead(A6);
    L3=analogRead(A8);
    LF=analogRead(A9);
    
Serial.print(LF);
Serial.print(" ");
Serial.print(L3);
Serial.print(" ");
Serial.print(L2);
Serial.print(" ");
Serial.print(L1);
Serial.print(" ");
Serial.print(R1);
Serial.print(" ");
Serial.print(R2);
Serial.print(" ");
Serial.print(R3);
Serial.print(" ");
Serial.print(RF);

Serial.println("");
delay(500);

}
