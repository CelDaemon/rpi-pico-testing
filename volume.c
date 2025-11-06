#include <hardware/gpio.h>
#include <hardware/adc.h>

#define TRUE 1
#define FALSE 0

#define LED0 15
#define LED1 14
#define LED2 13
#define LED3 12
#define LED4 11

#define POT 26

#define STATE_COUNT 5

#define DELTA 4069

#define BIT(x) (1u << (x))
#define LED_MASK (BIT(LED0) | BIT(LED1) | BIT(LED2) | BIT(LED3) | BIT(LED4))

int main() {
    gpio_init_mask(LED_MASK);

    gpio_set_dir_out_masked(LED_MASK);

    adc_init();
    adc_gpio_init(POT);
    adc_select_input(0);

    while(TRUE) {
        uint const result = adc_read();
        float const normalised = ((float) result) / DELTA;
        uint const state = normalised * STATE_COUNT;

        gpio_clr_mask(LED_MASK);

        switch(state) {
            case 5:
                gpio_put(LED4, TRUE);
            case 4:
                gpio_put(LED3, TRUE);
            case 3:
                gpio_put(LED2, TRUE);
            case 2:
                gpio_put(LED1, TRUE);
            case 1:
                gpio_put(LED0, TRUE);
        }
    }
}
