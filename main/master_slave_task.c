#include "master_slave_task.h"
#include "uart_handler.h"
#include "protocol.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include <string.h>

#define TIMEOUT_MS 100
static const char *TAG = "ROLE";

static const char *commands[] = {
    "Q0V1E0", "I0", "I1", "I2", "I3", "I4", "I5", "I6", "I7", "I8", "I9", "I10", "I11", "I12", "I13", "I14"
};

static const char *responses[] = {
    "OK", "56000OK", "255OK", "OK\nOK", "SoftK56V_B2.1_V5.03.03.01OK",
    "SoftK56 Data Fax CARPOK", "004OK", "SoftK56 \nCModem Version 12\nRksample Version 342OK",
    "255OK", "Mar 20 2002 # 15:37:05OK", "GERMANYOK",
    "ERROR", "ERROR", "ERROR", "ERROR", "ERROR"
};

void master_task(void *arg) {
    uint8_t rx_buf[BUF_SIZE];
    for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); ++i) {
        send_telegram((const uint8_t *)commands[i], strlen(commands[i]), &master_protocol);
        int len = receive_telegram(rx_buf, &slave_protocol, pdMS_TO_TICKS(TIMEOUT_MS));
        if (len > 0) {
            rx_buf[len] = 0;
            ESP_LOGI(TAG, "RX: %s", rx_buf);
        } else {
            ESP_LOGW(TAG, "Timeout or error");
        }
        vTaskDelay(pdMS_TO_TICKS(200));
    }
    vTaskDelete(NULL);
}

void slave_task(void *arg) {
    uint8_t rx_buf[BUF_SIZE];
    while (1) {
        int len = receive_telegram(rx_buf, &master_protocol, portMAX_DELAY);
        if (len > 0) {
            rx_buf[len] = 0;
            ESP_LOGI(TAG, "Received: %s", rx_buf);
            for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++) {
                if (strcmp((char *)rx_buf, commands[i]) == 0) {
                    send_telegram((const uint8_t *)responses[i], strlen(responses[i]), &slave_protocol);
                    break;
                }
            }
        }
    }
}

void start_master_task() {
    xTaskCreate(master_task, "master_task", 4096, NULL, 5, NULL);
}

void start_slave_task() {
    xTaskCreate(slave_task, "slave_task", 4096, NULL, 5, NULL);
}