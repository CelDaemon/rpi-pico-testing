#include <stdio.h>
#include <stdbool.h>

#include <pico/stdlib.h>
#include <hardware/gpio.h>
#include <hardware/adc.h>
const uint LDR_PIN = 28;
const uint LED_PIN = 15;



int main() {
     stdio_init_all();
     printf("Meow\n");

     gpio_init(LED_PIN);
     gpio_set_dir(LED_PIN, GPIO_OUT);
     adc_init();

     adc_gpio_init(LDR_PIN);
     adc_select_input(2);

     while(true) {
         const float conversion_factor = 3.3f / (1 << 12);
         uint16_t result = adc_read();
         printf("Raw value: %d (0x%03x), voltage: %f V\n", result, result, result * conversion_factor);
         gpio_put(LED_PIN, result > 3000);
         sleep_ms(10);
     }

}
