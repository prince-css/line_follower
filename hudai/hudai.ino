void check()
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

