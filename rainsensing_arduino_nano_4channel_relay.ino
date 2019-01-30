//IDE settings: Tools/Board: arduino nano, Processor:atmega168, Programmer: arduinoISP

const int analogInPin = A0; 

const int IN1 = 4; 
const int IN2 = 5;
const int IN3 = 6; 
const int IN4 = 7;

#define ON   0
#define OFF  1

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;
int sensorValue6 = 0;
int x = 1000;
 
void setup() {
 Serial.begin(9600); 
 
 Serial.println("Esőérzékelő 1.0");
 Serial.println(" ");
 Serial.println("5 mp-nkénti mérés folyamatban");
 
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  relay_init();//initialize the relay
}
 
void loop() {
 Serial.print(".");
 sensorValue1 = analogRead(analogInPin)*100/1024; 
 delay(x); Serial.print(".");
 sensorValue2 = analogRead(analogInPin)*100/1024; 
 delay(x); Serial.print(".");
 sensorValue3 = analogRead(analogInPin)*100/1024; 
 delay(x); Serial.print(".");
 sensorValue4 = analogRead(analogInPin)*100/1024; 
 delay(x); Serial.println(".");
 sensorValue5 = analogRead(analogInPin)*100/1024; 
 Serial.println("");
sensorValue6 = sensorValue1 + sensorValue2 + sensorValue3 + sensorValue4 + sensorValue5;
  
 Serial.print("Sensor1 = " ); 
 Serial.print(sensorValue1); 
 Serial.println("%");
 Serial.print("Sensor2 = " ); 
 Serial.print(sensorValue2); 
 Serial.println("%");
 Serial.print("Sensor3 = " ); 
 Serial.print(sensorValue3); 
 Serial.println("%");
 Serial.print("Sensor4 = " ); 
 Serial.print(sensorValue4); 
 Serial.println("%");
 Serial.print("Sensor5 = " ); 
 Serial.print(sensorValue5); 
 Serial.println("%");

  Serial.print("Sensor6 = " ); 
 Serial.print(sensorValue6); 
 Serial.println("%");
 
 delay(1000); 




//ha nagyobb nullánál a mérés, azaz nedves idő van kikapcsolja a relét
if (sensorValue6 > 20){
 relay_SetStatus(OFF, OFF, OFF, OFF);//turn on RELAY_1 
  Serial.println("relék kikapcsolása, nedves idő van, felesleges az öntözés");
  }   
else if (sensorValue6 <= 20)
  {
  relay_SetStatus(ON, ON, ON, ON);//turn on RELAY_2
    Serial.println("relék bekapcsolása, száraz idő van, mehet az öntözés");
  }
}



 void relay_init(void)//initialize the relay
  {  
    //set all the relays OUTPUT
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    relay_SetStatus(OFF,OFF,OFF,OFF);//turn off all the relay
  }

//set the status of relays
void relay_SetStatus( unsigned char status_1,  unsigned char status_2, unsigned char status_3,unsigned char status_4)
  {
    digitalWrite(IN1, status_1);
    digitalWrite(IN2, status_2);
    digitalWrite(IN3, status_3);
    digitalWrite(IN4, status_4);
  
  }

