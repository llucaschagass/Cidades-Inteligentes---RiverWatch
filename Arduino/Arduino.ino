#include <WiFiEsp.h>

char ssid[] = "nome_da_rede_wifi";
char pass[] = "senha_da_rede_wifi";
char serverAddress[] = "endereco_do_arduino";
int serverPort = 80;

WiFiEspClient client;

void setup() {
  Serial.begin(9600);
  WiFi.init(&Serial);
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield não encontrado.");
    while (true);
  }
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Tentando conectar-se à rede ");
    Serial.println(ssid);
    if (WiFi.begin(ssid, pass) == WL_CONNECTED) {
      break;
    }
  }
}

void loop() {
  if (client.connect(serverAddress, serverPort)) {
    Serial.println("Conectado ao ESP32");
    while (client.available()) {
      char c = client.read();
      Serial.print(c);
    }
    client.stop();
  } else {
    Serial.println("Falha na conexão com o ESP32");
  }

  delay(1000);
}
