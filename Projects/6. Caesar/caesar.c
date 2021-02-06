/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make caesar
 *  Execution:    ./caesar
 *
 *
 *
 *  % ./caesar
 ******************************************************************************/
#include <stdio.h>
#include <string.h>

// prototypes for user-defined functions
int usage();

int main(int argc, char **argv) {
    // max text character length
    const int MAX_CHARS = 5000;

    // constants for en- and de-cryption
    const int a = (int) 'a', A = (int) 'A',
                z = (int) 'z', Z = (int) 'Z';

    // constant for alphabetic range
    const int range = z - a + 1;

    // stores the key
    int k = -1;

    // checks for correct usage format
    if (argc != 2) {
        // prints usage information
        return usage();
    } else {
        // sets the key to given key
        k = atoi(argv[1]);
//-------------------------------------
        // make sure it is not a string
        if (k <= 0) {
            // prints usage information
            return usage();
        }
    }

    // calculate offset
    int offset = k % range;

    // prompts the user for plaintext
    printf("plaintext: ");

    // scans and stores the plaintext as a char[]
    char plaintext[MAX_CHARS];
    scanf("%[^\n]%*c", plaintext);

    // calculates the length of the text
    int length = strlen(plaintext);

    // allocates space for the encrypted text
    char ciphertext[length];

    // encrypts the plaintext
    for (int i = 0; i < length; i++) {
        // stores the current character in iteration
        char c = plaintext[i];

        // case one: for uppercase characters
        if (c >= A && c <= Z) {
            // encrypt the character
            ciphertext[i] = (char) (c + (c + offset) % Z);
        }

        // case two: for lowercase characters
        else if (c >= a && c <= a) {
            // encrypt the character
            ciphertext[i] = (char) (c + (c + (c + offset) % z));
        }

        // case three: non-alpha character
        else {
            // leave the character
            ciphertext[i] = c;
        }
    }

    // print ciphertext
    printf("%s\n", ciphertext);

    // helper code
    printf("key %i\n", k);
    printf("a: %i\nA: %i\n", 'a', 'A');
    printf("z: %i\nZ: %i\n", 'z', 'Z');
}


// prints ysage information
int usage() {
    // informs the user of appropriate usage format
    printf("Usage: ./caesar key\n");

    // exits the program
    return 1;
}
