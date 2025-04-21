void sensorTanah1() {

int dataSensor1 = analogRead(sensorLembab1);
Serial.print("dataSensor1: ");
Serial.println(dataSensor1);
display.setCursor(0,30);
display.print("Soil1 :");
display.setCursor(60,30);
display.print(dataSensor1);
display.display();

client.publish("jsp/level1", String(dataSensor1));

}

void sensorTanah2() {

int dataSensor2 = analogRead(sensorLembab2);
Serial.print("dataSenso2: ");
Serial.println(dataSensor2);
display.setCursor(0,40);
display.print("Soil2 :");
display.setCursor(60,40);
display.print(dataSensor2);
display.display();

client.publish("jsp/level2", String(dataSensor2));

}

void sensorTanah3() {

int dataSensor3 = analogRead(sensorLembab3);
Serial.print("dataSensor3: ");
Serial.println(dataSensor3);
display.setCursor(0,50);
display.print("Soil3 :");
display.setCursor(60,50);
display.print(dataSensor3);
display.display();

client.publish("jsp/level3", String(dataSensor3));

}