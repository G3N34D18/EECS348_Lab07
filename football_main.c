#include <stdio.h>
#include "football.h"

int main(int argc, char *argv[]) {
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        printf("Enter the NFL score: ");
        int points;
        scanf("%d", &points);
        if (points <= 1) {
            break;
        }
        else {
            printf("Total combinations possible for %d points is %d.\n", points, count_combinations(points));
            printf("Possible Combinations: \n");
            print_combinations(points);
        }
    }
}