#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

// prototypes for user-defined functions
int numOfLetters(int length, char* text);
int numOfWords(int length, char* text);
int numOfSentences(int length, char* text);
float CLindex(float l, float w, float s);

// max text character length
const int MAX_CHARS = 5000;

// index of first alpha character
int alpha = -1;

int main(void) {
    // asks the user for text
    printf("Enter text:\n");

    // scans and stores the text as a char[]
    char text[MAX_CHARS];
    scanf("%[^\n]%*c", text);

    // calculate the length of the text
    int length = strlen(text);

    // find the index of the first alpha
    for (int i = 0; i < length; i++) {
        if (isalpha(text[i])) {
            alpha = i;

            // break once found
            break;
        }
    }

    // calculate number of letters, word, sentences
    float l = (float) numOfLetters(length, text);
    float w = (float) numOfWords(length, text);
    float s = (float) numOfSentences(length, text);

    // calculate index
    int i = round (CLindex(l, w, s));

    // Prints grade level required to read text
    if (i < 1)
        printf("Before Grade %d\n", 1);
    else if (i < 16)
        printf("Grade %d\n", i);
    else
        printf("Grade %d+\n", 16);
}

// counts the number of letters (characters)
int numOfLetters(int length, char* text) {
    // counter for letters
    int numLetters = 0;

    // count the characters
    for (int i = alpha; i < length; i++) {
        // check if the currect character is between a-z or A-Z
        if (isalpha(text[i]))
            numLetters++;
    }

    // return number of letters
    return numLetters;
}

/*  counts the number of words (separated by spaces or period)

    1. discards non-alpha characters in the following scenarios:
        a. at the start or end of the text
        b. that are consecutive
*/
int numOfWords(int length, char* text) {
    // counter for words
    int numWords = 0;

    // return word count (= 0) if there are no alpha
    if (alpha == -1)
        return 0;

    // else - count the words
    for (int i = alpha; i <= length; i++) {
        // skip the currect character if it is between a-z or A-Z
        if (isalpha(text[i]) || text[i] == '\'' || text[i] == '-')
            continue;
        else {
            numWords++;

            // discard
            while (!isalpha(text[i]) && i < length)
                i++;
        }
    }

    // return the number of words
    return numWords;
}

/*  counts the number of sentences
    1. discards non-alpha characters in the following scenarios:
        a. at the start or end of the text
        b. that are consecutive
*/
int numOfSentences(int length, char* text) {
    // counter for sentences
    int numSentences = 0;

    // return setence count (= 0) if there are no alpha
    if (alpha == -1)
        return 0;

    // else - count the sentences
    for (int i = alpha; i <= length; i++) {
        // skip the currect character if it is not '.', '!' or '?'
        if (text[i] != '.' && text[i] != '!' && text[i] != '?' && text[i] != '\0')
            continue;
        else {
            numSentences++;

            // discard
            while (!isalpha(text[i]) && i < length)
                i++;
        }
    }

    // return the number of sentences
    return numSentences;
}

// calculates the Coleman-Liau index
float CLindex(float l, float w, float s) {
    // calculate average letters and sentences per 100 words
    float lpw = 100.0 * (float) l / w,
          spw = 100.0 * (float) s / w;

    // calculate and return index
    float ia = 5.88e-2 * lpw;
    float ib = -2.96e-1 * spw;

    return ia + ib - 15.8;
}
