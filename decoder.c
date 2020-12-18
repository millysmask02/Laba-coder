#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "stringutils.h"

void mutableCaesarDecoder(char* str, int offset) {
    mutableStrip(str);
    mutableToLower(str);
    for (int i = 0; i < strlen(str); ++i) {
	str[i] = (str[i] - (offset % 26));
    }
}

char* immutableCaesarDecoder(const char* str, int offset) {
    char* StrRes = immutableStrip(str);
    mutableToLower(StrRes);
    for (int i = 0; i < strlen(StrRes); ++i) {
	StrRes[i] = (str[i] - (offset % 26));   
    }
    return StrRes;
}

void mutableXorDecoder(char* str, const char* password) {
    mutableStrip(str);
    mutableToLower(str);
    int k = 0;
    for (int i = 0; i < strlen(str); ++i) {
	str[i] = (str[i] ^ password[k]);
	k = (k + 1) % strlen(password);
    }
}

char* immutableXorEncoder(const char* str, const char* password) {
    char* StrRes = immutableStrip(str);
    mutableToLower(StrRes);
    int k = 0;
    for (int i = 0; i < strlen(StrRes); ++i) {
	StrRes[i] = (StrRes[i] ^ password[k]);
	k = (k + 1) % strlen(password);
    }
    return StrRes;
}


int main() {
    char cipher[6];
    printf("Enter cipher (Caesar or XOR): "); 
    scanf("%s", cipher);
    char text[200];
    printf("Enter text: ");
    scanf("%s", text);

    if (WhatCipher(cipher, "Caesar") == 1) {
	int offset;
	printf("Enter offset: ");
        scanf("%d", &offset);
        printf("%s\n", immutableCaesarDecoder(text, offset));
    }
    else if (WhatCipher(cipher, "XOR") == 1) {
	char password[200];
	printf("Enter password: ");
        scanf("%s", password);
        printf("%s\n", immutableXorEncoder(text, password));
    }
    else {
	printf("Incorrect data");
    }

    return 0;
}
