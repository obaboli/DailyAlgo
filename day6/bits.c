#include <limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Helpers
void setBit(void* value, uint8_t bitnumber)
{
    uint32_t* dummy = (uint32_t*)value;
    *dummy |= 1UL << bitnumber;
}

void clearBit(void* value, uint8_t bitnumber)
{
    uint32_t* dummy = (uint32_t*)value;
    *dummy &= ~(1UL << bitnumber);
}

void toggleBit(void* value, uint8_t bitnumber)
{
    uint32_t* dummy = (uint32_t*)value;
    *dummy ^= (1UL << bitnumber);
}

bool checkBit(void* value, uint8_t bitnumber)
{
    uint32_t* dummy = (uint32_t*)value;
    return (*dummy >> bitnumber) & 1UL;
}

//assumes little endian
void printBinary(size_t const size, void const* const ptr)
{
    unsigned char* b = (unsigned char*)ptr;
    unsigned char byte;
    int i, j;

    for (i = size - 1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

//Problems
uint8_t hammingWeight(uint32_t value)
{
    uint8_t count = 0;

    while (value) {
        if (checkBit(&value, 0)) {
            count++;
        }
        value >>= 1;
    }

    return count;
}

bool isPowerOfTwo(uint32_t value)
{
    uint8_t count = 0;

    while (value) {
        if (checkBit(&value, 0)) {
            count++;
        }

        if (count > 1) {
            return false;
        }
        value >>= 1;
    }

    return (count == 1);
}

uint32_t reverseBits(uint32_t value)
{
    uint32_t newValue = 0;
    uint32_t spot = 1;

    while (value) {
        if (checkBit(&value, 0)) {
            setBit(&newValue, (sizeof(uint32_t) * CHAR_BIT) - spot);
        }

        spot++;
        value >>= 1;
    }
    return newValue;
}

int absBits(int value)
{
    int mask = value >> 31;
    value = value ^ mask;
    return (value - mask);
}

bool isPalindrome(uint32_t value)
{
    uint8_t lower = 0;
    uint8_t upper = sizeof(value) * CHAR_BIT - 1;

    while (lower < upper) {
        if (checkBit(&value, lower) != checkBit(&value, upper)) {
            return false;
        }
        lower++;
        upper--;
    }

    return true;
}

int main()
{
    uint8_t data = 55;
    printBinary(sizeof(data), &data);

    data = 0;
    setBit(&data, 1);
    printBinary(sizeof(data), &data);

    clearBit(&data, 1);
    printBinary(sizeof(data), &data);

    toggleBit(&data, 1);
    printBinary(sizeof(data), &data);

    printf(checkBit(&data, 1) ? "true\n" : "false\n");

    toggleBit(&data, 1);
    printBinary(sizeof(data), &data);

    printf("%u\n", checkBit(&data, 1));

    data = 55;
    printf("%u\n", hammingWeight(data));

    data = 16;
    printf(isPowerOfTwo(data) ? "true\n" : "false\n");

    data = 17;
    printf(isPowerOfTwo(data) ? "true\n" : "false\n");

    uint32_t dataB = reverseBits(3);
    printBinary(sizeof(dataB), &dataB);

    dataB = 3221225475;
    printf(isPalindrome(dataB) ? "true\n" : "false\n");

    printf("%d\n", absBits(-1));
    printf("%d\n", absBits(-89));
    printf("%d\n", absBits(9));

    return 0;
}
