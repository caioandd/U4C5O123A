#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

//GPIOS
#define led_red 13
#define led_green 11

volatile int estado = 0; //Estado atual da repetição do callback

void leds();

bool repeating_timer_callback(struct repeating_timer *t){
    switch (estado){
      case 0:
        printf("Sinal vermelho!\n"); //Acende cor vermelha
        gpio_put(led_red, true);
        gpio_put(led_green, false);
        break;
      case 1:
        printf("Sinal amarelo!\n");
        gpio_put(led_green, true); //Acende cor amarela (Vermelho + verde = amarelo)
        break;
      case 2:
        printf("Sinal verde!\n"); //Acende cor verde
        gpio_put(led_red, false);
        break;
    }
    estado++; //Incremento após conclusão do case
    if (estado>2){
      estado=0; //Limite de incremento
    }
  return true;
}

int main(){
  stdio_init_all();
  leds();

  struct repeating_timer timer;
  add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); //Chama função callback a cada 3000ms
  printf("O semáforo está inicializando...\n");
  sleep_ms(3000);
  while (true){
    printf("O semáforo está em funcionamento.\n"); //Repetição principal a cada 1000ms
    sleep_ms(1000);
  }
}
//Inicialização de LEDs
void leds(){
  gpio_init(led_red);
  gpio_init(led_green);

  gpio_set_dir(led_red, GPIO_OUT);
  gpio_set_dir(led_green, GPIO_OUT);
}