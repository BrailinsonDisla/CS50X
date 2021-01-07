/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make hello
 *  Execution:    ./hello
 *
 *  Prints "hello, brai" to the standard output device -- terminal.
 *    - where brai is the input (name) provided by the user.
 *
 *  % ./hello
 ******************************************************************************/
#include <stdio.h>

// max number of characters constant
const int MAX_CHARS = 20;

int main(void) {
    // asks the user for name
    printf("What's your name? ");

    // scans and stores the name as a char[]
    char name[MAX_CHARS];
    scanf("%[^\n]%*c", name);


    // prints 'hello, *name*'
    printf("hello, %s\n", name);

    // exit
    return 0;
}

/******************************************************************************
 *  Notes:
 *    - main() or main(int argc, char** argv) is the entry point
 *      + the return statemnt indicates the sucessfulness of the program
 *          * by convention
 *            - return value of 0 indicates successfulness
 *            - return value of any non-zero number indicates failure
 *          * return can be omitted for main
 *    - in scanf(...), %[^\n] defines a new line as delimeter
 ******************************************************************************/
