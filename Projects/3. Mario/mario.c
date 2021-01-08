/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make mario
 *  Execution:    ./mario
 *
 *  Draws pyramid of given height, modeled after those that appear in Nintendo’s
 *  Super Mario Brothers' videogame. Hashes (#) represent bricks in the pyramid.
 *
 *  APPROACH 1 OF 2:
 *    Uses relational positioning of the current row (r) to determine the number
 *  of spaces (s) to the right of the #'s in relation to the pyramid's height.
 *    - the number of spaces           -->   (h - r)
 *    - the number of #s is (right)    -->   r
 *    - the number of #s is (left)     -->   r
 *
 *  % ./mario
 ******************************************************************************/
#include <stdio.h>

int main() {
    // bounds on tower height
    const int MIN_HEIGHT = 1, MAX_HEIGHT = 8;

    // stores user height input
    int height = 0;

    while (height < MIN_HEIGHT || height > MAX_HEIGHT) {
        // ask user for height
        printf("Height: ");

        // scan input Heigh
        scanf("%d", &height);

        // clear buffer if not a number
        while (getchar() != '\n') {};
    }

    // prints the pyramid
    for (int r = 1, h = height - 1; r <= height && h >= 0; r++, h--) {
        // prints spaces for the right pyramid
        for (int s = 1; s <= h; s++) {
            printf(" ");
        }

        // prints the right pyramid elements
        for (int c = 1; c <= r; c++) {
            printf("#");
        }

        // print gap
        printf("  ");

        // UNCOMMENT FOLLOWING FOR LOOP FOR ADJECENT PYRAMID

        // prints the left pyramid elements
        for (int c = 1; c <= r; c++) {
            printf("#");
        }

        // print new line
        printf("\n");
    }
}
