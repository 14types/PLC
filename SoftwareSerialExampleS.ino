#include <SoftwareSerial.h>

unsigned long endtime;
int k = 0;

void setup() {
  Serial.begin(4800);
  Serial.println("Master System");
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  delay(3000);
}

void loop() {  
  pinMode(11, OUTPUT);
  digitalWrite(11, HIGH);
  Serial.print("Длительность отправки-приёма: ");
  Serial.print(endtime);
  Serial.println(" миллисекунд");
  delay(1000);
  digitalWrite(11, LOW);
  delay(10);
  unsigned long starttime = millis();
  senderRunMaster(k);   
  recieverRunMaster();
  k++;
  endtime = millis() - starttime;  
}

void senderRunMaster(unsigned long input){
  SoftwareSerial mySerial(30,11);
  delay(2);
  mySerial.begin(4800);
  mySerial.print(input);
  mySerial.write("\n");
  Serial.print(input);
  Serial.println(" отправлено");
}

void recieverRunMaster(){
  SoftwareSerial mySerial(11,30);
  delay(1);
  mySerial.begin(4800);
  long time = millis();
  boolean recieved = false;
  while (!recieved){
    if(mySerial.available()){      
      char character = mySerial.read();      
      if (character == '\n') {
        recieved = true;       
        Serial.println(" принято");
      } else {
        Serial.write(character);
      }      
    }
  }
}
