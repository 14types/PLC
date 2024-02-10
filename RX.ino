#include <SoftwareSerial.h>

String Data = "";

void setup()  {
  delay(1);
  Serial.begin(4800);
  Serial.println("Slave System");    
}

void loop() { 
  pinMode(11, INPUT);
  if (digitalRead(11) == LOW){
    pinMode(11, OUTPUT);
    recieverRunSlave();
  } 
}

void senderRunSlave(){  
  SoftwareSerial mySerial(30,11); 
  delay(2);  
  mySerial.begin(4800);
  int dataint = Data.toInt() * 10;
  mySerial.print(dataint);
  mySerial.write("\n");
  Serial.print(dataint);
  Serial.println(" sent");
}

void recieverRunSlave(){
  SoftwareSerial mySerial(11,30);
  delay(1); 
  mySerial.begin(4800);
  boolean recieved = false;
  Serial.println("wait data");
  Data = "";
  while (!recieved){
    if(mySerial.available()){      
      char character = mySerial.read();      
      if (character == '\n') {
        recieved = true;
      } else {     
        Data.concat(character);        
      }      
    }
  }
  
  senderRunSlave();
  
}
