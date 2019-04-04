#include <Wire.h>

#define SLAVE_ADDRESS 0x09
int number = 0;
int pressure =0;

void setup() {
  
  Serial.begin(9600);

  Wire.begin(SLAVE_ADDRESS);

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
}

void loop() {
  
  int read = analogRead(5);
  float vout = read * 0.0049;
  float pressure = vout - 2.5;

  //Serial.println("Vout: ");
  //Serial.println(vout);
  Serial.println("Pressure (kPa): ");
  Serial.println(pressure);

  delay(800);
}

void receiveData(int byteCount){
  while(Wire.available()) {
    number = Wire.read();
    Serial.print("data received: ");
}

}

void sendData(){
  Wire.write(pressure);
}
