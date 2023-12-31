﻿#include <stdio.h>
#include <string.h>


void encrypt(char *plaintext, char *key, char *ciphertext) {
    int i, j;
    int key_len = strlen(key);
    int text_len = strlen(plaintext);


    for (i = 0, j = 0; i < text_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }
        ciphertext[i] = plaintext[i] ^ key[j];
    }


    ciphertext[i] = '\0';
}


void decrypt(char *ciphertext, char *key, char *plaintext) {
    int i, j;
    int key_len = strlen(key);
    int text_len = strlen(ciphertext);


    for (i = 0, j = 0; i < text_len; i++, j++) {
        if (j == key_len) {
            j = 0;
        }


        plaintext[i] = ciphertext[i] ^ key[j];
    }


    plaintext[i] = '\0';
}
int main() {
    char plaintext[1000];
    char key[100];
    char ciphertext[1000];
    char decrypted_text[1000];


    printf("Enter plaintext to encrypt: ");
    fgets(plaintext, 1000, stdin);


    printf("Enter key: ");
    fgets(key, 100, stdin);


    encrypt(plaintext, key, ciphertext);


    printf("Ciphertext: %s\n", ciphertext);


    decrypt(ciphertext, key, decrypted_text);


    printf("Plaintext(decrypted): %s\n", decrypted_text);


    return 0;
}