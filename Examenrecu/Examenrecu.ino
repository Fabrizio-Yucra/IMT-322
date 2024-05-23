#include <Time.h>
#include <TimeLib.h>

#define Boton1 2
#define Boton2 3
#define Periodo 80


String Pass = "ucb.2024";
char inChar;
String Cont = "";
bool Bandera = true;
bool Bandera1 = false;
bool Est = false;
unsigned long ultimoTiempo = 0;
unsigned long utiempo = 0;

typedef enum{
  Espera,
  Tiempo,
  Verificacion,
  Correcta,
  Low

}acceso;
acceso Paso = Low;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Cont.reserve(200);
  setTime(11, 3, 0, 23, 5, 2024);
  pinMode(Boton1, INPUT_PULLUP);
  pinMode(Boton2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(Boton2), presionado2, FALLING);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(Paso){
    
    case Espera:
    digitalWrite(LED_BUILTIN, LOW);
    if(hour()< 8 && hour() >16){
        Paso = Low;
      }
    if(Bandera){
      Serial.print("    Ingrese La contraseña: ");
      Paso = Tiempo;
      Bandera = false;
    }
    
    break;

    case Tiempo:
    Bandera = true;
    

    if((millis()-utiempo)< 3000){
      if(Serial.available()>0){
        /*inChar = Serial.read();
        Cont += inChar;*/
        Cont = Serial.readStringUntil('\n');
        utiempo = millis();
        Paso = Verificacion;   
      }
    }else{
      Serial.println("Paso el tiempo de la contraseña. Inténtelo de nuevo");
      utiempo = millis();
      Paso = Espera;
    }
    break;
    case Verificacion:
      veri();
    break;
    case Correcta:
      pull();
      
    break;

    case Low:
      if(hour()< 8 && hour() >16){
        Serial.println("Bajo Consumo");
        delay(1000);
      }else{
        Paso = Espera;
      }
    break;
  }
}
void veri(){
    if(Cont == Pass){
      Serial.println("Contraseña Correcta");
      digitalWrite(LED_BUILTIN, HIGH);
      Paso = Correcta;
    }else{
      Serial.println("Contraseña Incorrecta");
      Paso = Espera;
    }

}
void pull(){
  if(digitalRead(Boton1) == LOW){
    presionado1();
    Paso = Espera;
  }
}

void presionado1() {
  unsigned long tiempoActual = millis();
  if ((tiempoActual - ultimoTiempo) > Periodo) {
    Serial.println("Bienvenido");
    ultimoTiempo = tiempoActual;
  }
}


void presionado2() {
  unsigned long tiempoActual = millis();
  if ((tiempoActual - ultimoTiempo) > Periodo) {
    Serial.print("Reiniciando el sistema");
    ultimoTiempo = tiempoActual;
    Paso = Espera;
  }
}
