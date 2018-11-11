
int xPin=A0;
int yPin=A1;
int pin_pot=A2;
int mot1;
int mot2;
int mot3;
int mot4;
int output;

int out1=6;     //output1 for HT12E IC
int out2=9;     //output1 for HT12E IC
int out3=10;    //output1 for HT12E IC
int out4=11;    //output1 for HT12E IC

void setup(){
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(pin_pot,INPUT);

 
  
  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
}


void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);
  output=analogRead(pin_pot);

  if ((xval>294 && xval<340) && (yval>294 && yval<340)) //stop
  {
    mot1=map(output,0,1023,0,255);
    digitalWrite(out1,mot1); 
    mot2=map(output,0,1023,0,255); 
    digitalWrite(out2,mot2); 
    mot3=map(output,0,1023,0,255);  
    digitalWrite(out3,mot3);
    mot4=map(output,0,1023,0,255);
    digitalWrite(out4,mot4);
  } 

  else 
  { 
    if ((xval>340 && xval<380) && (yval>294 && yval<340)) //forward
   {

     digitalWrite(out1,240);  
     digitalWrite(out2,255);   
     digitalWrite(out3,240);  
     digitalWrite(out4,255);
      
    }
    if ((xval>345 && xval<294) && (yval>294 && yval<340)) //backward
  {
   digitalWrite(out1,255);   
   digitalWrite(out2,240);  
   digitalWrite(out3,255);   
   digitalWrite(out4,240);
      
    }   

    if ((xval>294 && xval<340) && (yval>340 && yval<380)) //left
    {
      digitalWrite(out1,255);  
      digitalWrite(out2,240);   
      digitalWrite(out3,240);   
      digitalWrite(out4,255);
     }


    if ((xval>294 && xval<340) && (yval>340 && yval<294))//right
    {
      digitalWrite(out1,240);  
      digitalWrite(out2,255);   
      digitalWrite(out3,255);   
      digitalWrite(out4,240);
      
    }
  }
}
