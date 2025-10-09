#include <stdio.h>
#include <stdbool.h>

#include <pico/stdlib.h>
#include <hardware/gpio.h>

const uint LED_PIN = 11;
const uint BTN_PIN = 12;

bool state_changed(bool *state_out) {
    static bool prev_state = false;
    bool state = gpio_get(BTN_PIN);
    if(state == prev_state)
        return false;
    *state_out = prev_state = state;
    return true;
}


void handle_gpio() {
    bool state;
    if(!state_changed(&state))
        return;
    gpio_put(LED_PIN, state);
}

int main() {
//     stdio_init_all();

    gpio_init_mask(1 << LED_PIN | 1 << BTN_PIN);
    gpio_init(LED_PIN);
    gpio_init(BTN_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);
    gpio_set_inover(BTN_PIN, GPIO_OVERRIDE_INVERT);

    gpio_put(LED_PIN, 0);

    gpio_set_irq_enabled_with_callback(BTN_PIN, GPIO_IRQ_LEVEL_LOW | GPIO_IRQ_LEVEL_HIGH, true, handle_gpio);
}
