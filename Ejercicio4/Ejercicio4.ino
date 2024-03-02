#define BOTON 2
#define LED 3
int cont = 0;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(BOTON), Incremento, FALLING); // esta funcion nos sirve para interrumpir el codigo cada vez que se detecte un cambio en el boton llamando a la funcion incremento cuando sea un flanco de bajada
}
void loop() {
  Serial.println(cont);  
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);                    
  digitalWrite(LED_BUILTIN, LOW);   
  delay(1000);           
}
void Incremento()
{
  cont = cont +1;
  digitalWrite(LED, !digitalRead(LED)); //se niega el estado del leda cada que se se presiona el boton
}