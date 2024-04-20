const int Trigger = 3;   //Pin digital 2 para el Trigger del sensor
const int Echo = 4;   //Pin digital 3 para el Echo del sensor
#define BOTON 2
int periodo = 100;
unsigned long tiempoAnterior = 0;
bool bandera = false;
typedef enum{
  Reposo,
  Muestreo
}est;
est estado = Reposo;

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  attachInterrupt(digitalPinToInterrupt(BOTON), muestreo, FALLING);
}
 
void loop()
{
  switch(estado){
    case Reposo:
      if(bandera){
        estado = Muestreo;
      }
    break;
    case Muestreo:
      if(bandera){
        while(millis()-tiempoAnterior<=5000){
          lectura();
      }
      estado = Reposo;
    }
    break;
  
  }
}
void muestreo()
{
  unsigned long tiempoActual = millis();
  if (tiempoActual - tiempoAnterior > periodo) {
    bandera=true;
    tiempoAnterior = tiempoActual;
  }
}
void lectura()
{
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros
 
  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();
  delay(500);          //Hacemos una pausa de 100ms
}