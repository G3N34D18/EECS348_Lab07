#include <stdio.h>
#include "football.h"

int main(int argc, char *argv[]) {
    // prints exit path for program
    printf("Enter 0 or 1 to STOP\n");
    // loop that will run indefinitely 
    while (1) {
        // prints prompt for score of game
        printf("Enter the NFL score: ");
        // initializes integer for points
        int points;
        // scans input from user and sends it to address of points
        scanf("%d", &points);
        // if points is one of exit digits
        if (points <= 1) {
            // break loop and exit program
            break;
        }
        // if not an exit or digit
        else {
            // prints total number of combinations possible
            printf("Total combinations possible for %d points is %d.\n", points, count_combinations(points));
            // prints title of "Possible Combinations: "
            printf("Possible Combinations: \n");
            // prints all possible combinations
            print_combinations(points);
        }
    }
}