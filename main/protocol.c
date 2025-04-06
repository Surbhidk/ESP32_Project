#include "protocol.h"
#include <stdint.h>  
#include <string.h>
#include <stdio.h>

const uint8_t MASTER_HEAD[] = {0x41, 0x54};       // 'AT'
const uint8_t COMMON_TAIL[] = {0x0D, 0x0A};       // '\r\n'

protocol_t master_protocol = {
    .name = "MASTER_PROTOCOL",
    .head = MASTER_HEAD,
    .tail = COMMON_TAIL,
    .head_len = 2,
    .tail_len = 2
};

protocol_t slave_protocol = {
    .name = "SLAVE_PROTOCOL",
    .head = COMMON_TAIL,
    .tail = COMMON_TAIL,
    .head_len = 2,
    .tail_len = 2
};