#include "assembler.h"

int main() {
    char input_line[100];
    char mnemonic[20];
    char operands[80];

    printf("8085 Opcode Generator\n");
    printf("Enter instruction (e.g., 'MOV A,B', 'LXI H,1234H', 'JNZ 2000H', or 'EXIT')\n");

    while (1) {
        printf("\n> ");
        if (!fgets(input_line, sizeof(input_line), stdin)) {
            break;
        }

        input_line[strcspn(input_line, "\n")] = 0;
        string_to_upper(input_line);

        if (strcmp(input_line, "EXIT") == 0) {
            break;
        }

        char *token = strtok(input_line, " ,");
        if (token == NULL) {
            continue;
        }
        strcpy(mnemonic, token);
        
        token = strtok(NULL, "");
        if (token != NULL) {
           while(isspace((unsigned char)*token)) token++;
           strcpy(operands, token);
        } else {
           operands[0] = '\0';
        }

        int found = 0;

        if (strcmp(mnemonic, "MOV") == 0) {
            found = handle_mov_instruction(operands);
        } else if (strcmp(mnemonic, "MVI") == 0) {
            found = handle_mvi_instruction(operands);
        } else if (get_arith_op_code(mnemonic) != -1) {
            found = handle_arithmetic_instruction(mnemonic, operands);
        } else if (strcmp(mnemonic, "LXI") == 0) {
            found = handle_lxi_instruction(operands);
        } else if (strcmp(mnemonic, "INR") == 0) {
            found = handle_inr_instruction(operands);
        } else if (strcmp(mnemonic, "DCR") == 0) {
            found = handle_dcr_instruction(operands);
        } else if (strcmp(mnemonic, "INX") == 0) {
            found = handle_inx_instruction(operands);
        } else if (strcmp(mnemonic, "DCX") == 0) {
            found = handle_dcx_instruction(operands);
        } else if (mnemonic[0] == 'J') {
            found = handle_jump_instruction(mnemonic, operands);
        } else if (mnemonic[0] == 'C') {
            found = handle_call_instruction(mnemonic, operands);
        } else if (mnemonic[0] == 'R') {
            found = handle_return_instruction(mnemonic, operands);
        } else if (strcmp(mnemonic, "PUSH") == 0) {
            found = handle_push_instruction(operands);
        } else if (strcmp(mnemonic, "POP") == 0) {
            found = handle_pop_instruction(operands);
        } else if (strcmp(mnemonic, "HLT") == 0) {
            found = handle_hlt_instruction();
        } else if (strcmp(mnemonic, "NOP") == 0) {
            found = handle_nop_instruction();
        }

        if (!found) {
            printf("Error: Instruction '%s' with operands '%s' not recognized or invalid.", mnemonic, operands);
        }
    }
    printf("\nExiting.\n");
    return 0;
}
