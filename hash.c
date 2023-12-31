﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned long hash_djb2(const char* str) {
    unsigned long hash = 5381;
    int c;


    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


int main() {
    char key[] = "example";
    unsigned long hash_value = hash_djb2(key);
    printf("Hash value: %lu\n", hash_value);
    return 0;
}