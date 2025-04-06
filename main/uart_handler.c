#include "uart_handler.h"
#include <string.h>
#include "esp_log.h"

static const char *TAG = "UART";

void uart_init() {
    uart_config_t config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity    = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE
    };
    uart_param_config(UART_PORT, &config);
    uart_driver_install(UART_PORT, BUF_SIZE * 2, 0, 0, NULL, 0);
}

int send_telegram(const uint8_t *data, int len, protocol_t *proto) {
    uart_write_bytes(UART_PORT, (const char *)proto->head, proto->head_len);
    uart_write_bytes(UART_PORT, (const char *)data, len);
    uart_write_bytes(UART_PORT, (const char *)proto->tail, proto->tail_len);
    return proto->head_len + len + proto->tail_len;
}

int receive_telegram(uint8_t *out_buf, protocol_t *proto, TickType_t timeout) {
    uint8_t temp[BUF_SIZE];
    int len = uart_read_bytes(UART_PORT, temp, BUF_SIZE, timeout);
    if (len <= 0) return -1;

    int start = -1, end = -1;
    for (int i = 0; i < len - proto->head_len; ++i) {
        if (memcmp(&temp[i], proto->head, proto->head_len) == 0) {
            start = i + proto->head_len;
            break;
        }
    }
    for (int i = start; i < len - proto->tail_len; ++i) {
        if (memcmp(&temp[i], proto->tail, proto->tail_len) == 0) {
            end = i;
            break;
        }
    }

    if (start >= 0 && end > start) {
        memcpy(out_buf, &temp[start], end - start);
        return end - start;
    }

    return -1;
}