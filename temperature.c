#include <stdio.h>
#include "temperature.h"

float celsius_to_fahrenheit(float celsius) {
    float fahrenheit = (9.0/5.0)*celsius+32;
    return fahrenheit;
}

float fahrenheit_to_celsius(float fahrenheit) {
    float celsius = (5.0/9.0)*(fahrenheit-32);
    return celsius;
}

float celsius_to_kelvin(float celsius) {
    float kelvin = celsius+273.15;
    return kelvin;
}

float kelvin_to_celsius(float kelvin) {
    float celsius = kelvin-273.15;
    return celsius;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    float celsius = fahrenheit_to_celsius(fahrenheit);
    float kelvin = celsius_to_kelvin(celsius);
    return kelvin;
}

float kelvin_to_fahrenheit(float kelvin) {
    float celsius = kelvin_to_celsius(kelvin);
    float fahrenheit = celsius_to_fahrenheit(celsius);
    return fahrenheit;
}

void categorize_function(float celsius) {
    if (celsius < 0.0) {
        printf("Freezing Weather: Wear Heavy Outerwear.\n");
    }
    else if (celsius <= 10.0) {
        printf("Cold Weather: Wear a coat.\n");
    }
    else if (celsius <= 25.0) {
        printf("Comfortable Weather: Enjoy the day outside.\n");
    }
    else if (celsius <= 35.0) {
        printf("Hot Weather: Wear light clothing.\n");
    }
    else if (celsius > 35.0) {
        printf("Extreme Heat: Stay indoors.\n");
    }
}