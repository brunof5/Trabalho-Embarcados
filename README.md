# Trabalho Embarcados

Desenvolver um projeto de hardware (parte 1) e software (parte 2) de um sistema embarcado para uma aplicação específica de livre escolha do(s) aluno(s).

## Objetivo

Monitorar a temperatura/umidade de um ambiente a fim de simular seu controle pelo microcontrolador ESP32.

## Componentes

* ESP32 DevKitC V4
* DHT11
* LED
* Dois push-buttons
* Três resistores de 22 Ohms
* Um resistor de 10k Ohms
* Módulo LCD com interface serial I2C soldado

O esquemático está disponível na pasta hardware.

## Descrição do Funcionamento

O projeto utiliza o ESP32 para monitorar e exibir a temperatura e umidade de um ambiente, lidas periodicamente pelo sensor DHT11, em um display LCD com interface I2C soldado.

Se a temperatura ultrapassar um limiar inicial de 30ºC, o LED conectado ao ESP32 será acionado, simulando uma ação de controle (como irrigação em uma estufa) a fim de reduzir a temperatura do ambiente.

Se a umidade ultrapassar o limiar inicial de 80%, o LED conectado ao ESP32 será desativado, simulando uma ação de controle a fim de interromper uma irrigação, por exemplo, assim estabilizando a umidade do ambiente.

O limiar de temperatuda pode ser ajustado entre 0 e 50ºC e o limiar de umidade entre 20 e 90%. Utilizando-se de dois push buttons:
1. No estado normal do projeto o push button SW3 habilita o estado de configuração, enquanto o push button SW4 habilita manualmente a ação de controle;
2. No estado de configuração é exibido na linha 1 do display LCD "Selecione: " e na linha 2 "Temperatura", "Umidade" ou "Voltar". SW3 alterna entre as opções e SW4 confirma a opção selecionada;
3. "Temperatura" configura o novo limiar de temperatura, "Umidade" configura o novo limiar de umidade e "Voltar" retorna ao estado normal do projeto;
4. Se "Temperatura" ou "Umidade" for selecionada, então SW3 seleciona os algarismos de 0 a 9 no display LCD e SW4 confirma o algarismo;
5. Após o 2º algarismo ser confirmado, deve-se verificar se ele respeita o alcance de leitura do sensor;
6. Uma mensagem será exibida no display LCD informando ao usuário o sucesso ou falha;
7. Após 5 segundos o software retorna ao estado normal do projeto.

No display LCD serão exibidas as informações de temperatura e umidade, além do último horário de leitura.

A implementação do código está disponível na pasta software.
