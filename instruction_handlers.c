#include "assembler.h"

int handle_mov_instruction(char *operands) {
    char *dest_str = strtok(operands, ", ");
    char *src_str = strtok(NULL, ", ");
    if (dest_str && src_str) {
        int dest_code = get_reg_code(dest_str);
        int src_code = get_reg_code(src_str);
        if (dest_code != -1 && src_code != -1) {
            unsigned char opcode = 0b01000000 | (dest_code << 3) | src_code;
            printf("%02X", opcode);
            return 1;
        }
    }
    return 0;
}

int handle_mvi_instruction(char *operands) {
    char *reg_str = strtok(operands, ", ");
    char *data_str = strtok(NULL, ", ");
    if (reg_str && data_str) {
        int reg_code = get_reg_code(reg_str);
        if (reg_code != -1) {
            unsigned char opcode = 0b00000110 | (reg_code << 3);
            long data = strtol(data_str, NULL, 16);
            printf("%02X %02X", opcode, (unsigned char)data);
            return 1;
        }
    }
    return 0;
}

int handle_arithmetic_instruction(char *mnemonic, char *operands) {
    int op_code = get_arith_op_code(mnemonic);
    int reg_code = get_reg_code(operands);
    if (reg_code != -1) {
        unsigned char opcode = 0b10000000 | (op_code << 3) | reg_code;
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_lxi_instruction(char *operands) {
    char *rp_str = strtok(operands, ", ");
    char *data_str = strtok(NULL, ", ");
    if (rp_str && data_str) {
        int rp_code = get_reg_pair_code(rp_str);
        if (rp_code != -1) {
            unsigned char opcode = 0b00000001 | (rp_code << 4);
            printf("%02X ", opcode);
            print_16bit_data(data_str);
            return 1;
        }
    }
    return 0;
}

int handle_inr_instruction(char *operands) {
    int reg_code = get_reg_code(operands);
    if (reg_code != -1) {
        unsigned char opcode = 0b00000100 | (reg_code << 3);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_dcr_instruction(char *operands) {
    int reg_code = get_reg_code(operands);
    if (reg_code != -1) {
        unsigned char opcode = 0b00000101 | (reg_code << 3);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_inx_instruction(char *operands) {
    int rp_code = get_reg_pair_code(operands);
    if (rp_code != -1) {
        unsigned char opcode = 0b00000011 | (rp_code << 4);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_dcx_instruction(char *operands) {
    int rp_code = get_reg_pair_code(operands);
    if (rp_code != -1) {
        unsigned char opcode = 0b00001011 | (rp_code << 4);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_jump_instruction(char *mnemonic, char *operands) {
    if (strcmp(mnemonic, "JMP") == 0) {
        unsigned char opcode = 0b11000011;
        printf("%02X ", opcode);
        print_16bit_data(operands);
        return 1;
    } else {
        int cond_code = get_condition_code(mnemonic);
        if (cond_code != -1) {
            unsigned char opcode = 0b11000010 | (cond_code << 3);
            printf("%02X ", opcode);
            print_16bit_data(operands);
            return 1;
        }
    }
    return 0;
}

int handle_call_instruction(char *mnemonic, char *operands) {
    if (strcmp(mnemonic, "CALL") == 0) {
        unsigned char opcode = 0b11001101;
        printf("%02X ", opcode);
        print_16bit_data(operands);
        return 1;
    } else {
        int cond_code = get_condition_code(mnemonic);
        if (cond_code != -1) {
            unsigned char opcode = 0b11000100 | (cond_code << 3);
            printf("%02X ", opcode);
            print_16bit_data(operands);
            return 1;
        }
    }
    return 0;
}

int handle_return_instruction(char *mnemonic, char *operands __attribute__((unused))) {
    if (strcmp(mnemonic, "RET") == 0) {
        unsigned char opcode = 0b11001001;
        printf("%02X", opcode);
        return 1;
    } else {
        int cond_code = get_condition_code(mnemonic);
        if (cond_code != -1) {
            unsigned char opcode = 0b11000000 | (cond_code << 3);
            printf("%02X", opcode);
            return 1;
        }
    }
    return 0;
}

int handle_push_instruction(char *operands) {
    int rp_code = get_reg_pair_push_pop_code(operands);
    if (rp_code != -1) {
        unsigned char opcode = 0b11000101 | (rp_code << 4);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_pop_instruction(char *operands) {
    int rp_code = get_reg_pair_push_pop_code(operands);
    if (rp_code != -1) {
        unsigned char opcode = 0b11000001 | (rp_code << 4);
        printf("%02X", opcode);
        return 1;
    }
    return 0;
}

int handle_hlt_instruction(void) {
    printf("76");
    return 1;
}

int handle_nop_instruction(void) {
    printf("00");
    return 1;
}
