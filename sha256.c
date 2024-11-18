#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

/*
helper functions (delete later)
*/

void displayBits(long A){
    long mask = 2147483648u;
    for(int i = 0; i < 32; i ++){
        printf("%d ", (A&mask) ? 1 : 0);
        mask >>= 1;
    }
    printf("\n");
}


//------------------------------------------

#define MOD 4294967296u
#define WORD_SIZE 32u
typedef unsigned long word;

// first bits of the fractional parts of the cube roots of the first 64 prime numbers
const unsigned long K[] = 
{
0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5, 
0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174, 
0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 
0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 
0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 
0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 
0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3, 
0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

//Basic Operations
word RotR(word A, int n){return (A>>n)|(A<<(WORD_SIZE - n));}

word ShR(word A, int n){ return A>>n;}

//Functions
word Ch(word X, word Y, word Z){ return (X&Y) ^ (~X&Z);}

word Maj(word X, word Y, word Z){ (X&Y) ^ (X&Z) ^ (Y&Z);}

word S0(word X){ RotR(X, 2) ^ RotR(X, 13) ^ RotR(X, 22);}

word S1(word X){RotR(X, 6) ^ RotR(X, 11) ^ RotR(X, 25);}

word s0(word X){RotR(X, 7) ^ RotR(X, 18) ^ ShR(X, 3);}

word s1(word X){RotR(X, 17) ^ RotR(X, 19) ^ ShR(X, 10);}


//returns multiple of 64 bytes
void pad(char** text, unsigned long long int* text_length){
    //(pads with a 1 then 0s)56 then length(8)
    unsigned long long int length = ((*text_length + 63) / 64) * 64;
    char *message = (char *)malloc(length * sizeof(char));
    if (message == NULL){
        printf("Memory allocation failed\n");
        return;
    }

    memcpy(message, text, length);

}

int main() 
{
    return 0;
}

