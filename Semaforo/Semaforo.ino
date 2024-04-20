#define LED1 2
#define LED2 3
#define LED3 4
int Num = 0;
int Retardo = 1000;

typedef enum{
  Rojo,
  Amarillo,
  Verde
}semaforo;
semaforo estado = Rojo;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  switch (estado) {
    case Rojo:
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      delay(Retardo);
      estado = Amarillo;
      break;
    case Amarillo:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      delay(Retardo);
      estado = Verde;
      break;
    case Verde:
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(Retardo);
      estado = Rojo;
      break;
  }
}
