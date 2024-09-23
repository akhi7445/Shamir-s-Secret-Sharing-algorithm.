#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

unsigned long long int convertBase(const char *value, int base) {
    return strtoull(value, NULL, base);
}

unsigned long long int lagrangeInterpolation(int x[], unsigned long long int y[], int k) {
    unsigned long long int c = 0;
    for (int i = 0; i < k; i++) {
        unsigned long long int term = y[i];
        for (int j = 0; j < k; j++) {
            if (i != j) {
                term = term * (-x[j]) / (x[i] - x[j]);
            }
        }
        c += term;
    }
    return c;
}

int main() {
    const int n = 9;
    const int k = 6;
    int xValues[] = {1, 2, 3, 4, 5, 6};  
    unsigned long long int yValues[k];   

    const char *yInputs[] = {
        "28735619723837",  // base 10
        "1A228867F0CA",    // base 16
        "32811A4AA0B7B",   // base 12
        "917978721331A",   // base 11
        "1A22886782E1",    // base 16
        "28735619654702"   // base 10
    };
    const int bases[] = {10, 16, 12, 11, 16, 10};

    for (int i = 0; i < k; i++) {
        yValues[i] = convertBase(yInputs[i], bases[i]);
    }

    unsigned long long int c = lagrangeInterpolation(xValues, yValues, k);
    printf("The constant term c is: %llu\n", c);

    return 0;
}
