int opcion;

typedef enum{
  Piso1 = 1,
  Piso2 = 2,
  Piso3 = 3
}ascensor;
ascensor nivel = Piso1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  Serial.print("El ascensor esta en el piso: ");
  Serial.println(nivel);
  opcion = Serial.read();
  delay(1000);
  
  switch (nivel){
    case Piso1:
       if(opcion == '1'){
        Serial.println("Ya estas en el piso 1");
       }
       if(opcion == '2'){
        Serial.println("Subiendo....");
        nivel = Piso2;
       }
       if(opcion == '3'){
        Serial.println("Subiendo....");
        nivel = Piso3;
       }
    break;

    case Piso2:
       if(opcion == '1'){
        Serial.println("bajando....");
        nivel = Piso1;
       }
       if(opcion == '2'){
        Serial.println("Ya estas en el piso 2");
       }
       if(opcion == '3'){
        Serial.println("Subiendo....");
        nivel = Piso3;
       }
    break;

    case Piso3:
       if(opcion == '1'){
        Serial.println("bajando....");
        nivel = Piso1;
       }
       if(opcion == '2'){
        Serial.println("bajando....");
        nivel = Piso2;
       }
       if(opcion == '3'){
        Serial.println("Ya estas en el piso 3");
       }
    break;
  }
}

