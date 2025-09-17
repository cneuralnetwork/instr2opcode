#include "assembler.h"

int get_reg_code(char *reg) {
    if (strcmp(reg, "B") == 0) return 0b000;
    if (strcmp(reg, "C") == 0) return 0b001;
    if (strcmp(reg, "D") == 0) return 0b010;
    if (strcmp(reg, "E") == 0) return 0b011;
    if (strcmp(reg, "H") == 0) return 0b100;
    if (strcmp(reg, "L") == 0) return 0b101;
    if (strcmp(reg, "M") == 0) return 0b110;
    if (strcmp(reg, "A") == 0) return 0b111;
    return -1;
}

int get_reg_pair_code(char *rp) {
    if (strcmp(rp, "B") == 0 || strcmp(rp, "BC") == 0) return 0b00;
    if (strcmp(rp, "D") == 0 || strcmp(rp, "DE") == 0) return 0b01;
    if (strcmp(rp, "H") == 0 || strcmp(rp, "HL") == 0) return 0b10;
    if (strcmp(rp, "SP") == 0) return 0b11;
    return -1;
}

int get_reg_pair_push_pop_code(char *rp) {
    if (strcmp(rp, "B") == 0 || strcmp(rp, "BC") == 0) return 0b00;
    if (strcmp(rp, "D") == 0 || strcmp(rp, "DE") == 0) return 0b01;
    if (strcmp(rp, "H") == 0 || strcmp(rp, "HL") == 0) return 0b10;
    if (strcmp(rp, "PSW") == 0) return 0b11;
    return -1;
}
