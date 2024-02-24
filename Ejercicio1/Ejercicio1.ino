#define LED1 8
#define LED2 9
#define LED3 10
#define SPEED 200
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}
void loop() {
    digitalWrite(LED1, HIGH); 
    delay(SPEED);                   
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, HIGH); 
    delay(SPEED);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, HIGH); 
    delay(SPEED);
    digitalWrite(LED3, LOW);             
}
