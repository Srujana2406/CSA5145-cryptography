#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#define BLOCK_SIZE 8
#define KEY_SIZE 24
void des_encrypt_block(uint8_t *input, uint8_t *output, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i % 8];
    }
}
void des_decrypt_block(uint8_t *input, uint8_t *output, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        output[i] = input[i] ^ key[i % 8];
    }
}
void triple_des_encrypt(uint8_t *input, uint8_t *output, uint8_t *key1, uint8_t *key2, uint8_t *key3) {
    uint8_t temp[BLOCK_SIZE];
    des_encrypt_block(input, temp, key1);
    des_decrypt_block(temp, temp, key2);
    des_encrypt_block(temp, output, key3);
}
void triple_des_decrypt(uint8_t *input, uint8_t *output, uint8_t *key1, uint8_t *key2, uint8_t *key3) {
    uint8_t temp[BLOCK_SIZE];
    des_decrypt_block(input, temp, key3);
    des_encrypt_block(temp, temp, key2);
    des_decrypt_block(temp, output, key1);
}

int main() {
    uint8_t key1[8] = { 'k', 'e', 'y', '1', 'k', 'e', 'y', '1' };
    uint8_t key2[8] = { 'k', 'e', 'y', '2', 'k', 'e', 'y', '2' };
    uint8_t key3[8] = { 'k', 'e', 'y', '3', 'k', 'e', 'y', '3' };
    uint8_t plaintext[] = "This is a test message.";
    int len = strlen((const char*)plaintext);
    int padded_len = ((len / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    uint8_t padded_plaintext[padded_len];
    memset(padded_plaintext, 0, padded_len);
    memcpy(padded_plaintext, plaintext, len);

    printf("Plaintext: %s\n", plaintext);
    uint8_t ciphertext[padded_len];
    for (int i = 0; i < padded_len; i += BLOCK_SIZE) {
        triple_des_encrypt(padded_plaintext + i, ciphertext + i, key1, key2, key3);
    }

    printf("Ciphertext (in hex): ");
    for (int i = 0; i < padded_len; i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    uint8_t decryptedtext[padded_len];
    for (int i = 0; i < padded_len; i += BLOCK_SIZE) {
        triple_des_decrypt(ciphertext + i, decryptedtext + i, key1, key2, key3);
    }

    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}

