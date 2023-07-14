#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int multiply(char *num1, char *num2) {
    int len1 = 0, len2 = 0, i, j, k;
    int *result, carry, n1, n2, sum;

    /* Calculate the lengths of the numbers */
    while (num1[len1] != '\0')
        len1++;
    while (num2[len2] != '\0')
        len2++;

    /* Create an array to store the result */
    result = malloc(sizeof(int) * (len1 + len2));
    if (result == NULL) {
        printf("Error: Failed to allocate memory.\n");
        exit(98);
    }

    /* Initialize the result array with 0s */
    for (i = 0; i < len1 + len2; i++)
        result[i] = 0;

    /* Multiply the digits and store the result in the result array */
    for (i = len1 - 1; i >= 0; i--) {
        n1 = num1[i] - '0';
        carry = 0;

        for (j = len2 - 1; j >= 0; j--) {
            n2 = num2[j] - '0';
            sum = n1 * n2 + result[i + j + 1] + carry;
            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }

        if (carry > 0)
            result[i + j + 1] += carry;
    }

    /* Skip leading zeros in the result */
    i = 0;
    while (i < len1 + len2 - 1 && result[i] == 0)
        i++;

    /* Print the result */
    for (k = i; k < len1 + len2; k++)
        printf("%d", result[k]);
    printf("\n");

    /* Free the dynamically allocated memory */
    free(result);

    return 0;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc != 3) {
        printf("Error: Incorrect number of arguments.\n");
        return 98;
    }

    /* Check if the arguments are composed of digits */
    for (i = 1; i < argc; i++) {
        char *num = argv[i];
        int j = 0;
        while (num[j] != '\0') {
            if (!isdigit(num[j])) {
                printf("Error: Arguments should only contain digits.\n");
                return 98;
            }
            j++;
        }
    }

    multiply(argv[1], argv[2]);

    return 0;
}

    
