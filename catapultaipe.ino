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
float Calculodevoltas(float DistanciaDigitada) {
//parte do calculo usando o polinomio 
  return DistanciaDigitada;
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
