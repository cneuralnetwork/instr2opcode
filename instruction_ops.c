#include "assembler.h"

int get_arith_op_code(char *op) {
    if (strcmp(op, "ADD") == 0) return 0b000;
    if (strcmp(op, "ADC") == 0) return 0b001;
    if (strcmp(op, "SUB") == 0) return 0b010;
    if (strcmp(op, "SBB") == 0) return 0b011;
    if (strcmp(op, "ANA") == 0) return 0b100;
    if (strcmp(op, "XRA") == 0) return 0b101;
    if (strcmp(op, "ORA") == 0) return 0b110;
    if (strcmp(op, "CMP") == 0) return 0b111;
    return -1;
}

int get_condition_code(const char *mnemonic) {
    if (strstr(mnemonic, "NZ")) return 0b000;
    if (strstr(mnemonic, "Z")) return 0b001;
    if (strstr(mnemonic, "NC")) return 0b010;
    if (strstr(mnemonic, "C")) return 0b011;
    if (strstr(mnemonic, "PO")) return 0b100;
    if (strstr(mnemonic, "PE")) return 0b101;
    if (strstr(mnemonic, "P")) return 0b110;
    if (strstr(mnemonic, "M")) return 0b111;
    return -1;
}
