#define BOTON 2
#define BOTON1 3

int cont = 0;
int cont2 = 500;
int periodo = 100;
bool t = false;
unsigned long tiempoAnterior = 0;

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(BOTON1, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BOTON), Incremento, FALLING);// esta funcion nos sirve para interrumpir el codigo cada vez que se detecte un cambio en el boton llamando a la funcion incremento cuando sea un flanco de bajada
  attachInterrupt(digitalPinToInterrupt(BOTON1), Reinicio, FALLING);
}
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(cont2);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW    delay(cont2);
  delay(cont2);
  Serial.println(cont);
  delay(500);
}
void Incremento()
{
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior > periodo) {
    cont = cont +1;
    Serial.println(tiempoActual - tiempoAnterior);
    tiempoAnterior = tiempoActual;
  }
}

void Reinicio()
{
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior > periodo) {
    cont = 0;
    EstadoLed();
    tiempoAnterior = tiempoActual;
  }
}
void EstadoLed()//funcion para determinar el tiempo de parpadeo del led
{
  if(cont2 == 1500){  
    cont2 = 500; 
    t = true;
  }
  if(cont2 == 1000){    
    cont2 = 1500; 
  }
  if(cont2 == 500 && t == false){  
    cont2 = 1000; 
  }
  t = false;
}