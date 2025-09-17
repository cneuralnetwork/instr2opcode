#include "assembler.h"

void string_to_upper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void print_16bit_data(const char *data_str) {
    long data = strtol(data_str, NULL, 16);
    unsigned char low_byte = data & 0xFF;
    unsigned char high_byte = (data >> 8) & 0xFF;
    printf("%02X %02X", low_byte, high_byte);
}
