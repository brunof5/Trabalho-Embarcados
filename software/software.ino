#include <Wire.h>                 // Biblioteca para gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h>    // Biblioteca para controlar display 16x2 através do I2C
#include <DHT.h>                  // Biblioteca para utilizar o sensor de temperatura e umidade DHT

#define col 16              // Define o número de colunas do display utilizado
#define lin 2               // Define o número de linhas do display utilizado
#define addr 0x27           // Define o endereço do display
#define buttonLedPin 32     // Define o pino conectado ao botão que irá ligar o LED
#define ledPin 15           // Define o pino conectado ao LED
#define buttonSensorPin 23  // Define o pino concectado ao botão que irá ler o sensor DHT
#define DHT_Pin 4           // Define o pino conectado ao sensor DHT
#define DHT_Type DHT11      // Define o tipo do sensor DHT utilizado

LiquidCrystal_I2C lcd(addr, col, lin);   // Cria o objeto lcd passando como parâmetros o endereço, o # de colunas e o # de linhas

DHT dht(DHT_Pin, DHT_Type);   // Cria o objeto do DHT pasando como parâmetros o pino conectado e o tipo

// Define os estados dos push buttons
int buttonLedState = 0;
int buttonSensorState = 0;

void setup() {
  // Inicializando os pinos
  pinMode(buttonLedPin, INPUT_PULLUP);
  pinMode(buttonSensorPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);

  lcd.init();       // Inicializa a comunicação com o display já conectado
  lcd.clear();      // Limpa a tela do display
  lcd.backlight();  // Aciona a luz de fundo do display

  lcd.setCursor(0, 0);  // Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("TESTE");   // Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1);  // Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Oi");      // Exibe a mensagem na segunda linha do display

  dht.begin();      // Inicializa o sensor DHT11
}

// Função para ler e exibir a leitura do sensor DHT no display LCD
void readDHTSensor() {
  // Curiosidade: Ler temperatura ou umidades leva 250 milissegundos
  float h = dht.readHumidity();     // Lê a umidade
  float t = dht.readTemperature();  // Lê a temperatura em Celsius

  // Se a leitura falhar exibe no display LCD e retorna para a função loop
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Falha leitura!");
    return;
  }

  // Exibe os resultados no display LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");

  lcd.setCursor(0, 1);
  lcd.print("Umid: ");
  lcd.print(h);
  lcd.print(" %");
}

void loop() {
  buttonLedState = digitalRead(buttonLedPin);
  if (buttonLedState == LOW) {
    digitalWrite(ledPin, HIGH);   // Liga o LED
  } else {
    digitalWrite(ledPin, LOW);     // Desliga o LED
  }

  buttonSensorState = digitalRead(buttonSensorPin);
  if (buttonSensorState == LOW) {
    readDHTSensor();
  }
}
