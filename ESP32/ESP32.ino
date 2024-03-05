#include <Arduino.h>
#include <WiFi.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 5

WiFiClient client;
const char *ssid = "nome_da_rede_wifi";
const char *password = "senha_da_rede_wifi";
const char *serverAddress = "endereco_do_arduino";
const int serverPort = 80;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Conectando ao Wi-Fi...");
  }
  Serial.println("Conectado ao Wi-Fi");
}

void loop() {
  long duration, distance;
  
  // Gera um pulso de 10 microssegundos no pino do trigger
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  // Calcula a duração do pulso recebido pelo pino do echo
  duration = pulseIn(ECHO_PIN, HIGH);
  
  // Calcula a distância em centímetros
  distance = duration * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (client.connect(serverAddress, serverPort)) {
    Serial.println("Conectado ao Arduino");
    if (distance <= 5) {
      client.print("Atenção, o rio alagou! Evite passar perto dele.");
    } else if (distance <= 20) {
      client.print("Alerta, possibilidade de alagamento no rio.");
    } else {
      client.print("Tudo normal no rio.");
    }
    client.stop();
    Serial.println("Dados enviados ao Arduino");
  } else {
    Serial.println("Falha ao conectar-se ao Arduino");
  }

  delay(5000); // Envio a cada 5 segundos
}

