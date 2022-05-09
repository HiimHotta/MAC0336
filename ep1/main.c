/* hexdump.c
*
* Thales Paiva <thalespaiva em gmail>
*
* Simples hexdump para ilustrar como ler um arquivo binario para um vetor.
* Escreve no arquivo_saida o arquivo_entrada XOR FF, byte a byte.
*
* Para compilar:
* gcc -Wall -ansi -o hexdump hexdump.c
*
* Para rodar:
* ./hexdump <arquivo_entrada> <arquivo_saida>
*
* References:
*
* add () function
*
* https://stackoverflow.com/questions/22026777/how-to-add-bits-using-bitwise
*
* isLE () function
*
* https://stackoverflow.com/questions/12791864/c-program-to-check-little-vs-big-endian/12792301#12792301
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char byte_t;

// number of rounds defined in the exercise
#define R 12

// 64 bits, but we represent in hex so 64 / 8 = 8
#define BITS 8

// check if computer is little endian (LE - 1) or big endian (BE - 0)
byte_t isLE () {
    int n = 1;

    if (*(char *) &n == 1)
        return 1;

    return 0;
}

// a + b (both 64 bits) and take module 2^64
*byte_t add (byte_t a, byte_t b) {
    byte_t carry  = a & b;

    byte_t result = a ^ b;

    while (carry != 0) {
        byte_t shiftedcarry = carry << 1;

        carry = result & shiftedcarry;

        result ^= shiftedcarry;
    }

    return result;
}

**byte_t subkey_generator (byte_t K[]) {
    // separa o espaço para L
    byte_t **L = malloc ((R + 2 * sizeof (*byte_t));


    // interador e variavel do pseudocodigo
    int i, j;

    // 1 - copia os dados para L0 e L1

    if (isLE () > 0) {
        for (int i = 0; i < BITS; i++) {
            L[0] = K_bytes[i];
            L[1] = K_bytes[i + BITS];
        }
    }
    
    // 2 - 

    for (j = 2; j < 4 * R + 2; j++) {
        //L_j <- L_j-1
        L[j] = add (L[j - 1], 0x9e3779b97f4a7151);
    }

    // create subkey array
    byte_t **k;

    k = malloc ((4 * R + 2) * sizeof (*byte_t));

    // 3 -
    k[0] = 0x8aed2a6bb7e15162;

    // 4 -
    for (j = 1; j < 4 * R + 3; j++)
        k[j] = add (k[j - 1], 0x7c159e3779b97f4a);
    

    // 5 - 
    i = 0; j = 0;

    byte_t *A = malloc (BITS * sizeof (*byte_t));

    byte_t *B = malloc (BITS * sizeof (*byte_t));

    A = 0x00000000; B = 0x00000000;

    // 6 -
    for (int s = 1; s < 4 * R + 3; s++) {
        // a)
        k[i] = add (add (k[i], A), B) << 3;

        A = k[i];

        i++;

        // b)
        L[j] = add (add (L[j], A), B) << add (A, B);

        B = L[j];

        j++;
    }

    return k;
}

int main () {

    return 0;
}