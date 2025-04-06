#include "master_slave_task.h"
#include "uart_handler.h"
#include "protocol.h"
#include "driver/gpio.h"

#define MODE_GPIO GPIO_NUM_0 

void app_main() {
    gpio_set_direction(MODE_GPIO, GPIO_MODE_INPUT);
    bool is_master = gpio_get_level(MODE_GPIO);

    uart_init();

    if (is_master) {
        start_master_task();
    } else {
        start_slave_task();
    }
}