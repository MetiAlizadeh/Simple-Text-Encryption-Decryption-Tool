#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void showMenu();
void encryptCaesar(char* key);
void decryptCaesar(char* key);
void encryptXOR(char* key);
void decryptXOR(char* key);

int main(void) {
    char choice;
    do {
        system("cls");
        printf("Welcome To Simple File Encryption/Decryption Tool\n");
        showMenu();
        printf("Thank You For Using The Tool\n");
        printf("Want to use again? (y/n): ");
        fflush(stdin);  // Clear the input buffer
        scanf(" %c", &choice);  // Adding a space before %c to skip any whitespace
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void showMenu() {
    int choice;
    char key[16];  // Key with a maximum length of 15 characters
    printf("1. Encrypt File Using Caesar Cipher\n");
    printf("2. Encrypt File Using XOR\n");
    printf("3. Decrypt File Using Caesar Cipher\n");
    printf("4. Decrypt File Using XOR\n");
    printf("5. Exit\n");

    printf("Enter Your Choice: ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        printf("Enter the key (max 15 chars): ");
        scanf("%15s", key);
    }

    switch (choice) {
        case 1:
            printf("Encrypting File Using Caesar Cipher\n");
            encryptCaesar(key);
            break;
        case 2:
            printf("Encrypting File Using XOR\n");
            encryptXOR(key);
            break;
        case 3:
            printf("Decrypting File Using Caesar Cipher\n");
            decryptCaesar(key);
            break;
        case 4:
            printf("Decrypting File Using XOR\n");
            decryptXOR(key);
            break;
        case 5:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid Choice\n");
    }
}

void encryptCaesar(char* key) {
    FILE *plaintext, *ciphertext;
    plaintext = fopen("result\\plaintext.txt", "r");
    ciphertext = fopen("result\\cipherEncrypted.txt", "w");
    if (plaintext == NULL || ciphertext == NULL) {
        printf("Error opening files.\n");
        return;
    }
    char ch;
    int keyLen = strlen(key);
    printf("Key Length: %d\n", keyLen);
    int i = 0;
    while ((ch = fgetc(plaintext)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + (key[i % keyLen] % 26)) % 26 + 'A';
            printf("Encrypting: %c -> %c\n", ch, ch);
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + (key[i % keyLen] % 26)) % 26 + 'a';
            printf("Encrypting: %c -> %c\n", ch, ch);
        }
        fputc(ch, ciphertext);
        i++;
    }
    fclose(plaintext);
    fclose(ciphertext);
}

void decryptCaesar(char* key) {
    FILE *ciphertext, *decrypted;
    ciphertext = fopen("result\\cipherEncrypted.txt", "r");
    decrypted = fopen("result\\cipherDecrypted.txt", "w");
    if (ciphertext == NULL || decrypted == NULL) {
        printf("Error opening files.\n");
        return;
    }
    char ch;
    int keyLen = strlen(key);
    int i = 0;
    while ((ch = fgetc(ciphertext)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - (key[i % keyLen] % 26) + 26) % 26 + 'A';
            printf("Decrypting: %c -> %c\n", ch, ch);
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - (key[i % keyLen] % 26) + 26) % 26 + 'a';
            printf("Decrypting: %c -> %c\n", ch, ch);
        }
        fputc(ch, decrypted);
        i++;
    }
    fclose(ciphertext);
    fclose(decrypted);
}

void encryptXOR(char* key) {
    FILE* plaintext, *xorEncrypted;
    plaintext = fopen("result\\plaintext.txt", "rb");  // Open in binary mode
    xorEncrypted = fopen("result\\xorEncrypted.txt", "wb");  // Open in binary mode
    if (plaintext == NULL || xorEncrypted == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int ch;
    int keyLen = strlen(key);
    int i = 0;

    while ((ch = fgetc(plaintext)) != EOF) {
        unsigned char encryptedChar = ch ^ key[i % keyLen];
        printf("Encrypting: %02X (%d) -> %02X (%d)\n", ch, ch, encryptedChar, encryptedChar); // Debug output in hex
        fputc(encryptedChar, xorEncrypted);
        i++;
    }

    fclose(plaintext);
    fclose(xorEncrypted);
}

void decryptXOR(char* key) {
    FILE* xorEncrypted, *decrypted;
    xorEncrypted = fopen("result\\xorEncrypted.txt", "rb");  // Open in binary mode
    decrypted = fopen("result\\xorDecrypted.txt", "wb");  // Open in binary mode
    if (xorEncrypted == NULL || decrypted == NULL) {
        printf("Error opening files.\n");
        return;
    }

    int ch;
    int keyLen = strlen(key);
    int i = 0;

    while ((ch = fgetc(xorEncrypted)) != EOF) {
        unsigned char decryptedChar = ch ^ key[i % keyLen];
        printf("Decrypting: %02X (%d) -> %02X (%d)\n", ch, ch, decryptedChar, decryptedChar); // Debug output in hex
        fputc(decryptedChar, decrypted);
        i++;
    }

    fclose(xorEncrypted);
    fclose(decrypted);
}
