#define BOTON 2
#define BOTON1 3
#define BOTON2 8
#define BOTON3 9
int temporizador = 30;
int volumen = 5;
int cancion = 0;
int periodo = 180;
long numeroAnterior;
long numeroRamdon;
bool bandera = false;
bool pausado = false;
volatile bool btnflag=false;
volatile bool btnflag2 = false;
unsigned long tiempoAnterior = 0;


void setup() {
  Serial.begin(9600);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(BOTON1, INPUT_PULLUP);
  pinMode(BOTON2, INPUT_PULLUP);
  pinMode(BOTON3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOTON1), bajarVolumen, FALLING);// esta funcion nos sirve para interrumpir el codigo cada vez que se detecte un cambio en el boton llamando a la funcion incremento cuando sea un flanco de bajada
  attachInterrupt(digitalPinToInterrupt(BOTON), subirVolumen, FALLING);

}

void loop() {
  if (digitalRead(BOTON2) == 0) { 
    pausado = !pausado;
    delay(80);
  }
  if(digitalRead(BOTON3) == 0){
    bandera = !bandera;
    delay(80);   
  }
  if(btnflag2){
    if(digitalRead(BOTON)==0){
      if(millis()-tiempoAnterior>=3000){
        rola();
        Serial.print("Cancion: ");
        Serial.println(cancion);
        temporizador = 30;
      }
    }
  }
  if(btnflag){
    if(digitalRead(BOTON1)==0){
      if(millis()-tiempoAnterior>=3000){
        rola();
        if(cancion == 1){
          cancion--;
        }else{
          cancion = cancion - 2;
        }
        Serial.print("Cancion: ");
        Serial.println(cancion);
        temporizador = 30;
      }
    }
  }
  if(pausado == false){
    if(temporizador > 0){
      temporizador--;
      delay(1000);
    }else{
      temporizador = 30;
      rola();
      Serial.print("Cancion: ");
      Serial.println(cancion);
      delay(1000);
    }
    Serial.print(temporizador);
    Serial.println(" Segundos");
  }else{
    Serial.print(temporizador);
    Serial.println(" Segundos");
    Serial.println("    PAUSADO");
    delay(1500);
  }
  
}
void rola()
{ 
  numeroRamdon = random(0,100);
  numeroAnterior = numeroRamdon;
  if(bandera == true){
    cancion = numeroRamdon;
    Serial.println("Aleatoridad Activada");
  }else{
    cancion++;
    Serial.println("Aleatoridad Desactivada");
  }
  
}
void bajarVolumen(){
  unsigned long tiempoActual = millis();
  if(volumen >0){
    if (tiempoActual - tiempoAnterior > periodo) {
      if(digitalRead(BOTON1)==0){
        volumen--;
        btnflag=true;
        Serial.print("      Nivel de Volumen: ");
        Serial.println(volumen);
        tiempoAnterior = tiempoActual;
    }
  }
}
}
void subirVolumen(){
  unsigned long tiempoActual = millis();
  if(volumen < 10){
    if (tiempoActual - tiempoAnterior > periodo) {
      if(digitalRead(BOTON)==0){
        volumen++;
        btnflag2=true;
        Serial.print("        Nivel de Volumen: ");
        Serial.println(volumen);
        tiempoAnterior = tiempoActual;
    }
  }
}
}
