﻿#include <stdio.h>
#include <string.h>


#define MAX_LEN 100


char arr[26][26];
char message[MAX_LEN], key[MAX_LEN], emessage[MAX_LEN], retMessage[MAX_LEN];


int findRow(char);
int findColumn(char);
int findDecRow(char, int);


int main() {
    int i, j, k, r, c;
    k = 96;


    for (i = 0; i < 26; i++) {
        k++;
        for (j = 0; j < 26; j++) {
            arr[i][j] = k++;
            if (k == 123)
                k = 97;
        }
    }


    printf("Enter message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';


    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';


    // Encryption
    for (i = 0; i < strlen(key); i++) {
        c = findRow(key[i]);
        r = findColumn(message[i]);
        emessage[i] = arr[r][c];
    }
    emessage[i] = '\0';


    printf("\nEncrypted message is:\n%s\n", emessage);


    // Decryption
    for (i = 0; i < strlen(key); i++) {
        c = findColumn(key[i]);
        r = findDecRow(emessage[i], c);
        retMessage[i] = arr[r][0];
    }
    retMessage[i] = '\0';


    printf("\nMessage Retrieved is:\n%s\n", retMessage);


    return 0;
}


int findRow(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (arr[0][i] == c)
            return i;
    }
    return -1; // Handle error (character not found)
}


int findColumn(char c) {
    int i;
    for (i = 0; i < 26; i++) {
        if (arr[i][0] == c)
            return i;
    }
    return -1; // Handle error (character not found)
}


int findDecRow(char c, int j) {
    int i;
    for (i = 0; i < 26; i++) {
        if (arr[i][j] == c)
            return i;
    }
    return -1; // Handle error (character not found)
}