#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
void dsa_sign(const char *message, unsigned char *signature, size_t sig_len) {
    srand(time(NULL));
    for (size_t i = 0; i < sig_len; i++) {
        signature[i] = message[i % strlen(message)] ^ (rand() % 256);
    }
}
void rsa_sign(const char *message, unsigned char *signature, size_t sig_len) {
    for (size_t i = 0; i < sig_len; i++) {
        signature[i] = message[i % strlen(message)] ^ 0xAA;
    }
}
int main() {
    const char *message = "This is a test message.";
    size_t message_len = strlen(message);
    size_t sig_len = 32; 
    unsigned char dsa_sig1[32];
    unsigned char dsa_sig2[32];
    unsigned char rsa_sig1[32];
    unsigned char rsa_sig2[32];
    dsa_sign(message, dsa_sig1, sig_len);
    dsa_sign(message, dsa_sig2, sig_len);
    rsa_sign(message, rsa_sig1, sig_len);
    rsa_sign(message, rsa_sig2, sig_len);
    printf("DSA Signature 1: ");
    for (size_t i = 0; i < sig_len; i++) printf("%02x", dsa_sig1[i]);
    printf("\n");
    printf("DSA Signature 2: ");
    for (size_t i = 0; i < sig_len; i++) printf("%02x", dsa_sig2[i]);
    printf("\n");
    printf("RSA Signature 1: ");
    for (size_t i = 0; i < sig_len; i++) printf("%02x", rsa_sig1[i]);
    printf("\n");
    printf("RSA Signature 2: ");
    for (size_t i = 0; i < sig_len; i++) printf("%02x", rsa_sig2[i]);
    printf("\n");

    return 0;
}
