#include <Wire.h>
#define SLAVE_ADDRESS 0x06

float pressure;
float number

void setup() {
  
  Serial.begin(9600);

  Wire.begin(SLAVE_ADDRESS);

  Wire.onReceive(receiveData);
  Wire.onRequest(sendData);
  
}

void loop() {
  
  int read = analogRead(1);                 //Leitura analógica do Output do sensor (inteiro de 0 a 1023)
  float vout = read * 0.0049;               //Conversão para um valor de tensão entre 0 e 5V
  float pressure = vout - 2.5;              //Conversão para um valor de pressão (de acordo com a função de transferência do Datasheet)

  Serial.println("Pressure (kPa): ");
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
