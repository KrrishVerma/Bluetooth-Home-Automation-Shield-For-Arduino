// Code Written By Krrish Verma
// Make Sure To Give Credits
#include <EEPROM.h>
char val; // Here Variable Is Used To Recieve Data From The Serial Port
//RX OF HC05 IS CONNECTED WITH PIN 1 ON ARDUINO
//TX OF HC05 IS CONNECTED WITH PIN 0 ON ARDUINO

int relay1 = 2;
int relay2 = 3;
int relay3 = 4;
int relay4 = 5;
//Above All The Relay Pins Are Defined

int R1, R2, R3, R4;

void setup() {
//Using EEPROM.read in Void Setup so next time Arduino boots It Cant take data from here and know previous state
R1 = EEPROM.read(1);
R2 = EEPROM.read(2);
R3 = EEPROM.read(3);
R4 = EEPROM.read(4);

pinMode(relay1, OUTPUT); digitalWrite(relay1, R1); 
pinMode(relay2, OUTPUT); digitalWrite(relay2, R2);
pinMode(relay3, OUTPUT); digitalWrite(relay3, R3);
pinMode(relay4, OUTPUT); digitalWrite(relay4, R4);

Serial.begin(9600);
}

void loop() {
  
if(Serial.available()>0)  
 {  
 char data= Serial.read();  
 Serial.println(data);
 // You can use Serial Monitor To See The Data being recieved by Hc05 Module


if (data == 'a'){R1=1;EEPROM.write(1, R1);}
if (data == 'A'){R1=0;EEPROM.write(1, R1);}

if (data == 'b'){R2=1;EEPROM.write(2, R2);}
if (data == 'B'){R2=0;EEPROM.write(2, R2);}

if (data == 'c'){R3=1;EEPROM.write(3, R3);}
if (data == 'C'){R3=0;EEPROM.write(3, R3);}

if (data == 'd'){R4=1;EEPROM.write(4, R4);}
if (data == 'D'){R4=0;EEPROM.write(4, R4);}

//Below is The Functionality To Turn Off All Of The Relays At Same Time
if (val == 'e'){
R1=1;EEPROM.write(1, R1);
R2=1;EEPROM.write(2, R2);
R3=1;EEPROM.write(3, R3);
R4=1;EEPROM.write(4, R4);
}
//Below is The Functionality To Turn On All Of The Relays At Same Time
if (val == 'E'){
R1=0;EEPROM.write(1, R1);
R2=0;EEPROM.write(2, R2);
R3=0;EEPROM.write(3, R3);
R4=0;EEPROM.write(4, R4);
}
val='0';
digitalWrite(relay1, R1);
digitalWrite(relay2, R2);
digitalWrite(relay3, R3);
digitalWrite(relay4, R4);
delay(100);
}
}
