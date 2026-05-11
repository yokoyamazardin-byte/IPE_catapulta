#include <Stepper.h>
#include <SoftwareSerial.h>


void rotacaoPorDistancia(float distancia);

// Número de passos por volta do motor
const int stepsPerRevolution = 2048;

// Motores
Stepper motor1(stepsPerRevolution, 8, 10, 9, 11); 
Stepper motor2(stepsPerRevolution, 4, 6, 5, 7);  

// Comunicação com ESP8266
SoftwareSerial espSerial(2, 3); // RX=2, TX=3

// Controle de energia do ESP8266
const int espPowerPin = 12;

// Variáveis
float distancia = 0.00;
float rot=0.00;
void setup() {
  Serial.begin(9600);
  espSerial.begin(9600);

  // velocidade dos motores
  motor1.setSpeed(10);
  motor2.setSpeed(10);

  // Liga ESP8266
  pinMode(espPowerPin, OUTPUT);
  digitalWrite(espPowerPin, HIGH);
}

void loop() {
  if (espSerial.available() > 0) {
    // Recebe a distância em metros
    distancia = espSerial.parseFloat();

    Serial.print("Distancia recebida: ");
    Serial.print(distancia);
    Serial.println(" metros");

    // Usa a função para aplicar a rotação no motor 1
    rot=rotacaoPorDistancia(distancia);

    
    

    // Desliga o ESP8266 para economizar energia
    digitalWrite(espPowerPin, LOW);
    Serial.println("ESP8266 desligado.");

    // Trava o loop para não religar
    while (true) { 
     // Usa a função para aplicar a rotação no motor 1
     motor1.step(rot);

      // Motor2 faz uma volta completa
      motor2.step(stepsPerRevolution);


    }
  }
}
