# mqttbroker-study
# Servidor MQTT em microcontrolador ESP32 para estudo.

## Introdução
Este projeto é um estudo sobre a implementação de um servidor MQTT simples utilizando o ESP32 e a biblioteca sMQTTBroker.h. O objetivo é demonstrar a capacidade do ESP32 em gerenciar conexões MQTT e exibir informações de conexão e memória RAM em um display OLED.

## Componentes
* ESP32
* Display OLED 128x32
* Biblioteca sMQTTBroker.h
* Biblioteca Adafruit_GFX e Adafruit_SSD1306 para controle do display OLED
* Biblioteca Wire para comunicação I2C

## Funcionamento
Conexão Wi-Fi: O ESP32 se conecta à rede Wi-Fi local utilizando as credenciais definidas no código.
Iniciação do Servidor MQTT: O servidor MQTT é iniciado na porta 1883.
Exibição de Informações: As informações de conexão e memória RAM do ESP32 são exibidas no display OLED.
Atualização do Servidor: O servidor MQTT é atualizado periodicamente para manter a conexão com os clientes MQTT.

## Código
O código é dividido em dois principais componentes: setup() e loop().
setup(): Inicializa a serial, o display OLED, a conexão Wi-Fi e o servidor MQTT.
loop(): Atualiza o servidor MQTT e exibe as informações de conexão e memória RAM no display OLED.

## Observações
O código utiliza a biblioteca sMQTTBroker.h para implementar o servidor MQTT.
O display OLED é controlado utilizando as bibliotecas Adafruit_GFX e Adafruit_SSD1306.
A memória RAM é monitorada e exibida no display OLED a cada 1 segundo.

## Autor
Wanderson Vicente
Data
03/06/2024
