// Código para fins didáticos sobre Broker MQTT
// Autor: Wanderson Vicente
// Data: 03/07/2024
// Definições de pinos Esp32:
// SDA - > pino D21
// SCL - > pino D22


#include<sMQTTBroker.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(); // Definição Objeto display

// Exemplo tirado da biblioteca sMQTTBroker
class MyBroker:public sMQTTBroker
{
public:
    bool onEvent(sMQTTEvent *event) override
    {
        switch(event->Type())
        {
        case NewClient_sMQTTEventType:
            {
                sMQTTNewClientEvent *e=(sMQTTNewClientEvent*)event;
                e->Login();
                e->Password();
            }
            break;
        case LostConnect_sMQTTEventType:
            WiFi.reconnect();
            break;
        case UnSubscribe_sMQTTEventType:
        case Subscribe_sMQTTEventType:
            {
                sMQTTSubUnSubClientEvent *e=(sMQTTSubUnSubClientEvent*)event;
            }
            break;
        }
        return true;
    }
};

///////////

MyBroker broker; // Definição do objeto broker
// Definição das variáveis 
unsigned long Time;
unsigned long freeRam;

void setup()
{
    Serial.begin(115200); // Inicialização da serial
    Wire.begin(); // inicialização wire para comunicação I2C
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Inicialização do display oled
    display.setTextColor(WHITE); //Define cor do texto para branco
    display.setTextSize(1); //Define tamanho do texto
    display.clearDisplay(); // Limpa display
    const char* ssid = "net-work";         // SSID da rede wi-fi local
    const char* password = "passwd"; // Password da rede
    WiFi.begin(ssid, password); // Solicita conexão 
    while (WiFi.status() != WL_CONNECTED) { // Fica em loop até a conexão
        delay(1000);
    }
    // exibe as informações na serial
    Serial.println("Connection established!");  // 
    Serial.print("IP address:\t");
    Serial.println(WiFi.localIP()); // mostra o IP do esp32
    // ebibe as informações  no display oled
    display.clearDisplay(); // limpa display
    display.setCursor(2,0); // posiciona cursor pixel coluna x linha
    display.print(F("Server MQTT BRoker"));
    display.setCursor(2,10);
    display.print(F("IP address:"));
    display.setCursor(2,25);
    display.print(WiFi.localIP());
    display.display();

    delay(3000); // pausa de 3 segundos 
    const unsigned short mqttPort=1883; // define porta do servidor
    broker.init(mqttPort); // iniciar servidor na porta definida
    // Definir no futuro parametros de login
    // no servidor mqtt
    Time=millis();
    freeRam=ESP.getFreeHeap();
};
void loop()
{
    broker.update();
    // Testar novas funções da biblioteca
    if(millis()-Time>1000)
    {
      Time=millis();
      if(ESP.getFreeHeap()!=freeRam)
      {
        freeRam=ESP.getFreeHeap();
        // Impressão memória RAM na serial
      Serial.println(freeRam);
      Serial.print(F("RAM:"));
      // Impressão dos dados no display oled
      display.clearDisplay();
      display.setCursor(2,0);
      display.print(F("IP address:\t"));
      display.setCursor(2,10);
      display.print(WiFi.localIP());
      display.display();
      display.setCursor(2,25);
      display.print(F("RAM: "));
      display.setCursor(25,25);
      display.print(freeRam);
      display.display(); 
      }
    }
};
