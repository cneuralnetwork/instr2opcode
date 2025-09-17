#ifndef ASSEMBLER_H
#define ASSEMBLER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Function declarations for register operations
int get_reg_code(char *reg);
int get_reg_pair_code(char *rp);
int get_reg_pair_push_pop_code(char *rp);

// Function declarations for instruction operations
int get_arith_op_code(char *op);
int get_condition_code(const char *mnemonic);

// Function declarations for utility operations
void string_to_upper(char *str);
void print_16bit_data(const char *data_str);

// Function declarations for instruction handlers
int handle_mov_instruction(char *operands);
int handle_mvi_instruction(char *operands);
int handle_arithmetic_instruction(char *mnemonic, char *operands);
int handle_lxi_instruction(char *operands);
int handle_lda_instruction(char *operands);
int handle_inr_instruction(char *operands);
int handle_dcr_instruction(char *operands);
int handle_inx_instruction(char *operands);
int handle_dcx_instruction(char *operands);
int handle_jump_instruction(char *mnemonic, char *operands);
int handle_call_instruction(char *mnemonic, char *operands);
int handle_return_instruction(char *mnemonic, char *operands);
int handle_push_instruction(char *operands);
int handle_pop_instruction(char *operands);
int handle_hlt_instruction(void);
int handle_nop_instruction(void);

#endif
