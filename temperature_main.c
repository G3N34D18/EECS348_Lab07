#include <stdio.h>
#include <string.h>
#include "temperature.h"

int main(int argc, char *argv[]) {
    // while loop that loops indefinitely
    while (1) {
        // prints prompt to enter temperature value
        printf("Enter temperature value: ");
        // initializes float as temp
        float temp;
        // takes input from user and checks if input is not a float
        if (scanf("%f", &temp) != 1) {
            // prints invalid input if not a float
            printf("Invalid input. Please input in format of a float.\n");
            // clears the input section
            while (getchar() != '\n');
            // reruns the abover code until valid input is given
            continue;
        }
        // initializes string start with max digits of 25
        char start[25];
        // prints prompt for temperature scale
        printf("Enter temperature scale (Fahrenheit, Celsius, or Kelvin): ");
        // scans in input from user to start address
        scanf("%s", start);
        // checks input to ensure it is in proper formating for conversion
        if (strcmp(start, "Fahrenheit") != 0 && strcmp(start, "Celsius") != 0 && strcmp(start, "Kelvin")) {
            // prints error message if one of the provided formats of scale is not used
            printf("Error: Please re-enter scale in format (Fahrenheit, Celsius, or Kelvin)\n");
            // reruns section of code until proper input
            continue;
        }
        // checks if scale is in kelvin and if it is a negative temp
        if (strcmp(start, "Kelvin") == 0 && temp < 0) {
            // prints error message because Kelvin cannot be negative
            printf("Error: Kelvin cannot be negative.\n");
            // reruns section of code until proper input
            continue;
        }
        // initializes empty target string  
        char target[25];
        // prints prompt for target scale
        printf("Enter target conversion scale: ");
        // scans in scale form user to target address
        scanf("%s", target);
        // if target is start scale
        if (strcmp(start, target) == 0) {
            // prints error message because cannot convert to self
            printf("Error: Cannot convert to same scale.");
            // reruns until proper input
            continue;
        }
        /*
            This if-else block checks the start and target input to determine which 
            conversion function to use to produce correct results. Additionally this 
            block find the celsius value and puts it through the categorize function. 
            The categorize function issues the advisory.
        */
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
