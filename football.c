#include <stdio.h>
#include "football.h"
// function that takes in integer points and returns an integer
int count_combinations(int points) {
    // initializes integer count to 0
    int count = 0;
    // for loop for all touchdowns with conversions that can fit in points
    for (int convTD = 0; convTD <= points / 8; convTD++) {
        // for loop for all touchdowns with fieldgoals that can fit in points
        for(int fgTD = 0; fgTD <= points / 7; fgTD++) {
            // for loop for all touch downs that fit in points
            for(int td = 0; td <= points / 6; td++) {
                // for loop for all field goals that fit in points
                for(int fg = 0; fg <= points / 3; fg++) {
                    // initializes integer safety as remainder of points after all other scoring subtracted
                    int safety = points - (8 * convTD) - (7 * fgTD) - (6 * td) - (3 * fg);
                    // safety has to be greater than 0, and must be 2
                    if (safety >= 0 && safety % 2 == 0) {
                        // increments count up by 1
                        count++;
                    }
                }
            }
        }
    }
    // returns count of combinations to user
    return count;
}

// printing combination function that takes in points
void print_combinations(int points) {
    // for loop that iterates through all conversion + TD can fit in points
    for (int convTD = 0; convTD <= points / 8; convTD++) {
        // iterates through all field goal + TD that fit in points
        for(int fgTD = 0; fgTD <= points / 7; fgTD++) {
            // iterates through all TD that fits in points 
            for(int td = 0; td <= points / 6; td++) {
                // iterates through all FG that can fit in points
                for(int fg = 0; fg <= points / 3; fg++) {
                    // initializes safety to be remainded after all other scoring subtracted
                    int safety = points - (8 * convTD) - (7 * fgTD) - (6 * td) - (3 * fg);
                    // safety has to be greater that 0, but also have no remainder when divided by two
                    if (safety >= 0 && safety % 2 == 0) {
                        // prints count of scoring in proper format
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", convTD, fgTD, td, fg, safety / 2);
                    }
                }
            }
        }
    }
}