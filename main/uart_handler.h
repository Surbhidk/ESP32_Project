#pragma once
#include "driver/uart.h"
#include "protocol.h"

#define UART_PORT UART_NUM_1
#define BUF_SIZE 256

void uart_init();
int send_telegram(const uint8_t *data, int len, protocol_t *proto);
int receive_telegram(uint8_t *out_buf, protocol_t *proto, TickType_t timeout);