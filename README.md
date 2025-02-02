# U4C5O123A - Clock e Temporizadores

## Materiais necessários
1) Microcontrolador Raspberry Pi Pico W.
2) 02 LEDs (vermelho e verde).
3) 02 Resistores de 330 Ω.

## Funcionalidades do programa

1) O acionamento dos LEDs inicia na
cor vermelha, alterando para amarela e, em seguida, verde.
2) O intervalo entre os estados é de 3000ms.
4) A rotina principal imprime uma mensagem de funcionamento a cada 1000ms.

## Características
1) A mudança de estado dos LEDs foi implementa na função de call-back do temporizador, a exemplo da rotina trabalhada na aula síncrona - repeating_timer_callback().
2) Para utilizar o sinal de cor amarela na placa BitDogLab, foi necessaria a utilização dos LEDS vermelho e verde.

## Ensaio
https://drive.google.com/file/d/1Mh-ybq4Ut-AJisVfRp6H4ZCRgWKspk-C/view?usp=sharing