/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make caesar
 *  Execution:    ./caesar
 *
 *  Uses a given key to encrypt a message the user is prompted to input.
 *
 *  % ./caesar
 ******************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// prototypes for user-defined functions
int usage();
void encrypt(char *, char *, int);

// global variables
const int MAX_BUFFER = 4096;

int main(int argc, char **argv) {
    // ensure a key was passed
    if (argc != 2) {
        // remind user of usage
        return usage();
    }

    // retrieve key
    char* str_key = argv[1];

    // ensure the key is valid
    for (int i = 0; i < strlen(str_key); i++) {
        // check if is ith is not digit
        if (!isdigit(str_key[i])) {
            return usage();
        }
    }

    // integer for key
    int key = atoi(argv[1]);

    // ensure the key is valid
    if (key < 0) {
        // remind user of usage
        return usage();
    }

    // string for message
    char message[MAX_BUFFER];

    // ask for plaintext
    printf("plaintext: ");

    // scan message input
    scanf("%[^\n]%*c", message);

    // string for ciphertext
    char ciphertext[MAX_BUFFER];

    // encrypt message
    encrypt(message, ciphertext, key);

    // print encrypted text
    printf("ciphertext: %s\n", ciphertext);
}

// encrypts message
void encrypt(char* message, char* ciphertext, int key) {
    // calculate string length
    int length = strlen(message);

    // iterate through message
    for (int i = 0; i <= length; i++) {
        if (message[i] >= 'A' && message[i] <= 'Z') {
            // encrypt uppercase alpha
            ciphertext[i] = 'A' + (message[i] - 'A' + key) % 26;
        } else if (message[i] >= 'a' && message[i] <= 'z') {
            // encrypt lowercase alpha
            ciphertext[i] = 'a' + (message[i] - 'a' + key) % 26;
        } else {
            // do not encrypt non-alpha
            ciphertext[i] = message[i];
        }
    }
}

// prints usage information
int usage() {
    // informs the user of appropriate usage format
    printf("Usage: ./caesar key\n");

    // exits the program
    return 1;
}
