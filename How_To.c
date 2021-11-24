#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Allows storage of different data types in the same memory location
// Each member of a union shares the same memory location

/* typedef struct
{
    uint8_t enable : 1;
    uint8_t ready : 1;
    uint8_t mode : 2;
    uint8_t something_else : 1;
} RegBits;

typedef union 
{
    RegBits bits;
    uint8_t byte;
} HardwareRegisterA; */

typedef union 
{
    struct 
    {
        uint8_t byte1;
        uint8_t byte2;
        uint8_t byte3;
        uint8_t byte4;
    }bytes;
    uint32_t word;    
} HardwareRegisterB;

/* void printBits(void *data, int size)
{
    uint8_t *bytes = data;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8; j++)
        {
           printf("%d", (bytes[i] >> j) & 1);
        }        
    }
    printf("\n");    
} */

int main()
{
    system("cls");

    /* HardwareRegisterA regA = {.byte = 0x01};
    printf("RegA: 0x%02X, ", regA.byte);
    printBits(&regA, sizeof(regA));

    regA.bits.mode = 3;
    printf("RegA: 0x%02X, ", regA.byte);
    printBits(&regA, sizeof(regA)); */

    HardwareRegisterB regB = {.word = 0xAABBCCDD}; // initialising the word 
    printf("regB: %X\n", regB.word);

    regB.bytes.byte2 = 0; // Changing the second byte CC to 00 (bytes read from right to left, DD = 1, etc)
    printf("regB: %X\n", regB.word);
    
    printf("\n\n");
    return EXIT_SUCCESS;
}
