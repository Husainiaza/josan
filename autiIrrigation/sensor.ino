void sensorTanah1() {

int dataSensor1 = analogRead(sensorLembab1);
Serial.print("dataSensor1: ");
Serial.println(dataSensor1);
lcd.setCursor(0,0);
lcd.print("sensor 1 :");
lcd.setCursor(10,0);
lcd.print(dataSensor1);
client.publish("jsp/level1", String(dataSensor1));

}

void sensorTanah2() {

int dataSensor2 = analogRead(sensorLembab2);
Serial.print("dataSenso2: ");
Serial.println(dataSensor2);
lcd.setCursor(0,1);
lcd.print("sensor 2 :");
lcd.setCursor(10,1);
lcd.print(dataSensor2);

client.publish("jsp/level2", String(dataSensor2));

}

void sensorTanah3() {

int dataSensor3 = analogRead(sensorLembab3);
Serial.print("dataSensor3: ");
Serial.println(dataSensor3);
lcd.setCursor(0,1);
lcd.print("sensor 3 :");
lcd.setCursor(10,1);
lcd.print(dataSensor3);

client.publish("jsp/level3", String(dataSensor3));

}