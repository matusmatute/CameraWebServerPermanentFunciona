

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

 const char* ssid = "Torre C Labs";
 const char* password = "1q2w3e4r5t";
// const char* ssid = "Monado";
//  const char* password = "Tensor333_";
//  const char* ssid = "A";
//  const char* password = "123456789";
 int Fire_analog = 4;
 const int relayPin = 33;
 const int buzzerPin = 32;

void setup() {
  Serial.begin(115200);

    SerialBT.begin("Lau"); //Bluetooth device name
  Serial.println("The device started");
  pinMode(relayPin, OUTPUT); // configura el pin del relé como salida
  pinMode(buzzerPin, OUTPUT); // configura el pin del buzzer como salida
  
}

void loop() {

 if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  int firesensorAnalog = analogRead(Fire_analog);
  Serial.println(firesensorAnalog);
  if (firesensorAnalog <= 2000 || Serial.readString().indexOf("fuego") >= 0){
    
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, HIGH);// activa el buzzer con una frecuencia de 1000 Hz
    delay(500); // espera 500 milisegundos
    digitalWrite(buzzerPin, LOW); // detiene el sonido del buzzer
    delay(500); // espera 500 milisegundos; // activa el relé
  } else { // de lo contrario
    digitalWrite(relayPin, LOW); // desactiva el relé
    digitalWrite(buzzerPin, LOW);
  }
  delay(100);

}
  
  