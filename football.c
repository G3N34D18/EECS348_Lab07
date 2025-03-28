#include "football.h"

int count_combinations(int points) {
    int count;
    for (int convTD = 0; convTD <= points / 8; convTD++) {
        for(int fgTD = 0; fgTD <= points / 7; fgTD++) {
            for(int td = 0; td <= points / 6; td++) {
                for(int fg = 0; fg <= points / 3; fg++) {
                    int safety = points - (8 * convTD) - (7 * fgTD) - (6 * td) - (3 * fg);
                    if (safety >= 0 && safety % 2 == 0) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

void print_combinations(int points) {
    for (int convTD = 0; convTD <= points / 8; convTD++) {
        for(int fgTD = 0; fgTD <= points / 7; fgTD++) {
            for(int td = 0; td <= points / 6; td++) {
                for(int fg = 0; fg <= points / 3; fg++) {
                    int safety = points - (8 * convTD) - (7 * fgTD) - (6 * td) - (3 * fg);
                    if (safety >= 0 && safety % 2 == 0) {
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n", convTD, fgTD, td, fg, safety / 2);
                    }
                }
            }
        }
    }
}