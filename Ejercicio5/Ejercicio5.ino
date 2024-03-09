#define BOTON 2
#define BOTON1 3
int cont = 0;
int periodo = 100;
unsigned long tiempoAnterior = 0;

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(BOTON1, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BOTON), Incremento, FALLING);// esta funcion nos sirve para interrumpir el codigo cada vez que se detecte un cambio en el boton llamando a la funcion incremento cuando sea un flanco de bajada
  attachInterrupt(digitalPinToInterrupt(BOTON1), Reinicio, FALLING);
}
void loop() {
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
    tiempoAnterior = tiempoActual;
  }
}
