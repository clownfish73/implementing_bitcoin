#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define PRIVATE_KEY_SIZE 32

typedef uint8_t PrivatKey[PRIVATE_KEY_SIZE];


#define COMPRESSED_PUBLIC_KEY_SIZE 33
#define UNCOMPRESSED_PUBLIC_KEY_SIZE 65

typedef uint8_t CompressedPublicKey[COMPRESSED_PUBLIC_KEY_SIZE];
typedef uint8_t UncompressedPublicKey[UNCOMPRESSED_PUBLIC_KEY_SIZE];


