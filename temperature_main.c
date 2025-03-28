#include <stdio.h>
#include <string.h>
#include "temperature.h"

int main(int argc, char *argv[]) {
    while (1) {
        printf("Enter temperature value: ");
        float temp;
        if (scanf("%f", &temp) != 1) {
            printf("Invalid input. Please input in format of a float.\n");
            while (getchar() != '\n');
            continue;
        }
        char start[25];
        printf("Enter temperature scale (Fahrenheit, Celsius, or Kelvin): ");
        scanf("%s", start);

        if (strcmp(start, "Fahrenheit") != 0 && strcmp(start, "Celsius") != 0 && strcmp(start, "Kelvin")) {
            printf("Error: Please re-enter scale in format (Fahrenheit, Celsius, or Kelvin)\n");
            continue;
        }
        if (strcmp(start, "Kelvin") == 0 && temp < 0) {
            printf("Error: Kelvin cannot be negative.\n");
            continue;
        }
        char target[25];
        printf("Enter target conversion scale: ");
        scanf("%s", target);
        if (strcmp(start, target) == 0) {
            printf("Error: Cannot convert to same scale.");
            continue;
        }

        if (strcmp(start, "Celsius") == 0 && strcmp(target, "Fahrenheit") == 0) {
            float new_temp = celsius_to_fahrenheit(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            categorize_function(temp);
        } else if (strcmp(start, "Celsius") == 0 && strcmp(target, "Kelvin") == 0) {
            float new_temp = celsius_to_kelvin(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            categorize_function(temp);
        } else if (strcmp(start, "Fahrenheit") == 0 && strcmp(target, "Celsius") == 0) {
            float new_temp = fahrenheit_to_celsius(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            categorize_function(new_temp);
        } else if (strcmp(start, "Fahrenheit") == 0 && strcmp(target, "Kelvin") == 0) {
            float new_temp = fahrenheit_to_kelvin(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            float convTemp = fahrenheit_to_celsius(temp);
            categorize_function(convTemp);
        } else if (strcmp(start, "Kelvin") == 0 && strcmp(target, "Celsius") == 0) {
            float new_temp = kelvin_to_celsius(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            categorize_function(new_temp);
        } else if (strcmp(start, "Kelvin") == 0 && strcmp(target, "Fahrenheit") == 0) {
            float new_temp = kelvin_to_fahrenheit(temp);
            printf("Converted temperature: %.2f %s\n", new_temp, target);
            float convTemp = kelvin_to_celsius(temp);
            categorize_function(convTemp);
        }
    }
    return 0;
}
