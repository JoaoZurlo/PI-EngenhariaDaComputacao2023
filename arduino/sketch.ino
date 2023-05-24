#include <TimeAlarms.h>
#include <ESP8266WiFi.h> // ou #include <ESP32WiFi.h> para ESP32

// Definição dos pinos do Arduino
int motor_pin1 = 2; // Pino 2 para controle do motor
int motor_pin2 = 3; // Pino 3 para controle do motor
int led_verde_pin = 4; // Pino 4 para o LED verde
int led_vermelho_pin = 5; // Pino 5 para o LED vermelho

// Definição das credenciais da rede Wi-Fi
const char* ssid = "nome_da_rede";
const char* password = "senha_da_rede";

// Criação do cliente Wi-Fi
WiFiClient client;

void setup() {
  // Inicialização dos pinos
  pinMode(motor_pin1, OUTPUT);
  pinMode(motor_pin2, OUTPUT);
  pinMode(led_verde_pin, OUTPUT);
  pinMode(led_vermelho_pin, OUTPUT);

  // Conexão à rede Wi-Fi
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Conectando-se à rede ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Conectado à rede Wi-Fi");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());

  // Criação do temporizador para executar a função do motor a cada 40 minutos
  Alarm.timerRepeat(2400, motorFunction); // 2400 segundos = 40 minutos
}

void loop() {
  // Verificação da conexão Wi-Fi
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Conexão Wi-Fi perdida");
    WiFi.begin(ssid, password);
  }

  // Verificação da conexão do cliente Wi-Fi
  if (!client.connected()) {
    Serial.println("Cliente desconectado");
    connectToServer();
  }

  // Execução da biblioteca TimeAlarms
  Alarm.delay(1000);
}

void connectToServer() {
  // Conexão ao servidor
  Serial.println("Conectando-se ao servidor...");
  while (!client.connect("nome_do_dispositivo")) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("");
  Serial.println("Conectado ao servidor");
}

void motorFunction() {
  // Ligar o motor e movê-lo para frente ou para trás
  digitalWrite(motor_pin1, HIGH);
  digitalWrite(motor_pin2, LOW);
  digitalWrite(led_verde_pin, HIGH);
  digitalWrite(led_vermelho_pin, LOW);
  delay(20000); // Mantém o motor ligado por 20 segundos
  digitalWrite(motor_pin1, LOW);
  digitalWrite(motor_pin2, LOW);
  digitalWrite(led_verde_pin, LOW);
  digitalWrite(led_vermelho_pin, HIGH);
}