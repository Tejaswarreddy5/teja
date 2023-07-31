     #include<EEPROM.h>

uint16_t DEVICE_ID = 57;
uint16_t MIN_VOLTAGE = 330; 
uint16_t MAX_VOLTAGE = 480;
byte max_volt1_add = 1;
byte max_volt2_add = 2;
byte min_volt1_add = 3;
byte min_volt2_add = 4;
byte max_cur_add = 5;
byte min_cur_add = 6;
byte device_id1_add = 7;
byte device_id2_add = 8;
byte cur_diff_add = 9;
byte host_add = 10; //next address will be 10+25 = 35+1 => 36
byte MIN_CURRENT = 1; 
byte MAX_CURRENT = 25;
byte CUR_DIFF = 2;
char mqtt_broker[25] = "hivemq.theja.in";

void setup() {
  // put your setup code here, to run once:
EEPROM.begin(30);
EEPROM.write(max_volt1_add , (( MAX_VOLTAGE >> 0 ) & 0xff ));
EEPROM.commit();
EEPROM.write(max_volt2_add , (( MAX_VOLTAGE >> 8 ) & 0xff ));
EEPROM.commit();
EEPROM.write(min_volt1_add , (( MIN_VOLTAGE >> 0 ) & 0xff ));
EEPROM.commit();
EEPROM.write(min_volt2_add , (( MIN_VOLTAGE >> 8 ) & 0xff ));
EEPROM.commit();
EEPROM.write(max_cur_add , MAX_CURRENT );
EEPROM.commit();
EEPROM.write(min_cur_add , MIN_CURRENT );
EEPROM.commit();
EEPROM.write(device_id1_add , (( DEVICE_ID >> 0 ) & 0xff ));
EEPROM.commit();
EEPROM.write(device_id2_add , (( DEVICE_ID >> 8 ) & 0xff ));
EEPROM.commit();
EEPROM.write(cur_diff_add , CUR_DIFF );
EEPROM.commit();
EEPROM.put(host_add, mqtt_broker);
EEPROM.commit();
}

void loop() {
  // put your main code here, to run repeatedly:
}
