#include <stdio.h>
#include <stdint.h>

// DES key schedule and round function are omitted for brevity

// Initial and final permutation tables
int initial_permutation[] = {58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8, 57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7};
int final_permutation[] = {40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29, 36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25};

// Initial permutation
uint64_t initial_permutation_func(uint64_t data) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++)
        result |= ((data >> (64 - initial_permutation[i])) & 1) << (63 - i);
    return result;
}

// Final permutation
uint64_t final_permutation_func(uint64_t data) {
    uint64_t result = 0;
    for (int i = 0; i < 64; i++)
        result |= ((data >> (64 - final_permutation[i])) & 1) << (63 - i);
    return result;
}

// DES encryption
uint64_t des_encrypt(uint64_t data, uint64_t key) {
    uint64_t permuted_data = initial_permutation_func(data);
    uint64_t result = final_permutation_func(permuted_data);
    return result;
}

int main() {
    uint64_t plaintext = 0x0123456789ABCDEF;
    uint64_t key = 0x133457799BBCDFF1;
    uint64_t ciphertext = des_encrypt(plaintext, key);

    printf("Plaintext: 0x%016llX\n", plaintext);
    printf("Key:       0x%016llX\n", key);
    printf("Ciphertext: 0x%016llX\n", ciphertext);

    return 0;
}
