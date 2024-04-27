#define LED1 8
#define LED2 9
#define LED3 10
#define SPEED 200
#define BOTON 2
bool E = true;
void setup() {
  Serial.begin(9600);
  pinMode(BOTON, INPUT_PULLUP);
}
void loop() {
  if(digitalRead(BOTON) == 0){
   
    Serial.println("hola");
    delay(80);
  }
              
}
