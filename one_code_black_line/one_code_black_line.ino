void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  //white line in black surface
if(BL<REF && RF<REF)
{
sread();
if(BL<REF&&L3<REF&&L2<REF && L1>REF && R1>REF && R2<REF&&R3<REF&&BR<REF)
{

  Serial.println("f");

forward();
  
}

#//FINDING "L"
sread();
if(LF>REF&&RF<REF)
{
sread();

  while(!(L3<REF&&L2<REF && L1>REF && R1>REF && R2<REF&&R3<REF))
  {
    Serial.println("THIS IS L POINT AND GOING TO LEFT");
     sread();
    power_left();

  }

}


#//FOLLOWING THE LINE FLUENTLY
  sread();
  if(L3<REF&&L2>REF&&L1>REF&&R1<REF&&R2<REF&&R3<REF)

{
  sread();

    Serial.println("ektu left");

  ektu_left();

}
sread();
 if(L3<REF&&L2>REF&&L1<REF&&R1<REF&&R2<REF&&R3<REF)

{
  sread();

    Serial.println("arektu left");

  ektu_left();

}
sread();
if(L3<REF&&L2<REF&&L1<REF&&R1>REF&&R2>REF&&R3<REF)

{
  sread();
  Serial.println("ektu right");

  ektu_right();


}
sread();
if(L3<REF&&L2<REF&&L1<REF&&R1<REF&&R2>REF&&R3<REF)

{
  sread();
  Serial.println("arektu right");

  ektu_right();


}


#//FINDING "R"
sread();
 if(LF<REF&&RF>REF)
{
 sread();
while(!(L3<REF&&L2<REF&&L1>REF&&R1>REF&&R2<REF&&R3<REF))
  {
    Serial.println("THIS IS R POINT AND GOING TO RIGHT");
     sread();
     
    power_right();
  }
  }
#//FINDING "45 DEGREE"
sread();


#//FINDING 'END POINT'

sread();
if(L3>REF&&LF>REF&&BL>REF&&L2>REF&&L1>REF&&R1>REF&&R2>REF&&R3>REF&&RF>REF&&BR>REF)
{
    sread();
    Stop();

}

}
