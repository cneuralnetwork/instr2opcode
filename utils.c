#include "assembler.h"

void string_to_upper(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void print_16bit_data(const char *data_str) {
    long data;
    
    // Check if the string ends with 'H' (hexadecimal indicator)
    if (data_str[strlen(data_str) - 1] == 'H') {
        // Remove the 'H' and parse as hex
        char hex_str[20];
        strncpy(hex_str, data_str, strlen(data_str) - 1);
        hex_str[strlen(data_str) - 1] = '\0';
        data = strtol(hex_str, NULL, 16);
    } else {
        // Check if the string contains any hex characters (A-F)
        int has_hex_chars = 0;
        for (int i = 0; data_str[i] != '\0'; i++) {
            if (data_str[i] >= 'A' && data_str[i] <= 'F') {
                has_hex_chars = 1;
                break;
            }
        }
        
        if (has_hex_chars) {
            data = strtol(data_str, NULL, 16);
        } else {
            data = strtol(data_str, NULL, 10);
        }
    }
    
    unsigned char low_byte = data & 0xFF;
    unsigned char high_byte = (data >> 8) & 0xFF;
    printf("%02X %02X", low_byte, high_byte);
}
