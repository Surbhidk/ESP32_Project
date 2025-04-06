#pragma once

#include <stdint.h>


#define MAX_MSG_SIZE 128

typedef struct {
    const char *name;
    const uint8_t *head;
    const uint8_t *tail;
    int head_len;
    int tail_len;
} protocol_t;

extern protocol_t master_protocol;
extern protocol_t slave_protocol;