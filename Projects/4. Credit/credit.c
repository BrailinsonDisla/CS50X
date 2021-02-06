/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make credit
 *  Execution:    ./credit
 *
 *  Checks if a given card number is valid using Luhn's checksun algorithm, and
 *  identifies its financial institution based on initial digital signature
 *      -- if valid prints whether it is a American Express, Mastercard or Visa
 *
 *  The program implements a user-defined representation of a card with their
 *  respective number, its institutional association and if it is valid.
 *
 *  % ./credit
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// user defined type for cards, and their validity and financial institution
typedef struct {
    // stores card number
    long int number;

    // stores validity
    bool validity;

    // stores financial institution
    char finInstitution[15];
} cc;

// prototype for user-defined functions
cc createCard(long int number);
bool validateCard(cc *card);
bool checksum(cc *card, int length);
bool finInstitution(cc *card, int length, int  firstTwoDigits);

int main(int argc, char** argv) {
    // stores card number
    long int number;

    while (number <= 0) {
        // prompts the user for card number
        printf("Number: ");

        // scans user input
        scanf("%ld", &number);

        // clears buffer if not a number
        while (getchar() != '\n') {};
    }

    // creates new card
    cc card = createCard(number);

    // exits the program
    return 0;
}

// creates a card representation (limited fields)
cc createCard(long int number) {
    // create a new instance of cc
    cc retCard;

    // sets number of the card
    retCard.number = number;

    validateCard(&retCard);

    // in- or validates card
    if (retCard.validity) {
        // prints success message
        printf("%s", retCard.finInstitution);
    } else {
        // prints error message
        printf("%s", retCard.finInstitution);
    }

    // returns the new card
    return retCard;
}

// in- or validates the given card
bool validateCard(cc *card) {
    // temporary variable to hold card number
    long int temp = (*card).number;

    // variables to store length, and first two digits
    int length = 0, firstTwoDigits = 0;

    // counts the number of digits
    while (temp > 0) {
        // increases digits counter
        length++;

        // checks if it is at the last (but first) two digits
        if (temp >= 10 && temp < 100) {
            // stores temp (first two  digits)
            firstTwoDigits = temp;
        }

        // removes last digit counted
        temp /= 10;
    }

    // returns card's validity
    return finInstitution(card, length, firstTwoDigits);
}

// assigns financial institution if valid and legal
bool finInstitution(cc *card, int length, int  firstTwoDigits) {
    if (checksum(card, length)) {
        if (length == 15) {
            // validates financial institution - AMEX
            if (firstTwoDigits == 34 || firstTwoDigits == 37)  {
                // validates card
                (*card).validity = true;

                // sets card's financial institution
                strcpy((*card).finInstitution, "AMEX\n");

                // returns true for valid
                return true;
            }
        } else if (length == 16 && firstTwoDigits / 10 != 4) {
            // validates financial institution - Mastercard
            if (firstTwoDigits > 50 && firstTwoDigits <= 55)  {
                // validates card
                (*card).validity = true;

                // sets card's financial institution
                strcpy((*card).finInstitution, "MASTERCARD\n");

                // returns true for valid
                return true;
            }
        } else if (length == 16 || length == 13) {
            // validates financial institution - VISA
            if (firstTwoDigits / 10 == 4)  {
                // validates card
                (*card).validity = true;

                // sets card's financial institution
                strcpy((*card).finInstitution, "VISA\n");

                // returns true for valid
                return true;
            }
        }
    }

    // if not valid, invalidates card
    (*card).validity = false;

    // invalidates financial institution
    strcpy((*card).finInstitution, "INVALID\n");

    // returns false
    return false;
}

// checks if card's checksum is valid
bool checksum(cc *card, int length) {
    // temporary variable to hold card number
    long int temp = (*card).number;

    // variable for first and second sum
    int sumOne = 0, sumTwo = 0, helper;

    // checks if length is even or odd
    int evenOrOdd = length % 2;

    // iterate through the digits
    for (int i = length; i >= 1; i--) {
        // adds the numbers for the second sum
        if (i % 2 == evenOrOdd) {
            // sums to second sum
            sumTwo += temp % 10;

            // removes the last digit
            temp /= 10;
        }  else {
            // helper to sum the digits
            helper = 2 * (temp % 10);

            // sums to first sum
            sumOne += helper % 10 + helper / 10;

            // removes the last digit
            temp /= 10;
        }
    }

    // checks if checksum ends in zero
    if ((sumOne + sumTwo) % 10 == 0)
        return true;

    // return false if checksum is invalid
    return false;
}
