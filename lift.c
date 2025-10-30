#include <stdbool.h>

#include <pico/stdlib.h>
#include <hardware/gpio.h>

#define BIT(x) (1u << (x))

#define MOVE_DELAY 2000
#define ALRM_DELAY 100

#define LED1 27
#define LED2 26
#define LED3 22

#define BUZ 21

#define BTN1 20
#define BTN2 19
#define BTN3 18

#define ALRM_BTN 17

#define BTN_TO_FLOOR(btn) \
    ( btn == BTN1 ? 0 \
      : btn == BTN2 ? 1 \
      : btn == BTN3 ? 2 \
      : 0 )

#define FLOOR_TO_LED(floor) \
    ( floor == 0 ? LED1 \
      : floor == 1 ? LED2 \
      : floor == 2 ? LED3 \
      : 0 )

bool btn1_state = false;
bool btn2_state = false;
bool btn3_state = false;
bool alrm_btn_state = false;

bool is_alarming = false;

uint current_floor = 0;
uint target_floor = 0;

absolute_time_t move_timer = 0;

bool btn_pressed(uint btn, bool *store) {
    bool current_state = !gpio_get(btn);
    if(current_state == *store)
        return false;
    *store = current_state;
    return current_state;
}

int sign(int a) {
    if(a == 0) return 0;
    if(a < 0) return -1;
    return 1;
}

void update_leds() {
    gpio_put(LED1, false);
    gpio_put(LED2, false);
    gpio_put(LED3, false);
    gpio_put(FLOOR_TO_LED(current_floor), true);
}

void alarm_run() {
    if(!is_alarming)
        return;
    static uint switch_timer = 0;
    absolute_time_t current_time = get_absolute_time();
    if(current_time < switch_timer) 
        return;
    gpio_put(BUZ, !gpio_get(BUZ));
    switch_timer = delayed_by_ms(current_time, ALRM_DELAY);
}

void alarm_start() {
    is_alarming = true;
}
void alarm_stop() {
    is_alarming = false;
    gpio_put(BUZ, false);
}

void set_target_floor(uint floor) {
    int previous_dir = sign(target_floor - current_floor);
    target_floor = floor;
    alarm_stop();
    int dir = sign(target_floor - current_floor);
    if(previous_dir != dir)
        move_timer = delayed_by_ms(get_absolute_time(), MOVE_DELAY);
}

void lift_stop() {
    target_floor = current_floor;
}

void lift_move() {
    int dir = sign(target_floor - current_floor);
    if(dir == 0)
        return;
    absolute_time_t current_time = get_absolute_time();
    if(current_time < move_timer)
        return;
    current_floor += dir;
    update_leds();
    move_timer = delayed_by_ms(current_time, MOVE_DELAY);
}

int main() {
    gpio_init_mask(
        BIT(LED1)     |
        BIT(LED2)     |
        BIT(LED3)     |
        BIT(BUZ)      |
        BIT(BTN1)     |
        BIT(BTN2)     |
        BIT(BTN3)     |
        BIT(ALRM_BTN)
    );

    gpio_set_dir_out_masked(
        BIT(LED1) |
        BIT(LED2) |
        BIT(LED3) |
        BIT(BUZ)
    );

    gpio_set_dir_in_masked(
        BIT(BTN1)     |
        BIT(BTN2)     |
        BIT(BTN3)     |
        BIT(ALRM_BTN)
    );

     gpio_pull_up(BTN1);
     gpio_pull_up(BTN2);
     gpio_pull_up(BTN3);
     gpio_pull_up(ALRM_BTN);

     update_leds();
     while(true) {
         if(btn_pressed(ALRM_BTN, &alrm_btn_state)) {
             target_floor = current_floor;
             alarm_start();
         } else if(btn_pressed(BTN1, &btn1_state)) {
             set_target_floor(BTN_TO_FLOOR(BTN1));
         } else if(btn_pressed(BTN2, &btn2_state)) {
             set_target_floor(BTN_TO_FLOOR(BTN2));
         } else if(btn_pressed(BTN3, &btn3_state)) {
             set_target_floor(BTN_TO_FLOOR(BTN3));
         }
         alarm_run();
         lift_move();
     }
}
