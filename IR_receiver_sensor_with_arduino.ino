#include <IRremote.hpp>
int receiver=3;   
int redled = 5; 
int greenled = 6; 
int blueled = 7; 
int buzzer = 8; 
 
/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/
 
 
 
void setup()   
{
  Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
 
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);
  pinMode(buzzer, OUTPUT);
   digitalWrite(redled, LOW);
   digitalWrite(greenled, LOW);
   digitalWrite(blueled, LOW);
   digitalWrite(buzzer, LOW);
 
 
}
 
 
void loop() 
{
  if (irrecv.decode(&results)) // have we received an IR signal?
 
  {
   Serial.println(results.value, HEX);  
 
    //translateIR(); 
      if (results.value==0x807F02FD)
      {   
        digitalWrite(redled, !digitalRead(redled));
           delay(100);
        }
       else if (results.value==0x807F22DD)
      {   
            digitalWrite(greenled, !digitalRead(greenled));
           delay(100);
        }
      else if (results.value==0x807F12ED)
      {   
        digitalWrite(blueled, !digitalRead(blueled));
           delay(100); 
        }
       else  if (results.value==0x807F827D)
      {   
        digitalWrite(buzzer, !digitalRead(buzzer));
           delay(100); 
        }
           else  
      {   
 
           Serial.println("Wrong button pressed"); 
           delay(100);
        }
        
    irrecv.resume(); // receive the next value
  }  
}
