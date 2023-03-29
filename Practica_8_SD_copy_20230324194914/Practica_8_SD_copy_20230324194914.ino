#include "FS.h"
#include "SD.h"
#include "SPI.h"
#include "BluetoothSerial.h"

File myFile;
int Fire_analog = 4;
void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(5)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");
  if(SD.exists("/datalog.csv"))
  {
      myFile = SD.open("/datalog.csv", FILE_WRITE);
      if (myFile) {
        Serial.println("Archivo nuevo, Escribiendo encabezado(fila 1)");
        myFile.println("Tiempo(ms),SensorLlama");
        myFile.close(); 
        
      } else {

        Serial.println("Error creando el archivo datalog.csv");
      }
  }
}

void loop()
{
  
  
  myFile = SD.open("/datalog.csv", FILE_APPEND);//abrimos  el archivo
  
  
  if (myFile) { 
        Serial.print("Escribiendo SD: ");
        int firesensorAnalog = analogRead(Fire_analog);
        myFile.print(millis());
        myFile.print(",");
        myFile.println(firesensorAnalog);
        myFile.flush(); 
         
        
        Serial.print("Tiempo(ms)=");
        Serial.print(millis());
        Serial.print(" , EntradaAnalogica= ");
        Serial.println(firesensorAnalog);
        delay(700);
        
       }       
                    
  
   else {
    Serial.println("Error al abrir el archivo");
    delay(100);
  }
  
}