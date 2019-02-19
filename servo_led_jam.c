servo_led_jam.c

#include <ir_Lego_PF_BitStreamEncoder.h>
#include <boarddefs.h>
#include <IRremoteInt.h>
#include <IRremote.h>

#include <Servo.h>



int ledPin = 7;
int criticalPin = 8;
int recV_pin = 2;

Servo servo;
int pos = 0;


IRrecv irrecv(recV_pin);
decode_results results;


void setup() {
   Serial.begin(9600); /* initialize log */
   pinMode(criticalPin, OUTPUT);
   servo.attach(4); /* Attach Servo to digital pin */

 irrecv.enableIRIn(); /*Initialize infra-red remote signal receiver */
 

}

void loop() 
{ 
  /* Check for decoded remore result */

  if(irrecv.decode(&results)){
  
    Serial.println(results.value);
    irrecv.resume();
  }

         if(results.value == 16753245){
         digitalWrite(criticalPin,HIGH);
          digitalWrite(ledPin,LOW);
        
         Serial.print(results.value);
         Serial.print("\n Red Light on \n");
         servo.write(120);
         delay(200);

      }
      else if(results.value == 16736925) {
        digitalWrite(ledPin,HIGH);
         digitalWrite(criticalPin, LOW);
         servo.write(50);
          delay(200);
      
      Serial.print(results.value);
         Serial.print("\n Blue light on \n");
  } else if(results.value == 4294967295) {
       servo.write(90);
          
    }
}
 