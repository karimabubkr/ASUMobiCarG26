
#include<IRremote.h>

int receiver=11;
IRrecv irrecv(receiver);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop()
{

  if(irrecv.decode(&results))
  { Serial.println(results.value,HEX);
    irrecv.resume();
  

  }
  
   if(results.value==0x1ff00ff || results.value==0x1ff00ff){ analogWrite(5, 255);
   
   analogWrite(6, 255);
   analogWrite(9, 0);
   analogWrite(10, 0);
   
   }

  if(results.value==0x1ff807F || results.value==0x1ff807F){ analogWrite(9, 255);
   
   analogWrite(10, 255);
   analogWrite(5, 0);
   analogWrite(6, 0);
  
  }
  
  if(results.value==0x1ff40bf || results.value==0x1ff40bf){ analogWrite(6, 255);
 
 analogWrite(9, 255);
 analogWrite(5, 0);
 analogWrite(10, 0);
 
  }
 
 if(results.value==0x1ffc03f || results.value==0x1ffc03f){ analogWrite(5, 255);
 analogWrite(10, 255);
 analogWrite(9, 0);
 analogWrite(6, 0);
 
 }
 
 if(results.value==0x1ffd827 || results.value==0x1ffd827){ analogWrite(5, 255);
 
  analogWrite(6, 80);
  analogWrite(9, 0);
 analogWrite(10, 0);
   
 }
 
  
   if(results.value==0x1ff7887 || results.value==0x1ff7887){ analogWrite(6, 255);
 
   analogWrite(5, 80);
   analogWrite(9, 0);
 analogWrite(10, 0);
 
 } 
 
 if(results.value==0x1ff708f || results.value==0x1ff708f){ analogWrite(10, 255);
 
   analogWrite(9, 80);
   analogWrite(6, 0);
 analogWrite(5, 0);
 
 }
 
 if(results.value==0x1fff00f || results.value==0x1fff00f){ analogWrite(9, 255);
 
   analogWrite(10, 80);
   analogWrite(6, 0);
 analogWrite(5, 0);
 
 }
 
  if(results.value==0x1fff807 || results.value==0x1fff807){ analogWrite(6, 0);
  analogWrite(5, 0);
 analogWrite(9, 0);
   analogWrite(10, 0);
}

}
  
  

