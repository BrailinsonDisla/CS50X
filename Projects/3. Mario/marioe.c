/******************************************************************************
 *  Name: Brailinson Disla
 *
 *  Compilation:  make mario
 *  Execution:    ./mario
 *
 *  Draws pyramid of given height, modeled after those that appear in Nintendo’s
 *  Super Mario Brothers' videogame. Hashes (#) represent bricks in the pyramid.
 *
 *  APPROACH 2 OF 2:
 *    Uses euclidean transformation to iterate through the x-coordinates of each
 *  row (r), and uses the following to choose between #'s and one or two spaces:
 *    - brick [hash]              --> when abs(x) <= r
 *    - gap [double space]        --> at x == 0
 *    - space [single space]      --> otherwise [breaks if x > r ]
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

        // scan input height
        scanf("%d", &height);

        // clear buffer if not a number
        while (getchar() != '\n') {};
    }

    // prints the pyramid
    for (int i = 1; i <= height; i++)  {
        // x-coordiate for the current row
        for (int x = -1 * height; x <= height; x++) {
            // prints #'s abs(x)  <= current row
            if ((x > 0 && x <= i) || (x < 0 && -1 * x <= i)) {
                printf("#");
            } else if (i == 0) {
                // print two spaces of separation
                printf("  ");
            } else {
                // break if last # has been drawn
                if (x > i)
                  break;

                // print spaces otherwise
                printf(" ");
            }
        }

        // print new line
        printf("\n");
    }
}
