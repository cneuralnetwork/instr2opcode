# 8085 instruction to opcode

simple 8085 instruction to opcode converter.

## how to run

```bash
make
./assembler
```

enter instructions like:
- `MOV A,B`
- `LXI H,1234H` 
- `JNZ 2000H`
- `EXIT` to quit

## what we did

built an 8085 assembler that converts assembly instructions to machine code opcodes.

## how opcodes are made

think of building an instruction's machine code like assembling a pizza. you have a base (the instruction type) and you add toppings (the registers or conditions).

the system breaks down every 8-bit opcode into smaller pieces, with each piece representing a part of the assembly instruction.

### the building blocks: code lookups

first, you need to know the code for each "ingredient." your notes provide these lookup tables:

**single registers (3 bits):** this code identifies a specific register like a, b, or c.

- b → 000
- c → 001
- d → 010
- e → 011
- h → 100
- l → 101
- m (memory) → 110
- a (accumulator) → 111

**conditions (3 bits):** this is for jump, call, or return instructions.

- nz (not zero) → 000
- z (zero) → 001
- nc (no carry) → 010
- and so on...

**operations (3 bits):** this defines the specific action.

- add → 000
- sub → 010 (for arithmetic)
- conditional jump → 010 (for branching)
- conditional call → 100 (for branching)

### the blueprints: assembling the opcode

once you have the codes for the ingredients, you plug them into a specific "blueprint" or "format" based on the type of instruction. your notes show four main blueprints, which can be identified by their first two bits.

**blueprint 1: arithmetic & logical (starts with 10)**
this is for instructions like add, sub, ana, xra, etc.

format: 10 | aaa | sss

- aaa: the 3-bit code for the arithmetic operation.
- sss: the 3-bit code for the source register.

example: add c
- blueprint: it's an arithmetic instruction, so the format is 10 aaasss.
- lookup codes:
  - the operation is add, so aaa = 000.
  - the source register is c, so sss = 001.
- combine: 10 + 000 + 001 → 10000001
- convert to hex: 10000001 in binary is 81h. ✅

**blueprint 2: jumps, calls, & returns (starts with 11)**
this is for instructions like jnz, cz, rnc, etc.

format: 11 | ccc | bbb

- ccc: the 3-bit code for the condition.
- bbb: the 3-bit code for the branching action (jump, call, return).

example: jnz 2000h (from your picture)
- blueprint: it's a branching instruction, so the format is 11 cccbbb.
- lookup codes:
  - the condition is nz (not zero), so ccc = 000.
  - the action is a conditional jump, so bbb = 010.
- combine: 11 + 000 + 010 → 11000010
- convert to hex: 11000010 in binary is c2h. ✅

**blueprint 3: data transfer (starts with 01)**
this is mainly for the mov instruction.

format: 01 | ddd | sss

- ddd: the 3-bit code for the destination register.
- sss: the 3-bit code for the source register.

example: mov b, a
- blueprint: it's a mov instruction, so the format is 01 dddsss.
- lookup codes:
  - the destination register is b, so ddd = 000.
  - the source register is a, so sss = 111.
- combine: 01 + 000 + 111 → 01000111
- convert to hex: 01000111 in binary is 47h. ✅

**blueprint 4: immediate instructions & more (starts with 00)**
this group has several variations. your notes highlight the format for mvi (move immediate).

format for mvi: 00 | ddd | 110

- ddd: the 3-bit code for the destination register.
- the last 3 bits (110) identify the instruction as mvi.

example: mvi a, 01h
- blueprint: the format is 00 ddd110.
- lookup code:
  - the destination register is a, so ddd = 111.
- combine: 00 + 111 + 110 → 00111110
- convert to hex: 00111110 in binary is 3eh. ✅

### final assembly: the full machine code

the opcode you just built is the first byte of the machine code.

**1-byte instructions:** for instructions like add c or mov b,a, the opcode (e.g., 81h) is the entire machine code.

**2-byte instructions:** for an instruction like mvi a, 01h, you need the opcode (3eh) followed by the 8-bit data (01h). the full machine code is 3e 01.

**3-byte instructions:** for an instruction like jnz 2000h, you need the opcode (c2h) followed by the 16-bit address. the 8085 processor uses a "little-endian" format, meaning the low-byte of the address comes first.

- address: 2000h
- low-byte: 00h
- high-byte: 20h
- the full machine code is c2 00 20.

so, the process is simply: identify the blueprint, look up the codes, and combine the bits!
