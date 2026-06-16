#include <Stepper.h>
#include <SoftwareSerial.h>

const int passosPorVolta = 2048;
const int pinoLED = 13;
// Configuração dos Motores (Pinos validados por você)
// Motor de Desacoplamento: Pinos 12, 10, 11, 9
Stepper motorDesacoplar(passosPorVolta, 12, 10, 11, 9);
// Motor de Tração: Pinos 7, 5, 6, 4
Stepper motorTracao(passosPorVolta, 7, 5, 6, 4);

// Configuração do Bluetooth (Pino 2 = RX, Pino 3 = TX)
SoftwareSerial bluetooth(2, 3);
void desligarMotorDesacoplar() {
  digitalWrite(12, LOW);   digitalWrite(11, LOW);
  digitalWrite(10, LOW);   digitalWrite(9, LOW);
}

void desligarMotorTracao() {
  digitalWrite(7, LOW);    digitalWrite(6, LOW);
  digitalWrite(5, LOW);    digitalWrite(4, LOW);
}
float Calculodevoltas(int DistanciaDigitada) {
    if (DistanciaDigitada <= 45) return 1.5f;
    else if (DistanciaDigitada <= 50) return 1.55f;
    else if (DistanciaDigitada <= 55) return 1.6f;
    else if (DistanciaDigitada <= 60) return 1.65f;
    else if (DistanciaDigitada <= 65) return 1.7f;
    else if (DistanciaDigitada <= 70) return 1.8f;
    else if (DistanciaDigitada <= 75) return 1.9f;
    else if (DistanciaDigitada <= 80) return 1.95f;
    else if (DistanciaDigitada <= 85) return 2.0f;
    else if (DistanciaDigitada <= 90) return 2.0f;
    else if (DistanciaDigitada <= 95) return 2.0f;
    else if (DistanciaDigitada <= 100) return 2.1f;
    else if (DistanciaDigitada <= 105) return 2.2f;
    else if (DistanciaDigitada <= 110) return 2.3f;
    else if (DistanciaDigitada <= 115) return 2.4f;
    else if (DistanciaDigitada <= 120) return 2.45f;
    else if (DistanciaDigitada <= 125) return 2.5f;
    else if (DistanciaDigitada <= 130) return 2.7f;
    else if (DistanciaDigitada <= 135) return 3.0f;
    else if (DistanciaDigitada <= 140) return 3.05f;
    else if (DistanciaDigitada <= 145) return 3.1f;
    else if (DistanciaDigitada <= 150) return 3.15f;
    else if (DistanciaDigitada <= 155) return 3.2f;
    else if (DistanciaDigitada <= 160) return 3.25f;
    else if (DistanciaDigitada <= 165) return 3.3f;
    else if (DistanciaDigitada <= 170) return 3.3f;
    else if (DistanciaDigitada <= 175) return 3.3f;
    else if (DistanciaDigitada <= 180) return 3.4f;
    else if (DistanciaDigitada <= 185) return 3.5f;
    else if (DistanciaDigitada <= 190) return 3.6f;
    else if (DistanciaDigitada <= 195) return 3.7f;
    else if (DistanciaDigitada <= 200) return 3.8f;
    else if (DistanciaDigitada <= 205) return 3.9f;
    else if (DistanciaDigitada <= 210) return 3.95f;
    else if (DistanciaDigitada <= 215) return 4.0f;
    else if (DistanciaDigitada <= 220) return 4.0f;
    else if (DistanciaDigitada <= 225) return 4.0f;
    else if (DistanciaDigitada <= 230) return 4.05f;
    else if (DistanciaDigitada <= 235) return 4.1f;
    else if (DistanciaDigitada <= 240) return 4.15f;
    else if (DistanciaDigitada <= 245) return 4.2f;
    else if (DistanciaDigitada <= 250) return 4.25f;
    else if (DistanciaDigitada <= 255) return 4.3f;
    else if (DistanciaDigitada <= 260) return 4.35f;
    else if (DistanciaDigitada <= 265) return 4.4f;
    else if (DistanciaDigitada <= 270) return 4.2f;
    else if (DistanciaDigitada <= 275) return 4.2f;
    else if (DistanciaDigitada <= 280) return 4.3f;
    else if (DistanciaDigitada <= 285) return 4.35f;
    else if (DistanciaDigitada <= 290) return 4.4f;
    else if (DistanciaDigitada <= 295) return 4.45f;
    else if (DistanciaDigitada <= 300) return 4.5f;
    else if (DistanciaDigitada <= 305) return 4.5f;
    else if (DistanciaDigitada <= 310) return 4.55f;
    else if (DistanciaDigitada <= 315) return 4.6f;
    else if (DistanciaDigitada <= 320) return 4.65f;
    else if (DistanciaDigitada <= 325) return 4.7f;
    else if (DistanciaDigitada <= 330) return 4.7f;
    else if (DistanciaDigitada <= 335) return 4.8f;
    else if (DistanciaDigitada <= 340) return 4.9f;
    else if (DistanciaDigitada <= 345) return 5.0f;
    else if (DistanciaDigitada <= 350) return 5.1f;
    else if (DistanciaDigitada <= 355) return 5.2f;
    else if (DistanciaDigitada <= 360) return 5.3f;
    else if (DistanciaDigitada <= 365) return 5.4f;
    else if (DistanciaDigitada <= 370) return 5.45f;
    else if (DistanciaDigitada <= 375) return 5.5f;
    else if (DistanciaDigitada <= 380) return 5.7f;
    else if (DistanciaDigitada <= 385) return 5.8f;
    else if (DistanciaDigitada <= 390) return 6.0f;
    else if (DistanciaDigitada <= 394) return 6.2f;
    else if (DistanciaDigitada <= 400) return 6.3f;
    else return 6.3f; // limite máximo
}

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  
  motorDesacoplar.setSpeed(6);
  motorTracao.setSpeed(6);
  
  desligarMotorDesacoplar();
  desligarMotorTracao();
  pinMode(pinoLED, OUTPUT);
  Serial.println("--- CATAPULTA PRONTA: 4 BOTÕES ATIVOS ---");
}

void loop() {
  // Verifica se chegaram dados do Bluetooth ou do Monitor Serial
  digitalWrite(pinoLED, HIGH);
  if (bluetooth.available() > 0 || Serial.available() > 0) {
    
    // 1. Lê apenas a primeira letra do comando (A, B, C ou D)
    char comando = (bluetooth.available() > 0) ? bluetooth.read() : Serial.read();
    
    // Força a letra a ser maiúscula para facilitar o teste
    comando = toupper(comando); 

    // 2. Se for uma das 4 letras válidas do aplicativo, processa o comando
    if (comando == 'A' || comando == 'B' || comando == 'C' || comando == 'D') {
      
      delay(50); // Pausa essencial de 50ms para dar tempo do celular enviar o número todo
      
      // 3. Lê o número de voltas que veio logo após a letra
      float DistanciaDigitada = (bluetooth.available() > 0) ? bluetooth.parseFloat() : Serial.parseFloat();
      
      // Se não digitou nada ou deu erro, define o padrão de segurança para 0
      if (DistanciaDigitada < 0) DistanciaDigitada = 0; 
      float voltasCalculadas = Calculodevoltas(DistanciaDigitada);
      // 4. Calcula os passos baseados nas voltas
      long passosCalculados = voltasCalculadas * passosPorVolta;
      
      Serial.print("Comando: ");
      Serial.print(comando);
      Serial.print(" | Voltas: ");
      Serial.println(voltasCalculadas);

      // ==========================================
      // SEÇÃO DO MOTOR DE TRAÇÃO
      // ==========================================
      if (comando == 'A') {
        Serial.println("-> Executando: Motor Tração [HORÁRIO]");
        motorTracao.step(passosCalculados); // Passos positivos = Horário
        desligarMotorTracao();
      } 
      else if (comando == 'B') {
        Serial.println("-> Executando: Motor Tração [ANTI-HORÁRIO]");
        motorTracao.step(-passosCalculados); // Passos negativos = Inverte o sentido
        desligarMotorTracao();
      }
      
      // ==========================================
      // SEÇÃO DO MOTOR DE DESACOPLAMENTO
      // ==========================================
      else if (comando == 'C') {
        Serial.println("-> Executando: Motor Desacoplamento [HORÁRIO]");
        motorDesacoplar.step(passosCalculados); // Passos positivos = Horário
        desligarMotorDesacoplar();
      } 
      else if (comando == 'D') {
        Serial.println("-> Executando: Motor Desacoplamento [ANTI-HORÁRIO]");
        motorDesacoplar.step(-passosCalculados); // Passos negativos = Inverte o sentido
        desligarMotorDesacoplar();
      }
    }
  }
}
